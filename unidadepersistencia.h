#ifndef UNIDADEPERSISTENCIA_H_INCLUDED
#define UNIDADEPERSISTENCIA_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

#include <iostream>
#include <string>
#include <stdio.h>

#include "sqlite3.h"           // Incluir cabeçalho da biblioteca SQLite.

using namespace std;


class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};
inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        int conectar();
        int desconectar();
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
             nomeBancoDados = "cinema.db";                             // Nome do banco de dados.
        }
        int executar();
};


class ComandoCadastrar:public ComandoSQL {
public:
        ComandoCadastrar(const Participante&);
};

class ComandoLerSenha: public ComandoSQL{
public:
        ComandoLerSenha(Matricula);
        Senha getResultado();
};

class ComandoPesquisarParticipante:public ComandoSQL{
public:
        ComandoPesquisarParticipante(Matricula);
        Participante getResultado();
};


#endif // UNIDADEPERSISTENCIA_H_INCLUDED
