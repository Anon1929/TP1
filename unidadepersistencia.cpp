#include "unidadepersistencia.h"
#include <string>
#include <vector>
#include <iostream>

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
        comandoSQL = "SELECT senha FROM participantes WHERE matricula = '";
        comandoSQL += matricula.getValor()+"';";
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
        comandoSQL = "SELECT * FROM participantes WHERE matricula = '";
        comandoSQL += matricula.getValor()+"';";
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

ComandoEditarParticipante::ComandoEditarParticipante(const Participante& participante){ //BUG
    comandoSQL = "UPDATE participantes SET ";
    vector<string> edits;

    if(participante.getNome().getValor().compare("")!=0)
        edits.push_back("nome = '" + participante.getNome().getValor()+ "'");
    if(participante.getSobrenome().getValor().compare("")!=0)
        edits.push_back("sobrenome = '" + participante.getSobrenome().getValor()+ "'");
    if(participante.getEmail().getValor().compare("")!=0)
        edits.push_back("email = '" + participante.getEmail().getValor()+ "'");
    if(participante.getTelefone().getValor().compare("")!=0)
        edits.push_back("telefone = '" + participante.getTelefone().getValor()+ "'");
    if(participante.getSenha().getValor().compare("")!=0)
        edits.push_back("senha = '" + participante.getSenha().getValor()+ "'");
    if(participante.getCargo().getValor().compare("")!=0)
        edits.push_back("cargo = '" + participante.getCargo().getValor()+ "'");
    if(participante.getIdPeca().getValor().compare("")!=0)
        edits.push_back("peca_id = '" + participante.getIdPeca().getValor()+ "'");

    bool comma = false;
    for(auto l : edits){
        if(comma){
            comandoSQL += ", " + l;
        }else{
            comandoSQL += l.c_str();
            comma = true;
        }
    }

    comandoSQL += " WHERE matricula = '"+ participante.getMatricula().getValor()+"';";
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
ComandoVisualizarPecas::ComandoVisualizarPecas(){
    comandoSQL = "SELECT * FROM pecas;";
}
vector<Peca> ComandoVisualizarPecas::getValor(){
    ElementoResultado resultado;
    vector<Peca> pecas;

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }

    Peca peca;
    while(!listaResultado.empty()){

        resultado = listaResultado.back();
        listaResultado.pop_back();
        peca.setCodigo(Codigo(resultado.getValorColuna()));

        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        peca.setNome(Nome(resultado.getValorColuna()));

        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        peca.setTipo(Tipo(resultado.getValorColuna()));

        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        peca.setClassificacao(Classificacao(resultado.getValorColuna()));

        pecas.push_back(peca);
    }
    return pecas;
}

ComandoCadastrarPeca::ComandoCadastrarPeca(const Peca& peca){
    comandoSQL = "INSERT INTO pecas VALUES (";
    comandoSQL += "'" + peca.getCodigo().getValor() + "', ";
    comandoSQL += "'" + peca.getNome().getValor() + "', ";
    comandoSQL += "'" + peca.getTipo().getValor() + "', ";
    comandoSQL += "'" + peca.getClassificacao().getValor() + "'); ";
}
ComandoEditarPeca::ComandoEditarPeca(const Peca& peca){
    comandoSQL = "UPDATE pecas SET ";
    vector<string> edits;
    if(peca.getNome().getValor().compare("")!=0)
        edits.push_back("nome = '" + peca.getNome().getValor()+ "'");
    if(peca.getTipo().getValor().compare("")!=0)
        edits.push_back("tipo = '" + peca.getTipo().getValor()+ "'");
    if(peca.getClassificacao().getValor().compare("")!=0)
        edits.push_back("classificacao = '" + peca.getClassificacao().getValor()+ "'");

    bool comma = false;
    for(auto l : edits){
        if(comma){
            comandoSQL += ", " + l;
        }else{
            comandoSQL += l.c_str();
            comma = true;
        }
    }

    comandoSQL += " WHERE identificador = '" + peca.getCodigo().getValor()+"';";
}
ComandoPesquisarPeca::ComandoPesquisarPeca(const Codigo& id){
    comandoSQL = "SELECT * FROM pecas WHERE identificador = '" + id.getValor()+"';";
}
Peca ComandoPesquisarPeca::getResultado(){
    ElementoResultado resultado;
    Peca peca;

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    peca.setCodigo(Codigo(resultado.getValorColuna()));

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    peca.setNome(Nome(resultado.getValorColuna()));

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    peca.setTipo(Tipo(resultado.getValorColuna()));

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    peca.setClassificacao(Classificacao(resultado.getValorColuna()));

    return peca;
}
ComandoExcluirPeca::ComandoExcluirPeca(const Codigo& id){
    comandoSQL = "DELETE FROM pecas WHERE identificador = '" + id.getValor()+"';";
}

//Sala
ComandoVisualizarSalas::ComandoVisualizarSalas(){
    comandoSQL = "SELECT * FROM salas;";
}
vector<Sala> ComandoVisualizarSalas::getValor(){
    ElementoResultado resultado;
    vector<Sala> salas;

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }

    Sala sala;
    while(!listaResultado.empty()){

        resultado = listaResultado.back();
        listaResultado.pop_back();
        sala.setCodigo(Codigo(resultado.getValorColuna()));

        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        sala.setNome(Nome(resultado.getValorColuna()));

        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        sala.setCapacidade(Capacidade(resultado.getValorColuna()));

        salas.push_back(sala);
    }
    return salas;
}

