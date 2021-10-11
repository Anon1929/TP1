#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "vector"

// Forward declarations.
//Apresentacao
class IApresentacaoAutenticacao;
class IApresentacaoParticipante;
class IApresentacaoPecaSessaoSala;
//servico
class IServicoAutenticacao;
class IServicoParticipante;
class IServicoPecaSessaoSala;

//Autenticacao
class IApresentacaoAutenticacao {
    public:
        virtual int autenticar(const matricula&) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IServicoAutenticacao {
    public:
        virtual int autenticar(const matricula&, const senha&) = 0;
        virtual ~IServicoAutenticacao(){}
};


//Participante

class IApresentacaoParticipante {
    public:
        virtual void cadastrar() = 0;
        virtual void executar(const matricula&) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoParticipante(){}
};

class IServicoParticipante {
    public:
        virtual int cadastrarUsuario(const participante&) = 0;
        virtual int editarUsuario(const participante&) = 0;
        virtual int excluirUsuario(const matricula&) = 0;
        virtual int cadastrarComoParticipante(const matricula&, const idPeca&) = 0;
        virtual ~IServicoParticipante(){}
};
//Peca Sessao Sala
class IApresentacaoPSS {
    public:
        virtual void executar() = 0;
        virtual void executar(const matricula&) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
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
        virtual int incluirPeca (const peca&) = 0;
        virtual int editarPeca (const peca&) = 0;
        virtual int excluirPeca (const id&) = 0;
        virtual int visualizarPeca (const id&, peca*) = 0;
        //Sessões
        virtual int incluirSessao (const sessao&) = 0;
        virtual int editarSessao (const sessao&) = 0;
        virtual int excluirSessao (const id&) = 0;
        virtual int visualizarSessao (const id&, sessao*) = 0;
        //Salas
        virtual int incluirSala (const sala&) = 0;
        virtual int editarSala (const sala&) = 0;
        virtual int excluirSala (const id&) = 0;
        virtual int visualizarSala (const id&, sala*) = 0;

        virtual ~IServicoPSS(){}
};

#endif // INTERFACE_H_INCLUDED
