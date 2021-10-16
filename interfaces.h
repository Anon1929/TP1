#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <vector>

using namespace std;

// Forward declarations.
//Apresentacao
class IApresentacaoAutenticacao;
class IApresentacaoParticipante;
class IApresentacaoPSS;

//Servico
class IServicoAutenticacao;
class IServicoParticipante;
class IServicoPSS;




//Autenticacao
class IApresentacaoAutenticacao {
    public:
        virtual int autenticar(Matricula*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};
class IServicoAutenticacao {
    public:
        virtual int autenticar(const Matricula&, const Senha&) = 0;
        virtual ~IServicoAutenticacao(){}
};

//Participante
class IApresentacaoParticipante {
    public:
        virtual void cadastrar() = 0;
        virtual bool executar(const Matricula&) = 0;
        virtual void setCntrServicoParticipante(IServicoParticipante*) = 0;
        virtual ~IApresentacaoParticipante(){}
};
class IServicoParticipante {
    public:
        virtual int cadastrarUsuario(const Participante&) = 0;
        virtual int editarUsuario(const Participante&) = 0;
        virtual int excluirUsuario(const Matricula&) = 0;
        virtual int visualizarUsuario(const Matricula&, Participante*) = 0;
        virtual int cadastrarComoParticipante(const Matricula&, const Codigo&) = 0;
        virtual ~IServicoParticipante(){}
};

//Peca Sessao Sala
class IApresentacaoPSS {
    public:
        virtual void executar() = 0;
        virtual void executar(const Matricula&) = 0;
        virtual void setCntrServicoPSS(IServicoPSS*) = 0;
        virtual ~IApresentacaoPSS(){}
};
class IServicoPSS {
    public:
        //Sem cadastro
        virtual vector<Peca> listarPecas() = 0;
        virtual vector<Sessao> listarSessoes() = 0;
        virtual vector<Sala> listarSalas() = 0;
        //Com cadastro
        //Peças
        virtual int incluirPeca (const Peca&) = 0;
        virtual int editarPeca (const Peca&) = 0;
        virtual int excluirPeca (const Codigo&) = 0;
        virtual int visualizarPeca (const Codigo&, Peca*) = 0;
        //Sessões
        virtual int incluirSessao (const Sessao&) = 0;
        virtual int editarSessao (const Sessao&) = 0;
        virtual int excluirSessao (const Codigo&) = 0;
        virtual int visualizarSessao (const Codigo&, Sessao*) = 0;
        //Salas
        virtual int incluirSala (const Sala&) = 0;
        virtual int editarSala (const Sala&) = 0;
        virtual int excluirSala (const Codigo&) = 0;
        virtual int visualizarSala (const Codigo&, Sala*) = 0;

        virtual ~IServicoPSS(){}
};

#endif // INTERFACE_H_INCLUDED
