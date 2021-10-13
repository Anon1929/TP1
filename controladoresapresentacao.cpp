#include <iostream>
#include <string.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interface.h"
#include "controladoresapresentacao.h"

// Implementa��es de m�todos de classes controladoras de apresenta��o.
//--------------------------------------------------------------------------------------------
// CntrApresentacaoControle
//--------------------------- Private ---------------------------
//--------------------------- Public ----------------------------
void CntrApresentacaoControle::executar(){
    bool apresentar = true;
    int campo;
    int linha,coluna;
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Acessar sistema.";
    char texto3[]="2 - Cadastrar usuario.";
    char texto4[]="3 - Listar dados sobre pecas, sessoes ou salas.";
    char texto5[]="4 - Encerrar execucao do sistema.";

    char texto6[]="Selecione um dos servicos : ";
    char texto7[]="1 - Selecionar servicos de participante.";
    char texto8[]="2 - Selecionar servicos relacionados a pecas, sessoes ou salas.";
    char texto9[]="3 - Encerrar sessao.";
    char texto10[]="Falha na autenticacao. Digite algo para continuar.";

        while(apresentar){
            clear();
            mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
            mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
            mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
            mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
            mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
            noecho();
            campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
            echo();
            switch(campo){
                case 1:
                if(cntrApresentacaoAutenticacao->autenticar(matricula)){
                    while(apresentar){

                            clear();                                                            // Limpa janela.
                            mvprintw(linha/4,coluna/4,"%s",texto6);                             // Imprime nome do campo.
                            mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 6,coluna/4,"%s",texto9);                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.

                            noecho();
                            campo = getch() - 48;                                               // Leitura do campo de entrada e convers�o de ASCII.
                            echo();
                            switch(campo){
                                case 1: cntrApresentacaoParticipante->executar(matricula);               // Solicita servi�o de participante
                                        break;
                                case 2: cntrApresentacaoPSS->executar(matricula);
                                        break;
                                case 3: apresentar = false;
                                        break;
                                        }
                            }
                    }
                    else{
                        clear();                                                                // Limpa janela.
                        mvprintw(linha/4,coluna/4,"%s",texto10);                                // Imprime mensagem.
                        noecho();                                                               // Desabilita eco.
                        getch();                                                                // Leitura de caracter digitado.
                        echo();                                                                 // Habilita eco.
                    }
                    break;

                    case 2:
                        cntrApresentacaoParticipante->cadastrar();
                        break;

                    case 3:
                        cntrApresentacaoPSS->executar();
                        break;
                    case 4:
                        apresentar = false;
                        break;

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
    while(true) {
        try {
            // Pedir matr�cula e salvar em entrada
            matricula->setValor(entrada);
            // Pedir senha e salvar em entrada
            senha.setValor(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            // Tratamento de exce��o
        }
    }

    // Solicitar autentica��o.
    int resultado = cntrServicoAutenticacao->autenticar(*matricula, senha);

    // Retornar resultado da autentica��o.
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
void CntrApresentacaoParticipante::cadastrarComoParticipante(){
}
//--------------------------- Public ----------------------------
void CntrApresentacaoParticipante::cadastrar(){
}
void CntrApresentacaoParticipante::executar(){
}
void CntrApresentacaoParticipante::executar(Matricula*){
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
//Sess�es
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
void CntrApresentacaoPSS::executar(Matricula*){
}
