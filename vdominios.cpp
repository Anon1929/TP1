#include "vdominios.h"
#include <set>
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
    quantidade = 100;
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

void Matricula::validar(std::string registro){
    if(registro.size()!= 5)
        throw std::invalid_argument("Argumento inválido, tamanho errado");
    std::set<char> verificar;
    for(char c : registro){
        if(!isdigit(c))
           throw std::invalid_argument("Argumento inválido, não numero");
        verificar.insert(c);
    }
    if(verificar.size()!=registro.size())
        throw std::invalid_argument("Argumento inválido, número repetido");
}
void Matricula::setRegistro(std::string registro){
    validar(registro);
    this->registro = registro;
}
Matricula::Matricula(){
    registro = "00000";
}
Matricula::Matricula(std::string registro){
    validar(registro);
    this->registro = registro;
}

void Senha::validar(std::string entrada){

    if(entrada.size()!=8)
        throw std::invalid_argument("Argumento inválido, tamanho errado");
    std::set<char> verificar;
    bool minimo[3] ={false, false, false};
    for(char c: entrada){
        if (isdigit(c))
            minimo[0] = true;
        else if (islower(c)||isupper(c))
            minimo[1] = true;
        else if (c=='!'||c=='@'||c=='#'||c=='$'||c=='%'||c=='&'||c=='?')
            minimo[2] = true;
        else
            throw std::invalid_argument("Argumento inválido, caracter não permitido");
        verificar.insert(c);
    }
    if(verificar.size()!=entrada.size())
        throw std::invalid_argument("Argumento inválido, caracter repetido");
    if(!(minimo[0] && minimo[1] && minimo[2]))
        throw std::invalid_argument("Argumento inválido, não cumpre com o mínimo");
}

void Senha::setEntrada(std::string entrada){
    validar(entrada);
    this->entrada = entrada;
}

Senha::Senha(std::string entrada){
    validar(entrada);
    this->entrada = entrada;
}

Senha::Senha(){
    entrada = "ABC123#$";
}
