#include "entidadesteste.h"
#include <iostream>
void TUPeca::setUp(){
    peca = new Peca();
    estado = SUCESSO;
}

void TUPeca::tearDown(){
    delete peca;
}

void TUPeca::testarCenarioSucesso(){

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

int TUPeca::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

//TUParticipante
void TUParticipante::setUp(){
    participante = new Participante();
    estado = SUCESSO;
}

void TUParticipante::tearDown(){
    delete participante;
}

void TUParticipante::testarCenarioSucesso(){
    Matricula matricula;
    matricula.setRegistro(MATRICULAVALIDA);
    participante->setMatricula(matricula);
    if(participante->getMatricula().getRegistro() != MATRICULAVALIDA)
        estado = FALHA;

    Nome nome;
    nome.setValor(NOMEVALIDO);
    participante->setNome(nome);
    if(participante->getNome().getValor() != NOMEVALIDO)
        estado = FALHA;

    Nome sobrenome;
    sobrenome.setValor(SOBRENOMEVALIDO);
    participante->setSobrenome(sobrenome);
    if(participante->getSobrenome().getValor() != SOBRENOMEVALIDO)
        estado = FALHA;

    Email email;
    email.setValor(EMAILVALIDO);
    participante->setEmail(email);
    if(participante->getEmail().getValor() != EMAILVALIDO)
        estado = FALHA;

    Senha senha;
    senha.setEntrada(SENHAVALIDA);
    participante->setSenha(senha);
    if(participante->getSenha().getEntrada() != SENHAVALIDA)
        estado = FALHA;

    Cargo cargo;
    cargo.setTitulo(CARGOVALIDO);
    participante->setCargo(cargo);
    if(participante->getCargo().getTitulo() != CARGOVALIDO)
        estado = FALHA;
}

int TUParticipante::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}


void TUSessao::setUp(){
    sessao = new Sessao();
    estado = SUCESSO;
}

void TUSessao::tearDown(){
    delete sessao;
}

void TUSessao::testarCenarioSucesso(){

    Codigo codigo;
    codigo.setEntrada(CODIGOVALIDO);
    sessao->setCodigo(codigo);
    if(sessao->getCodigo().getEntrada() != CODIGOVALIDO)
        estado = FALHA;

    Data data;
    data.setValor(DATAVALIDA);
    sessao->setData(data);
    if(sessao->getData().getValor() != DATAVALIDA)
        estado = FALHA;

    Horario horario;
    horario.setEntrada(HORARIOVALIDO);
    sessao->setHorario(horario);
    if(sessao->getHorario().getEntrada() != HORARIOVALIDO)
        estado = FALHA;
}
