#include "vdominios.h"

void Capacidade::validar(int argumento){
    bool valido;
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

void Cargo::validar(std::string titulo){
    bool valido;
    if (titulo=="ator"||titulo=="cenógrafo"||titulo=="figurinista"||titulo=="maquiador"||titulo=="sonoplasta"||titulo=="iluminador")
        valido=true;
    else
        valido=false;
    if (!valido)
        throw std::invalid_argument("Argumento invalido");
}
Cargo::Cargo(){
    titulo = "ator";
}
Cargo::Cargo(std::string titulo){
    validar(titulo);
    this->titulo = titulo;
}
void Cargo::setTitulo(std::string titulo){
    validar(titulo);
    this->titulo = titulo;
}

void Tipo::validar(std::string genero){
    bool valido;
    if (genero=="auto"||genero=="comédia"||genero=="drama"||genero=="farsa"||genero=="melodrama"||genero=="monólogo"||genero=="musical"||genero=="ópera"||genero=="revista")
        valido=true;
    else
        valido=false;
    if (!valido)
        throw std::invalid_argument("Argumento invalido");

}

Tipo::Tipo(){
    genero = "auto";
}

Tipo::Tipo(std::string genero){
    validar(genero);
    this->genero = genero;
}

void Tipo::setGenero(std::string genero){
    validar(genero);
    this->genero = genero;
}

void Classificacao::validar(std::string idade){
    bool valido;
    if (idade=="livre"||idade=="10"||idade=="12"||idade=="14"||idade=="16"||idade=="18")
        valido=true;
    else
        valido=false;
    if (!valido)
        throw std::invalid_argument("Argumento invalido");
}
Classificacao::Classificacao(){
    idade = "auto";
}

Classificacao::Classificacao(std::string idade){
    validar(idade);
    this->idade = idade;
}

void Classificacao::setIdade(std::string idade){
    validar(idade);
    this->idade = idade;
}

