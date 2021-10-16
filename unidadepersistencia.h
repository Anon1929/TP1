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
        ComandoExcluirParticipante(const Matricula&);
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


//Peca
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
        ComandoExcluirPeca(const Codigo&);
};

class ComandoPesquisarPeca:public ComandoSQL{
public:
        ComandoPesquisarPeca(const Codigo&);
        Peca getResultado();
};


//Sessao
class ComandoVisualizarSessoes:public ComandoSQL {
public:
        ComandoVisualizarSessoes();
        vector<Sessao> getValor();
};

class ComandoCadastrarSessao:public ComandoSQL {
public:
        ComandoCadastrarSessao(const Sessao&);
};

class ComandoEditarSessao:public ComandoSQL {
public:
        ComandoEditarSessao(const Sessao&);
};

class ComandoExcluirSessao:public ComandoSQL {
public:
        ComandoExcluirSessao(const Codigo&);
};

class ComandoPesquisarSessao:public ComandoSQL{
public:
        ComandoPesquisarSessao(const Codigo&);
        Sessao getResultado();
};

//Sala
class ComandoVisualizarSalas:public ComandoSQL {
public:
        ComandoVisualizarSalas();
        vector<Sala> getValor();
};

class ComandoCadastrarSala:public ComandoSQL {
public:
        ComandoCadastrarSala(const Sala&);
};

class ComandoEditarSala:public ComandoSQL {
public:
        ComandoEditarSala(const Sala&);
};

class ComandoExcluirSala:public ComandoSQL {
public:
        ComandoExcluirSala(const Codigo&);
};

class ComandoPesquisarSala:public ComandoSQL{
public:
        ComandoPesquisarSala(const Codigo&);
        Sala getResultado();
};

#endif // UNIDADEPERSISTENCIA_H_INCLUDED
