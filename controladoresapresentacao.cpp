#include <iostream>
#include <string.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
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

        while(apresentar){
            clear();
            mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos : ");                                                 // Imprime nome do campo.
            mvprintw(linha/4 + 2,coluna/4,"%s","1 - Acessar sistema.");                                             // Imprime nome do campo.
            mvprintw(linha/4 + 4,coluna/4,"%s","2 - Cadastrar usuario.");                                             // Imprime nome do campo.
            mvprintw(linha/4 + 6,coluna/4,"%s","3 - Listar dados sobre pecas, sessoes ou salas.");                                             // Imprime nome do campo.
            mvprintw(linha/4 + 8,coluna/4,"%s","4 - Encerrar execucao do sistema.");                                             // Imprime nome do campo.
            noecho();
            campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
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
                            mvprintw(linha/4 + 6,coluna/4,"%s","3 - Encerrar sessao.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
                            noecho();
                            campo = getch() - 48;                                               // Leitura do campo de entrada e convers�o de ASCII.
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
        getstr(campo1);                                                                         // L� valor do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s","Digite a senha: ");                                             // Imprime nome do campo.
        getstr(campo2);

        try {
            // Pedir matr�cula e salvar em entrada
            matricula->setValor(campo1);
            // Pedir senha e salvar em entrada
            senha.setValor(campo2);
            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
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
void CntrApresentacaoParticipante::consultarDadosPessoais(const Matricula& matricula){
    Participante *participante = new Participante;
    cntrServicoParticipante->visualizarUsuario(matricula,participante);
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    clear();
    mvprintw(linha/8+2,coluna/4,"%s %s","Matricula : ", participante->getMatricula().getValor().c_str());
    mvprintw(linha/8+4,coluna/4,"%s %s","Nome : ", participante->getNome().getValor().c_str());
    mvprintw(linha/8+6,coluna/4,"%s %s","Sobrenome : ", participante->getSobrenome().getValor().c_str());
    mvprintw(linha/8+8,coluna/4,"%s %s","Cargo : ", participante->getCargo().getValor().c_str());
    mvprintw(linha/8+10,coluna/4,"%s %s","Email : ", participante->getEmail().getValor().c_str());
    mvprintw(linha/8+12,coluna/4,"%s %s","Telefone : ", participante->getTelefone().getValor().c_str());
    mvprintw(linha/8+14,coluna/4,"%s %s","Senha : ", participante->getSenha().getValor().c_str());
    mvprintw(linha/8+16,coluna/4,"%s %s","IdPeca : ", participante->getIdPeca().getValor().c_str());
    mvprintw(linha/8+18,coluna/4,"%s","Digite algo para continuar");
    getch();                                                                            // L� caracter digitado.

}
void CntrApresentacaoParticipante::editarUsuario(const Matricula& matricula){
    Participante participante;
    participante.setMatricula(matricula);
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
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Nome : (vazio para não modificar)");
            getstr(campo1);
            if(strcmp(campo1, "") != 0){
                nome.setValor(campo1);
                participante.setNome(nome);
            }
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Sobrenome :  (vazio para não modificar)");
            getstr(campo1);
            if(strcmp(campo1, "") != 0){
                sobrenome.setValor(campo1);
                participante.setSobrenome(sobrenome);
            }

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Email :  (vazio para não modificar)");
            getstr(campo1);
            if(strcmp(campo1, "") != 0){
                email.setValor(campo1);
                participante.setEmail(email);
            }

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Cargo :  (vazio para não modificar)");
            getstr(campo1);
            if(strcmp(campo1, "") != 0){
                cargo.setValor(campo1);
                participante.setCargo(cargo);
            }

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite a Senha : (vazio para não modificar) ");
            getstr(campo1);
            if(strcmp(campo1, "") != 0){
                senha.setValor(campo1);
                participante.setSenha(senha);
            }

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Telefone :  (vazio para não modificar)");
            getstr(campo1);
            if(strcmp(campo1, "") != 0){
                telefone.setValor(campo1);
                participante.setTelefone(telefone);
            }

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
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
void CntrApresentacaoParticipante::cadastrarcomoparticipante(const Matricula& matricula){
    clear();
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    bool apresentar=true;
    char campo[80];
    Codigo codigo;
    while(apresentar){
        mvprintw(linha/6,coluna/4,"%s","Insira o c�digo da pe�a : ");                             // Imprime nome do campo.
        getstr(campo);
        try{
            codigo.setValor(campo);
            apresentar =false;
        }
        catch(...){
            clear();
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
        }
    }
    int resultado = cntrServicoParticipante->cadastrarComoParticipante(matricula,codigo);
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Participante cadastrado em Peca com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
        default:
            mvprintw(linha/4,coluna/4,"%s","Falha ao cadastrar participante em Peca. Digite algo.");
            noecho();
            getch();
            echo();
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
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
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
            mvprintw(linha/4 -3,coluna/4,"%s","Falha no cadastro. Muito provavelmente ja existe usu�rio com essa matricula. Digite algo.");
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
            mvprintw(linha/6,coluna/4,"%s","Selecione um dos servicos : ");                             // Imprime nome do campo.
            mvprintw(linha/6 + 2,coluna/4,"%s","1 - Ver dados de usuario.");                         // Imprime nome do campo.
            mvprintw(linha/6 + 4,coluna/4,"%s","2 - Editar dados de usuario.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
            mvprintw(linha/6 + 6,coluna/4,"%s","3 - Excluir usuario.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
            mvprintw(linha/6 + 8,coluna/4,"%s","4 - Cadastrar usuario como participante de Peca.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
            mvprintw(linha/6 + 10,coluna/4,"%s","5 - Retornar.");                         // Imprime nome do campo.                                    // Apresenta tela de sele��o de servi�o.
            campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
            switch(campo){
                case 1:
                    consultarDadosPessoais(matricula);
                    break;
                case 2:
                    editarUsuario(matricula);
                    break;
                case 3:
                    excluirUsuario(matricula);
                    return true;
                    break;
                case 4:
                    cadastrarcomoparticipante(matricula);
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
    clear();
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    vector<Peca> pecas;
    pecas = cntrServicoPSS->listarPecas();
    int i=0;
    if(pecas.empty()){
        mvprintw(linha/8, coluna/6,"Nenhum elemento cadastrado");
        getch();
        return;
    }
    for(auto peca : pecas){
        mvprintw(linha/8 + i*2, coluna/8,"Codigo: %s, Nome: %s, Tipo: %s, Classificacao: %s", peca.getCodigo().getValor().c_str(), peca.getNome().getValor().c_str(), peca.getTipo().getValor().c_str(), peca.getClassificacao().getValor().c_str());
        i++;
    }
    mvprintw(linha/8 + i*2, coluna/8,"Clique qualquer tecla para voltar");
    getch();
}
void CntrApresentacaoPSS::listarSessoes(){
    clear();
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    vector<Sessao> sessoes;
    sessoes = cntrServicoPSS->listarSessoes();
    if(sessoes.empty()){
        mvprintw(linha/8, coluna/6,"Nenhum elemento cadastrado");
        getch();
        return;
    }
    int i=0;
    for(auto sessao : sessoes){
        mvprintw(linha/8 + i*2, coluna/8,"Codigo: %s, data: %s, horario: %s, idSala: %s, idPeca: %s", sessao.getCodigo().getValor().c_str(), sessao.getData().getValor().c_str(), sessao.getHorario().getValor().c_str(), sessao.getIdSala().getValor().c_str(), sessao.getIdPeca().getValor().c_str());
        i++;
    }
    mvprintw(linha/8 + i*2, coluna/8,"Clique qualquer tecla para voltar");
    getch();
}
void CntrApresentacaoPSS::listarSalas(){
    clear();
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);
    vector<Sala> salas;
    salas = cntrServicoPSS->listarSalas();
    if(salas.empty()){
        mvprintw(linha/8, coluna/6,"Nenhum elemento cadastrado");
        getch();
        return;
    }
    int i=0;
    for(auto sala : salas){
        mvprintw(linha/8 + i*2, coluna/8,"Codigo: %s, Nome: %s, Capacidade: %s", sala.getCodigo().getValor().c_str(), sala.getNome().getValor().c_str(), sala.getCapacidade().getValor().c_str());
        i++;
    }
    mvprintw(linha/8 + i*2, coluna/8,"Clique qualquer tecla para voltar");
    getch();
}
//Pecas
void CntrApresentacaoPSS::incluirPeca(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Peca peca;
    Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo : ");
            getstr(campo1);
            codigo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Nome : ");
            getstr(campo1);
            nome.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Tipo : ");
            getstr(campo1);
            tipo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite a Classificacao : ");
            getstr(campo1);
            classificacao.setValor(campo1);

            peca.setCodigo(codigo);
            peca.setNome(nome);
            peca.setTipo(tipo);
            peca.setClassificacao(classificacao);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de excecao
        }
    }

    clear();
    int resultado = cntrServicoPSS->incluirPeca(peca);
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Peca incluida com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
            mvprintw(linha/4 -3,coluna/4,"%s","Falha na inclusao. Muito provavelmente ja existe Peca com esse codigo. Digite algo.");
            noecho();
            getch();
            echo();
            break;
    }
}
void CntrApresentacaoPSS::editarPeca(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Peca peca;
    Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
                codigo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Nome : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
                nome.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Tipo : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
                tipo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite a Classificacao : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
                classificacao.setValor(campo1);

            peca.setCodigo(codigo);
            peca.setNome(nome);
            peca.setTipo(tipo);
            peca.setClassificacao(classificacao);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->editarPeca(peca);
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Peca editada com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
        default:
            mvprintw(linha/4,coluna/4,"%s","Falha ao editar Peca. Digite algo.");
            noecho();
            getch();
            echo();
            break;
    }
}
void CntrApresentacaoPSS::excluirPeca(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Codigo codigo;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Peca a excluir : ");
            getstr(campo1);
            codigo.setValor(campo1);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->excluirPeca(codigo);
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Peca excluida com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
            mvprintw(linha/4,coluna/4,"%s","Falha ao excluir Peca. Muito provavelmente nao foi encontrada ocorrencia para Codigo informado. Digite algo.");
            noecho();
            getch();
            echo();
            break;
    }
}
void CntrApresentacaoPSS::visualizarPeca(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Peca *peca = new Peca;
    Codigo codigo;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Peca a visualizar : ");
            getstr(campo1);
            codigo.setValor(campo1);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->visualizarPeca(codigo,peca);
    switch(resultado){
        case 0:
            mvprintw(linha/8+2,coluna/4,"%s %s","Codigo : ", peca->getCodigo().getValor().c_str());
            mvprintw(linha/8+4,coluna/4,"%s %s","Nome : ", peca->getNome().getValor().c_str());
            mvprintw(linha/8+6,coluna/4,"%s %s","Tipo: ", peca->getTipo().getValor().c_str());
            mvprintw(linha/8+8,coluna/4,"%s %s","Classificacao: ", peca->getClassificacao().getValor().c_str());
            mvprintw(linha/8+10,coluna/4,"%s","Digite algo para continuar");
            getch();                                                                            // L� caracter digitado.
            break;
        case 1:
            mvprintw(linha/4,coluna/4,"%s","Falha ao visualizar Peca. Muito provavelmente nao foi encontrada ocorrencia para Codigo informado. Digite algo.");                        // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            break;
    }
}
//Sessoes
void CntrApresentacaoPSS::incluirSessao(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Sessao sessao;
    Codigo codigo;
    Data data;
    Horario horario;
    Codigo codigoPeca;
    Codigo codigoSala;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo : ");
            getstr(campo1);
            codigo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite a Data : ");
            getstr(campo1);
            data.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Horario : ");
            getstr(campo1);
            horario.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Peca : ");
            getstr(campo1);
            codigoPeca.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Sala : ");
            getstr(campo1);
            codigoSala.setValor(campo1);


            sessao.setCodigo(codigo);
            sessao.setData(data);
            sessao.setHorario(horario);
            sessao.setIdPeca(codigoPeca);
            sessao.setIdSala(codigoSala);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->incluirSessao(sessao); // Adicionar c�digos!
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Sessao incluida com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
            mvprintw(linha/4 -3,coluna/4,"%s","Falha na inclusao. Muito provavelmente ja existe Sessao com esse codigo. Digite algo.");
            noecho();
            getch();
            echo();
            break;
    }
}
void CntrApresentacaoPSS::editarSessao(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Sessao sessao;
    Codigo codigo;
    Data data;
    Horario horario;
    Codigo codigoPeca;
    Codigo codigoSala;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
                codigo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite a Data : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
                data.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Horario : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
                horario.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Peca : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
                codigoPeca.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Sala : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
                codigoSala.setValor(campo1);


            sessao.setCodigo(codigo);
            sessao.setData(data);
            sessao.setHorario(horario);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->editarSessao(sessao); // Adicionar c�digos!
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Sessao editada com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
            mvprintw(linha/4 -3,coluna/4,"%s","Falha ao editar Sessao. Digite algo.");
            noecho();
            getch();
            echo();
            break;
    }
}
void CntrApresentacaoPSS::excluirSessao(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Codigo codigo;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Sessao a excluir : ");
            getstr(campo1);
            codigo.setValor(campo1);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->excluirSessao(codigo);
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Sessao excluida com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
            mvprintw(linha/4,coluna/4,"%s","Falha ao excluir Sessao. Muito provavelmente nao foi encontrada ocorrencia para Codigo informado. Digite algo.");
            noecho();
            getch();
            echo();
            break;
    }
}
void CntrApresentacaoPSS::visualizarSessao(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Sessao *sessao = new Sessao;
    Codigo codigo;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Sessao a visualizar : ");
            getstr(campo1);
            codigo.setValor(campo1);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->visualizarSessao(codigo,sessao);
    switch(resultado){
        case 0:
            mvprintw(linha/8+2,coluna/4,"%s %s","Codigo : ", sessao->getCodigo().getValor().c_str());
            mvprintw(linha/8+4,coluna/4,"%s %s","Data : ", sessao->getData().getValor().c_str());
            mvprintw(linha/8+6,coluna/4,"%s %s","Horario: ", sessao->getHorario().getValor().c_str());
            mvprintw(linha/8+8,coluna/4,"%s %s","idSala: ", sessao->getIdSala().getValor().c_str());
            mvprintw(linha/8+10,coluna/4,"%s %s","idPeca: ", sessao->getIdPeca().getValor().c_str());
            mvprintw(linha/8+12,coluna/4,"%s","Digite algo para continuar");
            getch();                                                                           // L� caracter digitado.
            break;
        case 1:
            mvprintw(linha/4,coluna/4,"%s","Falha ao visualizar Sessao. Muito provavelmente nao foi encontrada ocorrencia para Codigo informado. Digite algo.");                        // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            break;
    }
}
//Salas
void CntrApresentacaoPSS::incluirSala(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Sala sala;
    Codigo codigo;
    Nome nome;
    Capacidade capacidade;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo : ");
            getstr(campo1);
            codigo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Nome : ");
            getstr(campo1);
            nome.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite a Capacidade : ");
            getstr(campo1);
            capacidade.setValor(campo1);

            sala.setCodigo(codigo);
            sala.setNome(nome);
            sala.setCapacidade(capacidade);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->incluirSala(sala);
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Sala incluida com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
            mvprintw(linha/4 -3,coluna/4,"%s","Falha na inclusao. Muito provavelmente ja existe Sala com esse codigo. Digite algo.");
            noecho();
            getch();
            echo();
            break;
    }
}
void CntrApresentacaoPSS::editarSala(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Sala sala;
    Codigo codigo;
    Nome nome;
    Capacidade capacidade;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
            codigo.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Nome : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
            nome.setValor(campo1);

            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite a Capacidade : ");
            getstr(campo1);
            if(strcmp(campo1, "")!=0)
            capacidade.setValor(campo1);

            sala.setCodigo(codigo);
            sala.setNome(nome);
            if(strcmp(campo1, "")!=0)
            sala.setCapacidade(capacidade);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->editarSala(sala);
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Sala editada com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
            mvprintw(linha/4 -3,coluna/4,"%s","Falha ao editar Sala. Digite algo.");
            noecho();
            getch();
            echo();
            break;
    }
}
void CntrApresentacaoPSS::excluirSala(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Codigo codigo;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Sala a excluir : ");
            getstr(campo1);
            codigo.setValor(campo1);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->excluirSala(codigo);
    switch(resultado){
        case 0:
            mvprintw(linha/4,coluna/4,"%s","Sala excluida com sucesso. Digite algo.");
            noecho();
            getch();
            echo();
            break;
        case 1:
            mvprintw(linha/4,coluna/4,"%s","Falha ao excluir Sala. Muito provavelmente nao foi encontrada ocorrencia para Codigo informado. Digite algo.");
            noecho();
            getch();
            echo();
            break;
    }
}
void CntrApresentacaoPSS::visualizarSala(){
    char campo1[80];
    int linha,coluna;                                                                           // Dados sobre tamanho da tela.
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    Sala *sala = new Sala;
    Codigo codigo;
    while(true) {
        try {
            clear();                                                                                // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Digite o Codigo da Sala a visualizar : ");
            getstr(campo1);
            codigo.setValor(campo1);

            break;
        }
        catch (const invalid_argument &exp) {
            clear();                                                                            // Limpa janela.
            mvprintw(linha/4,coluna/4,"%s","Dado em formato incorreto. Digite algo.");                                             // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            // Tratamento de exce��o
        }
    }

    clear();
    int resultado = cntrServicoPSS->visualizarSala(codigo,sala);
    switch(resultado){
        case 0:
            mvprintw(linha/8+2,coluna/4,"%s %s","Codigo : ", sala->getCodigo().getValor().c_str());
            mvprintw(linha/8+4,coluna/4,"%s %s","Nome : ", sala->getNome().getValor().c_str());
            mvprintw(linha/8+6,coluna/4,"%s %s","Capacidade: ", sala->getCapacidade().getValor().c_str());
            mvprintw(linha/8+8,coluna/4,"%s","Digite algo para continuar");
            getch();                                                                            // L� caracter digitado.
            break;
        case 1:
            mvprintw(linha/4,coluna/4,"%s","Falha ao visualizar Sala. Muito provavelmente nao foi encontrada ocorrencia para Codigo informado. Digite algo.");                        // Informa formato incorreto.
            noecho();
            getch();                                                                            // L� caracter digitado.
            echo();
            break;
    }
}
//--------------------------- Public ----------------------------
void CntrApresentacaoPSS::executar(){
    int campo;
    int linha,coluna;
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    bool apresentar = true;
    while(apresentar){
        clear();
        mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos : ");                                                 // Imprime nome do camp
        mvprintw(linha/4 + 2,coluna/4,"%s","1 - Listar Pecas.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s","2 - Listar Sessoes.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s","3 - Listar Salas.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s","4 - Retornar.");                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();
        switch(campo){
            case 1:
                listarPecas();
                break;
            case 2:
                listarSessoes();
                break;
            case 3:
                listarSalas();
                break;
            case 4:
                apresentar = false;
                break;
        }
    }
}
void CntrApresentacaoPSS::executar(const Matricula&){
    int campo;
    int linha,coluna;
    getmaxyx(stdscr,linha,coluna);                                                              // Armazena quantidade de linhas e colunas.
    bool apresentar = true;
    bool apresentar0;
    while(apresentar){
        clear();
        mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos : ");                                                 // Imprime nome do campo.
        mvprintw(linha/4 + 2,coluna/4,"%s","1 - Listar Pecas.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 4,coluna/4,"%s","2 - Listar Sessoes.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 6,coluna/4,"%s","3 - Listar Salas.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 8,coluna/4,"%s","4 - Manusear Pecas.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 10,coluna/4,"%s","5 - Manusear Sessoes.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 12,coluna/4,"%s","6 - Manusear Salas.");                                             // Imprime nome do campo.
        mvprintw(linha/4 + 14,coluna/4,"%s","7 - Retornar.");                                             // Imprime nome do campo.
        noecho();
        campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
        echo();
        switch(campo){
            case 1:
                listarPecas();
                break;
            case 2:
                listarSessoes();
                break;
            case 3:
                listarSalas();
                break;
            case 4:
                apresentar0 = true;
                while(apresentar0){
                    clear();
                    mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos relacionados a pecas: ");                  // Imprime nome do campo.
                    mvprintw(linha/4 + 2,coluna/4,"%s","1 - Incluir.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 4,coluna/4,"%s","2 - Editar.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 6,coluna/4,"%s","3 - Excluir.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 8,coluna/4,"%s","4 - Visualizar.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 10,coluna/4,"%s","5 - Retornar.");                                             // Imprime nome do campo.
                    noecho();
                    campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
                    echo();
                    switch(campo){
                        case 1:
                            incluirPeca();
                            break;
                        case 2:
                            editarPeca();
                            break;
                        case 3:
                            excluirPeca();
                            break;
                        case 4:
                            visualizarPeca();
                            break;
                        case 5:
                            apresentar0 = false;
                            break;
                    }
                }
                break;
            case 5:
                apresentar0 = true;
                while(apresentar0){
                    clear();
                    mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos relacionados a sessoes: ");                  // Imprime nome do campo.
                    mvprintw(linha/4 + 2,coluna/4,"%s","1 - Incluir.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 4,coluna/4,"%s","2 - Editar.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 6,coluna/4,"%s","3 - Excluir.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 8,coluna/4,"%s","4 - Visualizar.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 10,coluna/4,"%s","5 - Retornar.");                                             // Imprime nome do campo.
                    noecho();
                    campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
                    echo();
                    switch(campo){
                        case 1:
                            incluirSessao();
                            break;
                        case 2:
                            editarSessao();
                            break;
                        case 3:
                            excluirSessao();
                            break;
                        case 4:
                            visualizarSessao();
                            break;
                        case 5:
                            apresentar0 = false;
                            break;
                    }
                }
                break;
            case 6:
                apresentar0 = true;
                while(apresentar0){
                    clear();
                    mvprintw(linha/4,coluna/4,"%s","Selecione um dos servicos relacionados a salas: ");                  // Imprime nome do campo.
                    mvprintw(linha/4 + 2,coluna/4,"%s","1 - Incluir.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 4,coluna/4,"%s","2 - Editar.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 6,coluna/4,"%s","3 - Excluir.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 8,coluna/4,"%s","4 - Visualizar.");                                             // Imprime nome do campo.
                    mvprintw(linha/4 + 10,coluna/4,"%s","5 - Retornar.");                                             // Imprime nome do campo.
                    noecho();
                    campo = getch() - 48;                                                                   // Leitura do campo de entrada e convers�o de ASCII.
                    echo();
                    switch(campo){
                        case 1:
                            incluirSala();
                            break;
                        case 2:
                            editarSala();
                            break;
                        case 3:
                            excluirSala();
                            break;
                        case 4:
                            visualizarSala();
                            break;
                        case 5:
                            apresentar0 = false;
                            break;
                    }
                }
                break;
            case 7:
                apresentar = false;
                break;
        }
    }
}
