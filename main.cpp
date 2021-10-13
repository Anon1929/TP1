#include <iostream>
#include "dominios.h"
#include "dominiosteste.h"
#include "entidades.h"
#include "entidadesteste.h"
#include "controladoresapresentacao.h"
#include "controladoresservico.h"
int main(void){
    CntrApresentacaoControle ControleApresentacao;

    IApresentacaoAutenticacao *cntrapresentacaoautenticacao;
    IApresentacaoParticipante *cntrapresentacaoparticipante;
    IApresentacaoPSS *cntrapresentacaopps;

    cntrapresentacaoautenticacao = new CntrApresentacaoAutenticacao();

    ControleApresentacao.setCntrApresentacaoAutenticacao(cntrapresentacaoautenticacao);

    initscr();
    ControleApresentacao.executar();
    endwin();

    return 0;
}
