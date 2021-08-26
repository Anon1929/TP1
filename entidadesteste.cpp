#include "entidadesteste.h"

void TUPeça::setUp(){
    peca = new Peça();
    estado = SUCESSO;
}

void TUPeça::tearDown(){
    delete peca;
}

void TUPeça::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setEntrada(CODIGOVALIDO);
    peca->setCodigo(codigo);
    if(peca->getCodigo().getEntrada() != CODIGOVALIDO)
        estado = FALHA;
    Nome nome;
    nome.setValor(NOMEVALIDO);
    peca->setNome(nome);
    if(peca->getNome().getValor() != NOMEVALIDO)
        estado = FALHA;
    Tipo tipo;
    tipo.setGenero(TIPOVALIDO);
    peca->setTipo(tipo);
    if(peca->getTipo().getGenero() != TIPOVALIDO)
        estado = FALHA;
    Classificacao classificacao;
    classificacao.setIdade(CLASSICACAOVALIDA);
    peca->setClassificacao(classificacao);
    if(peca->getClassificacao().getIdade() != CLASSICACAOVALIDA)
        estado = FALHA;
}

int TUPeça::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
