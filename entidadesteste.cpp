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
    codigo.setValor(CODIGOVALIDO);
    peca->setCodigo(codigo);
    if(peca->getCodigo().getValor() != CODIGOVALIDO)
        estado = FALHA;
    Nome nome;
    nome.setValor(NOMEVALIDO);
    peca->setNome(nome);
    if(peca->getNome().getValor() != NOMEVALIDO)
        estado = FALHA;
    Tipo tipo;
    tipo.setValor(TIPOVALIDO);
    peca->setTipo(tipo);
    if(peca->getTipo().getValor() != TIPOVALIDO)
        estado = FALHA;
    Classificacao classificacao;
    classificacao.setValor(CLASSICACAOVALIDA);
    peca->setClassificacao(classificacao);
    if(peca->getClassificacao().getValor() != CLASSICACAOVALIDA)
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
    matricula.setValor(MATRICULAVALIDA);
    participante->setMatricula(matricula);
    if(participante->getMatricula().getValor() != MATRICULAVALIDA)
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
    senha.setValor(SENHAVALIDA);
    participante->setSenha(senha);
    if(participante->getSenha().getValor() != SENHAVALIDA)
        estado = FALHA;

    Cargo cargo;
    cargo.setValor(CARGOVALIDO);
    participante->setCargo(cargo);
    if(participante->getCargo().getValor() != CARGOVALIDO)
        estado = FALHA;
}

int TUParticipante::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}


void TUSala::setUp(){
    sala = new Sala();
}

void TUSala::tearDown(){
    delete sala;
}

void TUSala::testarCenarioSucesso(){
    Codigo codigo;
    codigo.setValor(CODIGOVALIDO);
    estado = SUCESSO;
    sala->setCodigo(codigo);
    if(sala->getCodigo().getValor()!=codigo.getValor()){
        std::cout <<"A";
        estado=FALHA;
    }
    Nome nome;
    nome.setValor(NOMEVALIDO);
    sala->setNome(nome);
    if(sala->getNome().getValor()!=nome.getValor()){
        std::cout <<"B";
        estado=FALHA;
    }
    Capacidade capacidade;
    capacidade.setValor(CAPACIDADEVALIDA);
    sala->setCapacidade(capacidade);
    if(sala->getCapacidade().getValor()!=capacidade.getValor()){
        std::cout <<"C";
        estado=FALHA;
        }

}
int TUSala::run(){
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
    codigo.setValor(CODIGOVALIDO);
    sessao->setCodigo(codigo);
    if(sessao->getCodigo().getValor() != CODIGOVALIDO)
        estado = FALHA;

    Data data;
    data.setValor(DATAVALIDA);
    sessao->setData(data);
    if(sessao->getData().getValor() != DATAVALIDA)
        estado = FALHA;

    Horario horario;
    horario.setValor(HORARIOVALIDO);
    sessao->setHorario(horario);
    if(sessao->getHorario().getValor() != HORARIOVALIDO)
        estado = FALHA;
}
int TUSessao::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
