#ifndef CONTROLADORESAPRESENTACAO_H_INCLUDED
#define CONTROLADORESAPRESENTACAO_H_INCLUDED

#include <string.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"


//--------------------------------------------------------------------------------------------
// Declarações de classes controladoras e implementações de métodos.

class CntrApresentacaoControle{
    private:
        Matricula matricula;
        IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
        IApresentacaoParticipante *cntrApresentacaoParticipante;
        IApresentacaoPSS *cntrApresentacaoPSS;
    public:
        void executar();
        void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
        void setCntrApresentacaoParticipante(IApresentacaoParticipante*);
        void setCntrApresentacaoPSS(IApresentacaoPSS*);
};

inline void CntrApresentacaoControle::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoParticipante(IApresentacaoParticipante *cntr){
            cntrApresentacaoParticipante = cntr;
}

inline void CntrApresentacaoControle::setCntrApresentacaoPSS(IApresentacaoPSS *cntr){
    cntrApresentacaoPSS = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
    public:
        int autenticar(Matricula*);
        void setCntrServicoAutenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setCntrServicoAutenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

//--------------------------------------------------------------------------------------------

class CntrApresentacaoParticipante:public IApresentacaoParticipante{
    private:
        IServicoParticipante *cntrServicoParticipante;
        void consultarDadosPessoais();
        void editarUsuario();
        void excluirUsuario();
        void cadastrarComoParticipante();
    public:
        void executar(Matricula*);
        void cadastrar();
        void setCntrServicoParticipante(IServicoParticipante*);
};

inline void CntrApresentacaoParticipante::setCntrServicoParticipante(IServicoParticipante *cntr){
    cntrServicoParticipante = cntr;
}
//--------------------------------------------------------------------------------------------

class CntrApresentacaoPSS:public IApresentacaoPSS{
    private:
        IServicoPSS *cntr;
        void listarPecas();
        void listarSessoes();
        void listarSalas();
        //Peca
        void incluirPeca();
        void editarPeca();
        void excluirPeca();
        void visualizarPeca();
        //Sessões
        void incluirSessao();
        void editarSessao();
        void excluirSessao();
        void visualizarSessao();
        //Salas
        void incluirSala();
        void editarSala();
        void excluirSala();
        void visualizarSala();
    public:
        void executar();
        void executar(Matricula*);
        void setCntrServicoPSS(IServicoPSS*); //possível bug
};

inline void CntrApresentacaoPSS::setCntrServicoPSS(IServicoPSS *cntr){
    this->cntr = cntr;
}

#endif // CONTROLADORESAPRESENTACAO_H_INCLUDED
