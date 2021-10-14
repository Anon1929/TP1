#ifndef UNIDADEPERSISTENCIA_H_INCLUDED
#define UNIDADEPERSISTENCIA_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>
#include <vector>

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

//autenticar
class ComandoLerSenha: public ComandoSQL{
public:
        ComandoLerSenha(Matricula);
        Senha getResultado();
};
//participante
class ComandoCadastrarParticipante:public ComandoSQL {
public:
        ComandoCadastrarParticipante(const Participante&);
};

class ComandoEditarParticipante:public ComandoSQL {
public:
        ComandoEditarParticipante(const Participante&);
};

class ComandoExcluirParticipante:public ComandoSQL {
public:
        ComandoExcluirParticipante(const Participante&);
};

class ComandoPesquisarParticipante:public ComandoSQL{
public:
        ComandoPesquisarParticipante(const Matricula&);
        Participante getResultado();
};

class ComandoCadastrarParticipanteEmPeca:public ComandoSQL{
    public:
        ComandoCadastrarParticipanteEmPeca(const Matricula&, const Codigo&);
};


//peca
class ComandoVisualizarPecas:public ComandoSQL {
public:
        ComandoVisualizarPecas();
        vector<Peca> getValor();
};

class ComandoCadastrarPeca:public ComandoSQL {
public:
        ComandoCadastrarPeca(const Peca&);
};

class ComandoEditarPeca:public ComandoSQL {
public:
        ComandoEditarPeca(const Peca&);
};

class ComandoExcluirPeca:public ComandoSQL {
public:
        ComandoExcluirPeca(const Peca&);
};

class ComandoPesquisarPeca:public ComandoSQL{
public:
        ComandoPesquisarPeca(const Codigo&);
        Peca getResultado();
};


//sessao

//sala

#endif // UNIDADEPERSISTENCIA_H_INCLUDED
