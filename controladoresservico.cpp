#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladoresservico.h"
#include "unidadepersistencia.h"

// Implementa��es de m�todos de classes controladoras de apresenta��o.
//--------------------------------------------------------------------------------------------
// CntrServicoAutenticacao
//--------------------------- Private ---------------------------
//---------------------------- Public ----------------------------
int CntrServicoAutenticacao::autenticar(const Matricula& matricula, const Senha& senha){
    try {
        ComandoLerSenha comando(matricula);
        comando.executar();
        Senha senhaReal = comando.getResultado();
        if(senhaReal.getValor() == senha.getValor()) return 0;
        else return 1;
    }catch(...) {
        return 2;
    }
}

//--------------------------------------------------------------------------------------------
// CntrServicoParticipante
//--------------------------- Private ---------------------------
//--------------------------- Public ----------------------------
int CntrServicoParticipante::cadastrarUsuario(const Participante& participante){
    ComandoCadastrarParticipante cadastrar(participante);
    return cadastrar.executar();
}
int CntrServicoParticipante::editarUsuario(const Participante& participante){
    ComandoEditarParticipante comando(participante);
    return comando.executar();
}
int CntrServicoParticipante::excluirUsuario(const Matricula& matricula){
    ComandoExcluirParticipante comando(matricula);
    return comando.executar();
}
int CntrServicoParticipante::cadastrarComoParticipante(const Matricula& matricula, const Codigo& id){
    ComandoCadastrarParticipanteEmPeca cadastrar(matricula, id);
    return cadastrar.executar();
}
int CntrServicoParticipante::visualizarUsuario(const Matricula& matricula, Participante* participante){
    ComandoPesquisarParticipante comando(matricula);
    int ret = comando.executar();
    if(ret==0){
        try{
            *participante = comando.getResultado();
            return 0;
        }catch(...){
            return 1;
        }
    }else{
        return 1;
    }
}

//--------------------------------------------------------------------------------------------
// CntrServicoPSS
//--------------------------- Private ---------------------------
//---------------------------- Public ----------------------------
vector<Peca> CntrServicoPSS::listarPecas(){
    vector<Peca> r;
    ComandoVisualizarPecas comando;
    int ret = comando.executar();
    if(ret==0){
        try{
            r = comando.getValor();
            return r;
        }catch(...){
            return r;
        }
    }else{
        return r;
    }
}
vector<Sessao> CntrServicoPSS::listarSessoes(){
    vector<Sessao> r;
    ComandoVisualizarSessoes comando;
    int ret = comando.executar();
    if(ret==0){
        try{
            r = comando.getValor();
            return r;
        }catch(...){
            return r;
        }
    }else{
        return r;
    }
}
vector<Sala> CntrServicoPSS::listarSalas(){
    vector<Sala> r;
    ComandoVisualizarSalas comando;
    int ret = comando.executar();
    if(ret==0){
        try{
            r = comando.getValor();
            return r;
        }catch(...){
            return r;
        }
    }else{
        return r;
    }
}
//Pe�as
int CntrServicoPSS::incluirPeca (const Peca& peca){
    ComandoCadastrarPeca cadastrar(peca);
    return cadastrar.executar();
}
int CntrServicoPSS::editarPeca (const Peca& peca){
    ComandoEditarPeca comando(peca);
    return comando.executar();
}
int CntrServicoPSS::excluirPeca (const Codigo& codigo){
    ComandoExcluirPeca comando(codigo);
    return comando.executar();
}
int CntrServicoPSS::visualizarPeca (const Codigo& codigo, Peca* peca){
    ComandoPesquisarPeca comando(codigo);
    int ret = comando.executar();
    if(ret==0){
        try{
            *peca = comando.getResultado();
            return 0;
        }catch(...){
            return 1;
        }
    }else{
        return 1;
    }
}
//Sess�es
int CntrServicoPSS::incluirSessao (const Sessao& sessao){
    ComandoCadastrarSessao cadastrar(sessao);
    return cadastrar.executar();
}
int CntrServicoPSS::editarSessao (const Sessao& sessao){
    ComandoEditarSessao comando(sessao);
    return comando.executar();
}
int CntrServicoPSS::excluirSessao (const Codigo& codigo){
    ComandoExcluirSessao comando(codigo);
    return comando.executar();
}
int CntrServicoPSS::visualizarSessao (const Codigo& codigo, Sessao* sessao){
    ComandoPesquisarSessao comando(codigo);
    int ret = comando.executar();
    if(ret==0){
        try{
            *sessao = comando.getResultado();
            return 0;
        }catch(...){
            return 1;
        }
    }else{
        return 1;
    }
}
//Salas
int CntrServicoPSS::incluirSala (const Sala& sala){
    ComandoCadastrarSala cadastrar(sala);
    return cadastrar.executar();
}
int CntrServicoPSS::editarSala (const Sala& sala){
    ComandoEditarSala comando(sala);
    return comando.executar();
}
int CntrServicoPSS::excluirSala (const Codigo& codigo){
    ComandoExcluirSala comando(codigo);
    return comando.executar();
}
int CntrServicoPSS::visualizarSala (const Codigo& codigo, Sala* sala){
    ComandoPesquisarSala comando(codigo);
    int ret = comando.executar();
    if(ret==0){
        try{
            *sala = comando.getResultado();
            return 0;
        }catch(...){
            return 1;
        }
    }else{
        return 1;
    }
}
