#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladoresservico.h"
#include "unidadepersistencia.h"

// Implementações de métodos de classes controladoras de apresentação.
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
int CntrServicoParticipante::editarUsuario(const Participante&){

}
int CntrServicoParticipante::excluirUsuario(const Matricula&){
}
int CntrServicoParticipante::cadastrarComoParticipante(const Matricula&, const Codigo&){
}
int CntrServicoParticipante::visualizarUsuario(const Matricula&, Participante*){
}

//--------------------------------------------------------------------------------------------
// CntrServicoPSS
//--------------------------- Private ---------------------------
//---------------------------- Public ----------------------------
vector<Peca> CntrServicoPSS::listarPecas(){
}
vector<Sessao> CntrServicoPSS::listarSessoes(){
}
vector<Sala> CntrServicoPSS::listarSalas(){
}
//Peças
int CntrServicoPSS::incluirPeca (const Peca& peca){
    ComandoCadastrarPeca cadastrar(peca);
    return cadastrar.executar();
}
int CntrServicoPSS::editarPeca (const Peca&){
}
int CntrServicoPSS::excluirPeca (const Codigo&){
}
int CntrServicoPSS::visualizarPeca (const Codigo&, Peca*){
}
//Sessões
int CntrServicoPSS::incluirSessao (const Sessao& sessao, const Codigo& codigoPeca, const Codigo& codigoSala){
    ComandoCadastrarSessao cadastrar(sessao, codigoPeca, codigoSala);
    return cadastrar.executar();
}
int CntrServicoPSS::editarSessao (const Sessao&){
}
int CntrServicoPSS::excluirSessao (const Codigo&){
}
int CntrServicoPSS::visualizarSessao (const Codigo&, Sessao*){
}
//Salas
int CntrServicoPSS::incluirSala (const Sala& sala){
    ComandoCadastrarSala cadastrar(sala);
    return cadastrar.executar();
}
int CntrServicoPSS::editarSala (const Sala&){
}
int CntrServicoPSS::excluirSala (const Codigo&){
}
int CntrServicoPSS::visualizarSala (const Codigo&, Sala*){
}
