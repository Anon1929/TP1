#include "unidadepersistencia.h"
#include <string.h>

using namespace std;

list<ElementoResultado> ComandoSQL::listaResultado;


EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}

string EErroPersistencia::what() {
        return mensagem;
}

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}

int ComandoSQL::conectar() {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        return 1;
    return 0;
}

int ComandoSQL::desconectar() {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        return 1;
    return 0;
}

int ComandoSQL::executar() {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                sqlite3_free(mensagem);
                desconectar();
                return 1;
        }
        desconectar();
        return 0;
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

ComandoCadastrarParticipante::ComandoCadastrarParticipante(const Participante& participante){
        comandoSQL = "INSERT INTO participantes VALUES (";
        comandoSQL += "'" + participante.getMatricula().getValor() + "', ";
        comandoSQL += "'" + participante.getNome().getValor() + "', ";
        comandoSQL += "'" + participante.getSobrenome().getValor() + "', ";
        comandoSQL += "'" + participante.getEmail().getValor() + "', ";
        comandoSQL += "'" + participante.getTelefone().getValor() + "', ";
        comandoSQL += "'" + participante.getSenha().getValor() + "', ";
        comandoSQL += "'" + participante.getCargo().getValor() + "', ";
        comandoSQL += "'0');";
}

ComandoLerSenha::ComandoLerSenha(Matricula matricula) {
        comandoSQL = "SELECT senha FROM participantes WHERE matricula = ";
        comandoSQL += matricula.getValor();
}

Senha ComandoLerSenha::getResultado() {
        ElementoResultado resultado;
        Senha senha;

        //Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha.setValor(resultado.getValorColuna());

        return senha;
}

ComandoPesquisarParticipante::ComandoPesquisarParticipante(const Matricula& matricula){
        comandoSQL = "SELECT * FROM participantes WHERE matricula = ";
        comandoSQL += matricula.getValor();
}
Participante ComandoPesquisarParticipante::getResultado(){
        ElementoResultado resultado;
        Participante participante;

        // matricula;
        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        participante.setMatricula(Matricula(resultado.getValorColuna()));

        if (listaResultado.empty())
                throw "Lista de resultados vazia.";
        resultado = listaResultado.back();
        listaResultado.pop_back();
        participante.setNome(Nome(resultado.getValorColuna()));

        if (listaResultado.empty())
                throw "Lista de resultados vazia.";
        resultado = listaResultado.back();
        listaResultado.pop_back();
        participante.setSobrenome(Nome(resultado.getValorColuna()));

        if (listaResultado.empty())
                throw "Lista de resultados vazia.";
        resultado = listaResultado.back();
        listaResultado.pop_back();
        participante.setEmail(Email(resultado.getValorColuna()));

        if (listaResultado.empty())
                throw "Lista de resultados vazia.";
        resultado = listaResultado.back();
        listaResultado.pop_back();
        participante.setTelefone(Telefone(resultado.getValorColuna()));

        if (listaResultado.empty())
                throw "Lista de resultados vazia.";
        resultado = listaResultado.back();
        listaResultado.pop_back();
        participante.setSenha(Senha(resultado.getValorColuna()));

        if (listaResultado.empty())
                throw "Lista de resultados vazia.";
        resultado = listaResultado.back();
        listaResultado.pop_back();
        participante.setCargo(Cargo(resultado.getValorColuna()));

        if (listaResultado.empty())
                throw "Lista de resultados vazia.";
        resultado = listaResultado.back();
        listaResultado.pop_back();
        if(resultado.getValorColuna().compare("0") != 0)
            participante.setIdPeca(Codigo(resultado.getValorColuna()));

        return participante;
}

