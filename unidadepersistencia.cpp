#include "unidadepersistencia.h"

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
        comandoSQL += "'" + participante.getCargo().getValor() + "'); ";
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
        return participante;
}

