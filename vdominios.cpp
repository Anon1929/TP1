#include "vdominios.h"
void Capacidade::validar(int argumento){
    bool valido = false;
    if (argumento==100 || argumento ==200 || argumento == 300 || argumento == 400 || argumento == 500){
        valido = true;
    }
    else
        valido = false;
    if (!valido)
        throw std::invalid_argument("Argumento invalido");
    }
void Capacidade::setQuantidade(int quantidade){
    validar(quantidade);
    this->quantidade = quantidade;
}
Capacidade::Capacidade(){
    quantidade = DEFAULT;
}
Capacidade::Capacidade(int quantidade){
    validar(quantidade);
    this->quantidade = quantidade;
}