ComandoEditarParticipante::ComandoEditarParticipante(const Participante& participante){
    comandoSQL = "UPDATE participantes SET ";
    if(participante.getNome().getValor()!= "")
        comandoSQL += "nome = '" + participante.getNome().getValor();
    if(participante.getSobrenome().getValor()!= "")
        comandoSQL += "' sobrenome = '" + participante.getSobrenome().getValor();
    if(participante.getEmail().getValor()!= "")
        comandoSQL += "' email = '" + participante.getEmail().getValor();
    if(participante.getTelefone().getValor()!= "")
        comandoSQL += "' telefone = '" + participante.getTelefone().getValor();
    if(participante.getSenha().getValor()!= "")
        comandoSQL += "' senha = '" + participante.getSenha().getValor();
    if(participante.getCargo().getValor()!= "")
        comandoSQL += "' cargo = '" + participante.getCargo().getValor();
    if(participante.getIdPeca().getValor()!= "")
        comandoSQL += "' peca_id = '" + participante.getIdPeca().getValor();
    comandoSQL += "' WHERE matricula = '"+ participante.getMatricula().getValor()+"';";
}


ComandoCadastrarParticipanteEmPeca::ComandoCadastrarParticipanteEmPeca(const Matricula& matricula, const Codigo& idPeca){
    comandoSQL = "UPDATE participantes SET ";
    comandoSQL += "peca_id = '" + idPeca.getValor();
    comandoSQL += "' WHERE matricula = '"+ matricula.getValor()+"';";
}

ComandoExcluirParticipante::ComandoExcluirParticipante(const Matricula& matricula){
    comandoSQL += "DELETE FROM participantes WHERE matricula = '" + matricula.getValor() + "';";
}

//Peca
ComandoCadastrarPeca::ComandoCadastrarPeca(const Peca& peca){
    comandoSQL = "INSERT INTO pecas VALUES (";
    comandoSQL += "'" + peca.getCodigo().getValor() + "', ";
    comandoSQL += "'" + peca.getNome().getValor() + "', ";
    comandoSQL += "'" + peca.getTipo().getValor() + "', ";
    comandoSQL += "'" + peca.getClassificacao().getValor() + "'); ";
}
ComandoEditarPeca::ComandoEditarPeca(const Peca&){
    comandoSQL = "SELEC * FROM participantes";
}
ComandoPesquisarPeca::ComandoPesquisarPeca(const Codigo& id){
    comandoSQL = "SELEC * FROM participantes";
}
Peca ComandoPesquisarPeca::getResultado(){
    Peca peca;
    return peca;
}
ComandoExcluirPeca::ComandoExcluirPeca(const Codigo& id){
    comandoSQL = "SELEC * FROM participantes";
}

//Sala
ComandoCadastrarSala::ComandoCadastrarSala(const Sala&){
    comandoSQL = "SELEC * FROM participantes";
}
ComandoEditarSala::ComandoEditarSala(const Sala&){
    comandoSQL = "SELEC * FROM participantes";
}
ComandoPesquisarSala::ComandoPesquisarSala(const Codigo& id){
    comandoSQL = "SELEC * FROM participantes";
}
Sala ComandoPesquisarSala::getResultado(){
    Sala sala;
    return sala;
}
ComandoExcluirSala::ComandoExcluirSala(const Codigo& id){
    comandoSQL = "SELEC * FROM participantes";
}

//Sessao
ComandoCadastrarSessao::ComandoCadastrarSessao(const Sessao&){
    comandoSQL = "SELEC * FROM participantes";
}
ComandoEditarSessao::ComandoEditarSessao(const Sessao&){
    comandoSQL = "SELEC * FROM participantes";
}
ComandoPesquisarSessao::ComandoPesquisarSessao(const Codigo& id){
    comandoSQL = "SELEC * FROM participantes";
}
Sessao ComandoPesquisarSessao::getResultado(){
    Sessao sessao;
    return sessao;
}
ComandoExcluirSessao::ComandoExcluirSessao(const Codigo& id){
    comandoSQL = "SELEC * FROM participantes";
}
