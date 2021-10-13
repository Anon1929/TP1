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
int CntrServicoAutenticacao::autenticar(Matricula matricula, Senha senha){
    try {
        ComandoLerSenha comando(matricula);
        comando.executar();
        Senha senhaReal = comando.getResultado();
        if(senhaReal.getValor() == senha.getValor()) return 0;
        else return 1;
    }catch (EErroPersistencia &exp) {
        cout << exp.what() << endl;
        return 2;
    }
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
//Peças
int CntrServicoPSS::incluirPeca (const Peca&){
}
int CntrServicoPSS::editarPeca (const Peca&){
}
int CntrServicoPSS::excluirPeca (const Codigo&){
}
int CntrServicoPSS::visualizarPeca (const Codigo&, Peca*){
}
//Sessões
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
