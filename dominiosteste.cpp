#include "dominiosteste.h"
#include <stdexcept>
void TUCapacidade::setUp(){
    capacidade = new Capacidade();
    estado = SUCESSO;
}

void TUCapacidade::tearDown(){
    delete capacidade;
}

void TUCapacidade::testarCenarioSucesso(){
    try{
        capacidade->setQuantidade(VALOR_VALIDO);
        if (capacidade->getQuantidade() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCapacidade::testarCenarioFalha(){
    try{
        capacidade->setQuantidade(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        if (capacidade->getQuantidade() == VALOR_INVALIDO)
            estado = FALHA;
    }
}
int TUCapacidade::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUCargo::setUp(){
    cargo = new Cargo();
    estado = SUCESSO;
}

void TUCargo::tearDown(){
    delete cargo;
}

void TUCargo::testarCenarioSucesso(){
    try{
        cargo->setTitulo(VALOR_VALIDO);
        if (cargo->getTitulo() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCargo::testarCenarioFalha(){
    try{
        cargo->setTitulo(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        if (cargo->getTitulo() == VALOR_INVALIDO)
            estado = FALHA;
    }
}
int TUCargo::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


void TUTipo::setUp(){
    tipo = new Tipo();
    estado = SUCESSO;
}

void TUTipo::tearDown(){
    delete tipo;
}

void TUTipo::testarCenarioSucesso(){
    try{
        tipo->setGenero(VALOR_VALIDO);
        if (tipo->getGenero() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUTipo::testarCenarioFalha(){
    try{
        tipo->setGenero(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        if (tipo->getGenero() == VALOR_INVALIDO)
            estado = FALHA;
    }
}
int TUTipo::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}



void TUClassificacao::setUp(){
    classificao = new Classificacao();
    estado = SUCESSO;
}

void TUClassificacao::tearDown(){
    delete classificao;
}

void TUClassificacao::testarCenarioSucesso(){
    try{
        classificao->setIdade(VALOR_VALIDO);
        if (classificao->getIdade() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUClassificacao::testarCenarioFalha(){
    try{
        classificao->setIdade(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        if (classificao->getIdade() == VALOR_INVALIDO)
            estado = FALHA;
    }
}
int TUClassificacao::run(){
 setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


void TUMatricula::setUp(){
     matricula = new Matricula();
    estado = SUCESSO;
}

void TUMatricula::tearDown(){
    delete matricula;
}

void TUMatricula::testarCenarioSucesso(){
    try{
        matricula->setRegistro(VALOR_VALIDO);
        if (matricula->getRegistro() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUMatricula::testarCenarioFalha(){
    try{
        matricula->setRegistro(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        if (matricula->getRegistro() == VALOR_INVALIDO)
            estado = FALHA;
    }
}
int TUMatricula::run(){
 setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


void TUSenha::setUp(){
     senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioSucesso(){
    try{
        senha->setEntrada(VALOR_VALIDO);
        if (senha->getEntrada() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUSenha::testarCenarioFalha(){
    try{
        senha->setEntrada(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        if (senha->getEntrada() == VALOR_INVALIDO)
            estado = FALHA;
    }
}
int TUSenha::run(){
 setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

