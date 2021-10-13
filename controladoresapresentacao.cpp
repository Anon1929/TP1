#include <iostream>
#include <string.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladoresapresentacao.h"

// Implementações de métodos de classes controladoras de apresentação.
//--------------------------------------------------------------------------------------------
// CntrApresentacaoControle
//--------------------------- Private ---------------------------
//--------------------------- Public ----------------------------
void CntrApresentacaoControle::executar(){
    int entrada;
    while(true){
        cout << "Escolha entre uma das funções disponíveis:" << endl;
        cout << "0-sair 1-login" << endl;
        cin >> entrada;
        switch(entrada){
            case 0:
                return;
            case 1:
                cntrApresentacaoAutenticacao->autenticar(&matricula);
                break;
            default:
                cout << "opção inválida" << endl;
        }
    }
}


//--------------------------------------------------------------------------------------------
// CntrApresentacaoAutenticacao
//--------------------------- Private ---------------------------
//--------------------------- Public ----------------------------
int CntrApresentacaoAutenticacao::autenticar(Matricula *matricula){
    Senha senha;
    string entrada;
    // Solicitar matricula e senha.
    while(true){
        try {
            // Pedir matrícula e salvar em entrada
            cout << "insira matrícula" << endl;
            cin >> entrada;
            matricula->setValor(entrada);
            // Pedir senha e salvar em entrada
            cout << "insira senha:" << endl;
            cin >> entrada;
            senha.setValor(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << "matricula ou senha com formato inválido" << endl;
            // Tratamento de exceção
        }
    }

    // Solicitar autenticação.
    int resultado = cntrServicoAutenticacao->autenticar(*matricula, senha);
    switch(resultado){
        case 0:
            cout << "Autenticado com sucesso" << endl;
            break;
        case 1:
            cout << "Senha incorreta" << endl;
            break;
        case 2:
            cout << "Falha em recuperar a senha no banco de dados" << endl;
            break;
    }
    // Retornar resultado da autenticação.
    return resultado;
}

//--------------------------------------------------------------------------------------------
// CntrApresentacaoParticipante
//--------------------------- Private ---------------------------
void CntrApresentacaoParticipante::consultarDadosPessoais(){
}
void CntrApresentacaoParticipante::editarUsuario(){
}
void CntrApresentacaoParticipante::excluirUsuario(){
}
//--------------------------- Public ----------------------------
void CntrApresentacaoParticipante::cadastrar(){
}
void CntrApresentacaoParticipante::executar(const Matricula&){
}

//--------------------------------------------------------------------------------------------
// CntrApresentacaoPSS
//--------------------------- Private ---------------------------
void CntrApresentacaoPSS::listarPecas(){
}
void CntrApresentacaoPSS::listarSessoes(){
}
void CntrApresentacaoPSS::listarSalas(){
}
//Peca
void CntrApresentacaoPSS::incluirPeca(){
}
void CntrApresentacaoPSS::editarPeca(){
}
void CntrApresentacaoPSS::excluirPeca(){
}
void CntrApresentacaoPSS::visualizarPeca(){
}
//Sessões
void CntrApresentacaoPSS::incluirSessao(){
}
void CntrApresentacaoPSS::editarSessao(){
}
void CntrApresentacaoPSS::excluirSessao(){
}
void CntrApresentacaoPSS::visualizarSessao(){
}
//Salas
void CntrApresentacaoPSS::incluirSala(){
}
void CntrApresentacaoPSS::editarSala(){
}
void CntrApresentacaoPSS::excluirSala(){
}
void CntrApresentacaoPSS::visualizarSala(){
}
//--------------------------- Public ----------------------------
void CntrApresentacaoPSS::executar(){
}
void CntrApresentacaoPSS::executar(const Matricula&){
}
