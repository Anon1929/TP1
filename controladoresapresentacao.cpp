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

    bool apresentar = true;
    int campo;
    int linha,coluna;
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.



        while(apresentar){
            clear();
            mvprintw(linha/4,coluna/4,"%s %d","Selecione um dos servicos : ");                                                 // Imprime nome do campo.
            mvprintw(linha/4 + 2,coluna/4,"%s","1 - Acessar sistema.");                                             // Imprime nome do campo.
            mvprintw(linha/4 + 4,coluna/4,"%s","2 - Cadastrar usuario.");                                             // Imprime nome do campo.
            mvprintw(linha/4 + 6,coluna/4,"%s","3 - Listar dados sobre pecas, sessoes ou salas.");                                             // Imprime nome do campo.
            mvprintw(linha/4 + 8,coluna/4,"%s","4 - Encerrar execucao do sistema.");                                             // Imprime nome do campo.
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
                            mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos : ");                             // Imprime nome do campo.
                            mvprintw(linha/4 + 2,coluna/4,"%s","1 - Selecionar servicos de participante.");                         // Imprime nome do campo.
                            mvprintw(linha/4 + 4,coluna/4,"%s","2 - Selecionar servicos relacionados a pecas, sessoes ou salas.");                         // Imprime nome do campo.
                            mvprintw(linha/4 + 6,coluna/4,"%s","3 - Encerrar sessao.");                         // Imprime nome do campo.                                    // Apresenta tela de seleção de serviço.
                            noecho();
                            campo = getch() - 48;                                               // Leitura do campo de entrada e conversão de ASCII.
                            echo();
                            switch(campo){
                                case 1:
                                    if(cntrApresentacaoParticipante->executar(matricula))
                                        apresentar=false;
                                        break;
                                case 2: cntrApresentacaoPSS->executar(matricula);
                                        break;
                                case 3: apresentar = false;
                                        break;
                                        }
                            }
                            apresentar=true;
                            break;
                    case 1:
                        clear();
                        mvprintw(linha/4,coluna/4,"%s","Senha incorreta");
                        getch();
                        break;
                    case 2:
                        clear();
                        mvprintw(linha/4,coluna/4,"%s","Matricula inexistente");
                        getch();
                        break;
                    default:
                            clear();                                                                // Limpa janela.
                            mvprintw(linha/4,coluna/4,"%s","Falha na autenticacao. Digite algo para continuar.");                                // Imprime mensagem.
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
    // Solicitar matricula e senha.

    while(true) {
        clear();                                                                                // Limpa janela.
        mvprintw(linha/4,coluna/4,"%s","Digite a Matricula : ");                                                 // Imprime nome do campo.
        getstr(campo1);                                                                         // Lê valor do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s","Digite a senha: ");                                             // Imprime nome do campo.
        getstr(campo2);

        try {
            // Pedir matrícula e salvar em entrada
            matricula->setValor(campo1);
            // Pedir senha e salvar em entrada
            senha.setValor(campo2);
            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
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
void CntrApresentacaoParticipante::consultarDadosPessoais(const Matricula& matricula){
    Participante *participante = new Participante;
    cntrServicoParticipante->visualizarUsuario(matricula,participante);
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    clear();
    mvprintw(linha/8+2,coluna/4,"%s %s","Matricula : ", participante->getMatricula().getValor());
    mvprintw(linha/8+4,coluna/4,"%s %s","Nome : ", participante->getNome().getValor());
    mvprintw(linha/8+6,coluna/4,"%s %s","Sobrenome : " ,participante->getSobrenome().getValor());
    mvprintw(linha/8+8,coluna/4,"%s %s","Cargo : ", participante->getCargo().getValor());
    mvprintw(linha/8+10,coluna/4,"%s %s","Email : " ,participante->getEmail().getValor());
    mvprintw(linha/8+12,coluna/4,"%s %s","Telefone : ", participante->getTelefone().getValor());
    mvprintw(linha/8+12,coluna/4,"%s %s","Senha : " ,participante->getSenha().getValor());
    mvprintw(linha/8+14,coluna/4,"%s","Digite algo para continuar");
    getch();                                                                            // Lê caracter digitado.

}
void CntrApresentacaoParticipante::editarUsuario(const Matricula& matricula){
    Participante participante;
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Nome nome;
    Nome sobrenome;
    Email email;
    Cargo cargo;
    Telefone telefone;
    Senha senha;
    while(true) {
        clear();                                                                                // Limpa janela.
                                                                                // Lê valor do campo.
        try {


            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Nome : ");
            getstr(campo1);
            nome.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Sobrenome : ");
            getstr(campo1);
            sobrenome.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Email : ");
            getstr(campo1);
            email.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Cargo : ");
            getstr(campo1);
            cargo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite a Senha : ");
            getstr(campo1);
            senha.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Telefone : ");
            getstr(campo1);
            telefone.setValor(campo1);

            participante.setMatricula(matricula);
            participante.setNome(nome);
            participante.setSobrenome(sobrenome);
            participante.setCargo(cargo);
            participante.setEmail(email);
            participante.setSenha(senha);
            participante.setTelefone(telefone);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // Lê caracter digitado.
            echo();
            // Tratamento de exceção
        }
    }
    int resultado;
    clear();
    resultado = cntrServicoParticipante->editarUsuario(participante);
    switch(resultado){
    case 0:
        mvprintw(linha/4,coluna/4,"%s","Participante editado com sucesso. Digite algo.");
        noecho();
        getch();
        echo();
        break;
    case 1:
    default:
        mvprintw(linha/4,coluna/4,"%s","Falha ao editar participante. Digite algo.");
        noecho();
        getch();
        echo();
        break;
    }


}
void CntrApresentacaoParticipante::excluirUsuario(const Matricula& matricula){
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    clear();
    int resultado = cntrServicoParticipante->excluirUsuario(matricula);
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Participante excluido com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
        default:
            mvprintw(linha/4,coluna/4,"%s","Falha ao excluir participante. Digite algo.");
            noecho();
            getch();
            echo();
        break;
    }

}
//--------------------------- Public ----------------------------
void CntrApresentacaoParticipante::cadastrar(){
    Participante participante;
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Cargo cargo;
    Telefone telefone;
    Senha senha;
    while(true) {
        clear();                                                                                // Limpa janela.
                                                                                // Lê valor do campo.
        try {
            clear();
            mvprintw(linha/4,coluna/4,"%s","Digite a Matricula : ");
            getstr(campo1);
            matricula.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Nome : ");
            getstr(campo1);
            nome.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Sobrenome : ");
            getstr(campo1);
            sobrenome.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Email : ");
            getstr(campo1);
            email.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Cargo : ");
            getstr(campo1);
            cargo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite a Senha : ");
            getstr(campo1);
            senha.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Telefone : ");
            getstr(campo1);
            telefone.setValor(campo1);

            participante.setMatricula(matricula);
            participante.setNome(nome);
            participante.setSobrenome(sobrenome);
            participante.setCargo(cargo);
            participante.setEmail(email);
            participante.setSenha(senha);
            participante.setTelefone(telefone);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // Lê caracter digitado.
            echo();
            // Tratamento de exceção
        }
    }
    int resultado;
    clear();
    resultado = cntrServicoParticipante->cadastrarUsuario(participante);
    switch(resultado){
    case 0:
        mvprintw(linha/4,coluna/4,"%s","Participante cadastrado com sucesso. Digite algo.");
        noecho();
        getch();
        echo();
        break;
    case 1:
    default:
        mvprintw(linha/4,coluna/4,"%s","Falha ao cadastrar participante. Digite algo.");
        noecho();
        getch();
        echo();
        break;
    }



}
bool CntrApresentacaoParticipante::executar(const Matricula& matricula){
    clear();
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    bool apresentar=true;
    int campo;
    while(apresentar){
            clear();
            mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos : ");                             // Imprime nome do campo.
            mvprintw(linha/4 + 2,coluna/4,"%s","1 - Cadastrar outro participante.");                         // Imprime nome do campo.
            mvprintw(linha/4 + 4,coluna/4,"%s","2 - Ver dados de usuário.");                         // Imprime nome do campo.
            mvprintw(linha/4 + 6,coluna/4,"%s","3 - Editar dados de usuário.");                         // Imprime nome do campo.                                    // Apresenta tela de seleção de serviço.
            mvprintw(linha/4 + 6,coluna/4,"%s","4 - Excluir usuário.");                         // Imprime nome do campo.                                    // Apresenta tela de seleção de serviço.
            mvprintw(linha/4 + 6,coluna/4,"%s","5 - Retornar.");                         // Imprime nome do campo.                                    // Apresenta tela de seleção de serviço.
            campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
            switch(campo){
                case 1:
                    cadastrar();
                    break;
                case 2:
                    consultarDadosPessoais(matricula);
                    break;
                case 3:
                    editarUsuario(matricula);
                    break;
                case 4:
                    excluirUsuario(matricula);
                    return true;
                    break;
                case 5:
                    return false;
                    break;
            }


    }
    return false;

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
    while(apresentar){
        clear();
        mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos : ");                                                 // Imprime nome do camp
        mvprintw(linha/4 + 2,coluna/4,"%s","1 - Listar Pecas.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s","2 - Listar Sessoes.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s","3 - Listar Salas.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s","4 - Retornar.");                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e conversão de ASCII.
        echo();
        switch(campo){
            case 1:

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                apresentar = false;
                break;

        }

    }

}
void CntrApresentacaoPSS::executar(const Matricula&){
}
