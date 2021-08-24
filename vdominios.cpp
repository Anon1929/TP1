#include "vdominios.h"
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

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

void Telefone::validar(std::string entrada) {
    if(entrada.size() != 14)
        throw std::invalid_argument("Argumento invalido, tamanho incorreto.");

    std::string specialchars, digits;
    std::vector<char> ddd;
    for (unsigned i; i < entrada.size(); i++) {
        if (i == 0 || i == 3 || i == 4)
            specialchars.push_back(entrada.at(i));
        else if (i == 1 || i == 2)
            ddd.push_back(entrada.at(i));
        else
            digits.push_back(entrada.at(i));
    }

    std::set<int> negar = {20, 23, 25, 26, 29, 30, 31, 36, 39, 40, 50, 52, 56, 57, 58, 59, 60, 70, 72, 76, 78, 80, 90}; // Todos os DDDs entre 11 e 99 que não são permitidos
    std::string dddstr; for (char c: ddd) {dddstr.push_back(c);}
    int dddint = 0; try {dddint = std::stoi(dddstr);} catch(...){}
    if (specialchars != "()-")
        throw std::invalid_argument("Argumento invalido, formato incorreto.");
    else if (!isdigit(ddd[0]) || !isdigit(ddd[1]) || negar.find(dddint) != negar.end() || dddint < 11)
        throw std::invalid_argument("Argumento invalido, DDD invalido.");
    else if (!std::all_of(digits.begin(), digits.end(), ::isdigit))
        throw std::invalid_argument("Argumento invalido, numero nao composto por digitos.");
    else if (digits == "000000000")
        throw std::invalid_argument("Argumento invalido, numero nao pode ser 000000000.");
}

Telefone::Telefone(){
    entrada = "(11)-000000001";
}

Telefone::Telefone(std::string entrada){
    setEntrada(entrada);
}

void Telefone::setEntrada(std::string entrada){
    validar(entrada);
    this->entrada = entrada;
}

void Codigo::validar(std::string entrada) {
    if(entrada.size() != 6)
        throw std::invalid_argument("Argumento invalido, tamanho incorreto.");

    std::string letters, digits;
    for (unsigned i; i < entrada.size(); i++) {
        if (i == 0 || i == 1)
            letters.push_back(entrada.at(i));
        else
            digits.push_back(entrada.at(i));
    }

    if (!std::all_of(letters.begin(), letters.end(), ::isupper))
        throw std::invalid_argument("Argumento invalido, formato incorreto. Dois primeiros caracteres nao sao letras maiusculas.");
    else if (!std::all_of(digits.begin(), digits.end(), ::isdigit))
        throw std::invalid_argument("Argumento invalido, formato incorreto. Quatro ultimos caracteres nao sao numeros.");
}

Codigo::Codigo(){
    entrada = "AA0000";
}

Codigo::Codigo(std::string entrada){
    setEntrada(entrada);
}

void Codigo::setEntrada(std::string entrada){
    validar(entrada);
    this->entrada = entrada;
}

void Horario::validar(std::string entrada) {
    if(entrada.size() != 5)
        throw std::invalid_argument("Argumento invalido, tamanho incorreto.");

    std::string HH, MM;
    for (unsigned i; i < entrada.size(); i++) {
        if (i == 0 || i == 1)
            HH.push_back(entrada.at(i));
        else if (i == 2 && entrada.at(i) != ':')
            throw std::invalid_argument("Argumento invalido, formato incorreto. Utilize \"HH:MM\".");
        else if (i != 2)
            MM.push_back(entrada.at(i));
    }

    std::set<int> aceitar = {00, 15, 30, 45};
    if (!std::all_of(HH.begin(), HH.end(), ::isdigit) || !std::all_of(MM.begin(), MM.end(), ::isdigit))
        throw std::invalid_argument("Argumento invalido, formato incorreto. Hora e minutos devem ser apenas digitos.");
    else if (std::stoi(HH) > 23)
        throw std::invalid_argument("Argumento invalido. Hora tem que ser de 00 a 23.");
    else if (aceitar.find(std::stoi(MM)) == aceitar.end())
        throw std::invalid_argument("Argumento invalido, Minutos tem que ser 00, 15, 30 ou 45.");
}

Horario::Horario(){
    entrada = "00:00";
}

Horario::Horario(std::string entrada){
    setEntrada(entrada);
}

void Horario::setEntrada(std::string entrada){
    validar(entrada);
    this->entrada = entrada;
}

Nome::Nome(std::string valor){
    setValor(valor);
}
void Nome::validar(std::string valor){
    int tamanho = valor.length();
    if(tamanho<5 || tamanho>20)
        throw std::invalid_argument("O nome deve conter de 5 e 20 caracteres");
    char anterior = ' ';
    for(char c : valor){
        if(anterior==' '){
            if(c==' ')
                throw std::invalid_argument("Nao podem haver dois espacos em sequencia");
            else if(c<'A' || c>'Z')
                throw std::invalid_argument("Todos os termos devem começar com letra maiuscula");
        }else{
            c = std::tolower(c);
            if((c>='a' && c<='z') || c==' '){
            }else if(c=='.'){
                if(anterior<'a' || anterior>'z') //Se anterior não é letra
                    throw std::invalid_argument("Ponto nao precedido de letra.");
            }else{
                std::cout << c << std::endl;
                throw std::invalid_argument("character invalido");
            }
        }
        anterior = c;
    }
}
void Nome::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}

Email::Email(std::string valor){
    setValor(valor);
}
void Email::validar(std::string valor){
    int tamanho = valor.length();

}
void Email::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}


Data::Data(std::string valor){
    setValor(valor);
}
void Data::validar(std::string valor){
    if(valor.length()!= 10 || valor[2]!='/' || valor[5]!='/')
        throw std::invalid_argument("Formato invalido");
    int dd = std::stoi(valor.substr(0, 2));
    if(dd<1 || dd>31)
        throw std::invalid_argument("dia invalido");
    int mm = std::stoi(valor.substr(3, 2));
    if(mm<1 || mm>12)
        throw std::invalid_argument("mes invalido");
    int aaaa = std::stoi(valor.substr(6, 4));
    if(aaaa<2000)
        throw std::invalid_argument("ano invalido");
}
void Data::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}


