
#ifndef CONTROLADORESSERVICO_H_INCLUDED
#define CONTROLADORESSERVICO_H_INCLUDED

#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "interface.h"

// Declarações de classes controladoras e implementações de métodos.
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
        int cadastrarComoParticipante(const Matricula&, const Codigo&);
};

//--------------------------------------------------------------------------------------------
class CntrServicoPSS:public IServicoPSS{
    private:
    public:
        vector<Peca> listarPecas();
        vector<Sessao> listarSessoes();
        vector<Sala> listarSalas();
        //Peças
        int incluirPeca (const Peca&);
        int editarPeca (const Peca&);
        int excluirPeca (const Codigo&);
        int visualizarPeca (const Codigo&, Peca*);
        //Sessões
        int incluirSessao (const Sessao&, const Codigo&, const Codigo&);
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
