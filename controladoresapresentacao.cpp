#include <iostream>
#include <string.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interface.h"
#include "controladoresapresentacao.h"

// Implementações de métodos de classes controladoras de apresentação.
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
            campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
            echo();


            switch(campo){
                case 1:
                int retorno;
                retorno = cntrApresentacaoAutenticacao->autenticar(&matricula);
                switch(retorno){
                    case 0:
                        while(apresentar){
                            clear();                                                            // Limpa janela.
                            mvprintw(linha/4,coluna/4,"%s",texto6);                             // Imprime nome do campo.
                            mvprintw(linha/4 + 2,coluna/4,"%s",texto7);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s",texto8);                         // Imprime nome do campo.
                            mvprintw(linha/4 + 6,coluna/4,"%s",texto9);                         // Imprime nome do campo.                                    // Apresenta tela de seleção de serviço.
                            noecho();
                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversão de ASCII.
                            echo();
                            switch(campo){
                                case 1: cntrApresentacaoParticipante->executar(matricula);               // Solicita serviço de participante
                                        break;
                                case 2: cntrApresentacaoPSS->executar(&matricula);
                                        break;
                                case 3: apresentar = false;
                                        break;
                                        }
                            }
                            break;
                            case 1:
                            case 2:
                            default:
                                clear();                                                                // Limpa janela.
                                mvprintw(linha/4,coluna/4,"%s",texto10);                                // Imprime mensagem.
                                noecho();                                                               // Desabilita eco.
                                getch();                                                                // Leitura de caracter digitado.
                                echo();
                                break;                                                          // Habilita eco.
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
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    echo();                                                                                     // Habilita eco.
    char campo1[80];
    char campo2[80];

    char texto1[]="Digite a Matricula : ";
    char texto2[]="Digite a senha: ";
    char texto3[]="Dado em formato incorreto. Digite algo.";

    // Solicitar matricula e senha.
    while(true) {
        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do campo.
        getstr(campo1);                                                                         // Lê valor do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        getstr(campo2);
        Senha senha;

        try {
            // Pedir matrícula e salvar em entrada
            matricula->setValor(string(campo1));
            // Pedir senha e salvar em entrada
            senha.setValor(string(campo2));
            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s",texto3);                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // Lê caracter digitado.
            echo();
            // Tratamento de exceção
        }
    }

    // Solicitar autenticação.
    int resultado = cntrServicoAutenticacao->autenticar(*matricula, senha);

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
    bool apresentar = true;
    int campo;
    int linha,coluna;
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    char texto1[]="Selecione um dos servicos : ";
    char texto2[]="1 - Listar Pecas.";
    char texto3[]="2 - Listar Sessoes.";
    char texto4[]="3 - Listar Salas.";
    char texto5[]="4 - Retornar.";
    while(apresentar){
        clear();
        mvprintw(linha/4,coluna/4,"%s",texto1);                                                 // Imprime nome do camp
        mvprintw(linha/4 + 2,coluna/4,"%s",texto2);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s",texto3);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s",texto4);                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s",texto5);                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();

    }

}
void CntrApresentacaoPSS::executar(Matricula*){
}
