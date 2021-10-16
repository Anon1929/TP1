
#ifndef CONTROLADORESSERVICO_H_INCLUDED
#define CONTROLADORESSERVICO_H_INCLUDED

#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

// Declara��es de classes controladoras e implementa��es de m�todos.
//--------------------------------------------------------------------------------------------
class CntrServicoAutenticacao:public IServicoAutenticacao{
    private:
    public:
        int autenticar(const Matricula&, const Senha&);
};

//--------------------------------------------------------------------------------------------
class CntrServicoParticipante:public IServicoParticipante{
    private:
    public:
        int cadastrarUsuario(const Participante&);
        int editarUsuario(const Participante&);
        int excluirUsuario(const Matricula&);
        int visualizarUsuario(const Matricula&, Participante*);
        int cadastrarComoParticipante(const Matricula&, const Codigo&);
};

//--------------------------------------------------------------------------------------------
class CntrServicoPSS:public IServicoPSS{
    private:
    public:
        vector<Peca> listarPecas();
        vector<Sessao> listarSessoes();
        vector<Sala> listarSalas();
        //Pe�as
        int incluirPeca (const Peca&);
        int editarPeca (const Peca&);
        int excluirPeca (const Codigo&);
        int visualizarPeca (const Codigo&, Peca*);
        //Sess�es
        int incluirSessao (const Sessao&);
        int editarSessao (const Sessao&);
        int excluirSessao (const Codigo&);
        int visualizarSessao (const Codigo&, Sessao*);
        //Salas
        int incluirSala (const Sala&);
        int editarSala (const Sala&);
        int excluirSala (const Codigo&);
        int visualizarSala (const Codigo&, Sala*);
};



#endif // CONTROLADORESSERVICO_H_INCLUDED