ComandoCadastrarSala::ComandoCadastrarSala(const Sala& sala){
    comandoSQL = "INSERT INTO salas VALUES (";
    comandoSQL += "'" + sala.getCodigo().getValor() + "', ";
    comandoSQL += "'" + sala.getNome().getValor() + "', ";
    comandoSQL += "'" + sala.getCapacidade().getValor() + "'); ";
}
ComandoEditarSala::ComandoEditarSala(const Sala& sala){
    comandoSQL = "UPDATE salas SET ";
    vector<string> edits;
    if(sala.getNome().getValor().compare("")!=0)
        edits.push_back("nome = '" + sala.getNome().getValor()+ "'");
    if(sala.getCapacidade().getValor().compare("")!=0)
        edits.push_back("capacidade = '" + sala.getCapacidade().getValor()+ "'");

    bool comma = false;
    for(auto l : edits){
        if(comma){
            comandoSQL += ", " + l;
        }else{
            comandoSQL += l.c_str();
            comma = true;
        }
    }

    comandoSQL += " WHERE identificador = '" + sala.getCodigo().getValor()+"';";
}
ComandoPesquisarSala::ComandoPesquisarSala(const Codigo& id){
    comandoSQL = "SELECT * FROM salas WHERE identificador = '" + id.getValor()+"';";
}
Sala ComandoPesquisarSala::getResultado(){
    Sala sala;
    ElementoResultado resultado;

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sala.setCodigo(Codigo(resultado.getValorColuna()));

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sala.setNome(Nome(resultado.getValorColuna()));

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
        sala.setCapacidade(Capacidade(resultado.getValorColuna()));

    return sala;
}
ComandoExcluirSala::ComandoExcluirSala(const Codigo& id){
    comandoSQL = "DELETE FROM salas WHERE identificador = '" + id.getValor()+"';";
}

//Sessao
ComandoVisualizarSessoes::ComandoVisualizarSessoes(){
    comandoSQL = "SELECT * FROM sessoes;";
}
vector<Sessao> ComandoVisualizarSessoes::getValor(){
    ElementoResultado resultado;
    vector<Sessao> sessoes;

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }

    Sessao sessao;
    while(!listaResultado.empty()){

        resultado = listaResultado.back();
        listaResultado.pop_back();
        sessao.setCodigo(Codigo(resultado.getValorColuna()));

        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        sessao.setData(Data(resultado.getValorColuna()));

        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        sessao.setHorario(Horario(resultado.getValorColuna()));

        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        sessao.setIdSala(Codigo(resultado.getValorColuna()));

        if (listaResultado.empty()){
            throw "Lista de resultados vazia.";
        }
        resultado = listaResultado.back();
        listaResultado.pop_back();
        sessao.setIdPeca(Codigo(resultado.getValorColuna()));

        sessoes.push_back(sessao);
    }
    return sessoes;
}

ComandoCadastrarSessao::ComandoCadastrarSessao(const Sessao& sessao){ //Parei aqui!!!!!!
    comandoSQL = "INSERT INTO sessoes VALUES (";
    comandoSQL += "'" + sessao.getCodigo().getValor() + "', ";
    comandoSQL += "'" + sessao.getData().getValor() + "', ";
    comandoSQL += "'" + sessao.getHorario().getValor() + "', ";
    comandoSQL += "'" + sessao.getIdSala().getValor() + "', ";
    comandoSQL += "'" + sessao.getIdPeca().getValor() + "'); ";
}
ComandoEditarSessao::ComandoEditarSessao(const Sessao& sessao){
    comandoSQL = "UPDATE sessoes SET ";
    vector<string> edits;
    if(sessao.getData().getValor().compare("")!=0)
        edits.push_back("data = '" + sessao.getData().getValor()+ "'");
    if(sessao.getHorario().getValor().compare("")!=0)
        edits.push_back("horario = '" + sessao.getHorario().getValor()+ "'");
    if(sessao.getIdSala().getValor().compare("")!=0)
        edits.push_back("idSala = '" + sessao.getIdSala().getValor()+ "'");
    if(sessao.getIdPeca().getValor().compare("")!=0)
        edits.push_back("idPeca = '" + sessao.getIdPeca().getValor()+ "'");

    bool comma = false;
    for(auto l : edits){
        if(comma){
            comandoSQL += ", " + l;
        }else{
            comandoSQL += l.c_str();
            comma = true;
        }
    }

    comandoSQL += " WHERE identificador = '" + sessao.getCodigo().getValor()+"';";
}
ComandoPesquisarSessao::ComandoPesquisarSessao(const Codigo& id){
    comandoSQL = "SELECT * FROM sessoes WHERE identificador = '" + id.getValor()+"';";
}
Sessao ComandoPesquisarSessao::getResultado(){
    Sessao sessao;
    ElementoResultado resultado;

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sessao.setCodigo(Codigo(resultado.getValorColuna()));

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sessao.setData(Data(resultado.getValorColuna()));

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sessao.setHorario(Horario(resultado.getValorColuna()));

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sessao.setIdSala(Codigo(resultado.getValorColuna()));

    if (listaResultado.empty()){
        throw "Lista de resultados vazia.";
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();
    sessao.setIdPeca(Codigo(resultado.getValorColuna()));

    return sessao;
}
ComandoExcluirSessao::ComandoExcluirSessao(const Codigo& id){
    comandoSQL = "DELETE FROM sessoes WHERE identificador = '"+ id.getValor()+"';";
}
