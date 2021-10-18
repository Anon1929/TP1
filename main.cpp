#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "unidadepersistencia.h"
#include "interfaces.h"
#include "controladoresapresentacao.h"
#include "controladoresservico.h"
using namespace std;

int main(void){
    //Instanciar controladores de apresentação
    CntrApresentacaoControle cntrApresentacaoControle;
    CntrApresentacaoAutenticacao cntrApresentacaoAutenticacao;
    CntrApresentacaoParticipante cntrApresentacaoParticipante;
    CntrApresentacaoPSS cntrApresentacaoPSS;

    //instranciar controladores de serviço
    CntrServicoAutenticacao cntrServicoAutenticacao;
    CntrServicoParticipante cntrServicoParticipante;
    CntrServicoPSS cntrServicoPSS;
    //Interligar
    //Autenticação
    cntrApresentacaoControle.setCntrApresentacaoAutenticacao(&cntrApresentacaoAutenticacao);
    cntrApresentacaoAutenticacao.setCntrServicoAutenticacao(&cntrServicoAutenticacao);
    //Participante
    cntrApresentacaoControle.setCntrApresentacaoParticipante(&cntrApresentacaoParticipante);
    cntrApresentacaoParticipante.setCntrServicoParticipante(&cntrServicoParticipante);
    //Peça Sessão Sala
    cntrApresentacaoControle.setCntrApresentacaoPSS(&cntrApresentacaoPSS);
    cntrApresentacaoPSS.setCntrServicoPSS(&cntrServicoPSS);

    initscr();

    cntrApresentacaoControle.executar();
    endwin();

    cout << "obrigado por usar o programa!" << endl;
    return 0;

    /* //Exemplo de cadastro
    Participante participante;
    Matricula matricula("12345");
    participante.setMatricula(matricula);
    Nome nome("Marcelo");
    participante.setNome(nome);
    Nome sobrenome("Junqueira");
    participante.setSobrenome(sobrenome);
    Email email("marcelojunqueiraf@gmail.com");
    participante.setEmail(email);
    Senha senha("ABC123#$");
    Telefone telefone("(61)-998395011");
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    Cargo cargo("ator");
    participante.setCargo(cargo);

    ComandoCadastrar cadastrar(participante);

    if (cadastrar.executar()==0){
        cout << "sucesso" << endl;
    }else {
        cout << "falha" << endl;
    }

    */

}
