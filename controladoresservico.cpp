#include <string.h>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladoresservico.h"

// Implementa��es de m�todos de classes controladoras de apresenta��o.
//--------------------------------------------------------------------------------------------
// CntrServicoAutenticacao
//--------------------------- Private ---------------------------
//---------------------------- Public ----------------------------
int CntrServicoAutenticacao::autenticar(const Matricula&, const Senha&){
}

//--------------------------------------------------------------------------------------------
// CntrServicoParticipante
//--------------------------- Private ---------------------------
//--------------------------- Public ----------------------------
int CntrServicoParticipante::cadastrarUsuario(const Participante&){
}
int CntrServicoParticipante::editarUsuario(const Participante&){
}
int CntrServicoParticipante::excluirUsuario(const Matricula&){
}
int CntrServicoParticipante::cadastrarComoParticipante(const Matricula&, const Codigo&){
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
//Pe�as
int CntrServicoPSS::incluirPeca (const Peca&){
}
int CntrServicoPSS::editarPeca (const Peca&){
}
int CntrServicoPSS::excluirPeca (const Codigo&){
}
int CntrServicoPSS::visualizarPeca (const Codigo&, Peca*){
}
//Sess�es
int CntrServicoPSS::incluirSessao (const Sessao&, const Codigo&, const Codigo&){
}
int CntrServicoPSS::editarSessao (const Sessao&){
}
int CntrServicoPSS::excluirSessao (const Codigo&){
}
int CntrServicoPSS::visualizarSessao (const Codigo&, Sessao*){
}
//Salas
int CntrServicoPSS::incluirSala (const Sala&){
}
int CntrServicoPSS::editarSala (const Sala&){
}
int CntrServicoPSS::excluirSala (const Codigo&){
}
int CntrServicoPSS::visualizarSala (const Codigo&, Sala*){
}
