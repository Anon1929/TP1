#include "dominios.h"
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>

Capacidade::Capacidade(){
    valor = "";
}

void Capacidade::validar(std::string valor){
    bool valido;
    valido = (valor == "100" || valor == "200" || valor == "300" || valor == "400" || valor == "500");

    valido = true;
    if (!valido)
        throw std::invalid_argument("Argumento invalido");
    }

void Capacidade::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}

Capacidade::Capacidade(std::string valor){
    validar(valor);
    this->valor = valor;
}

//Cargo
Cargo::Cargo(){
    valor = "";
}

void Cargo::validar(std::string valor){
    bool valido;
    if (valor=="ator"||valor=="cenógrafo"||valor=="figurinista"||valor=="maquiador"||valor=="sonoplasta"||valor=="iluminador")
        valido=true;
    else
        valido=false;
    if (!valido)
        throw std::invalid_argument("Argumento invalido");
}
Cargo::Cargo(std::string valor){
    validar(valor);
    this->valor = valor;
}
void Cargo::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}


//Tipo
Tipo::Tipo(){
    valor = "";
}
void Tipo::validar(std::string valor){
    bool valido;
    if (valor=="auto"||valor=="comédia"||valor=="drama"||valor=="farsa"||valor=="melodrama"||valor=="monólogo"||valor=="musical"||valor=="ópera"||valor=="revista")
        valido=true;
    else
        valido=false;
    if (!valido)
        throw std::invalid_argument("Argumento invalido");

}

Tipo::Tipo(std::string valor){
    validar(valor);
    this->valor = valor;
}

void Tipo::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}


//Classificação
Classificacao::Classificacao(){
    valor = "";
}
void Classificacao::validar(std::string valor){
    bool valido;
    if (valor=="livre"||valor=="10"||valor=="12"||valor=="14"||valor=="16"||valor=="18")
        valido=true;
    else
        valido=false;
    if (!valido)
        throw std::invalid_argument("Argumento invalido");
}
Classificacao::Classificacao(std::string valor){
    validar(valor);
    this->valor = valor;
}

void Classificacao::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}
//Matricula
Matricula::Matricula(){
    valor = "";
}
void Matricula::validar(std::string valor){
    if(valor.size()!= 5){
        throw std::invalid_argument("Argumento inválido, tamanho errado matricula");
    }
    std::set<char> verificar;
    for(char c : valor){
        if(!isdigit(c))
           throw std::invalid_argument("Argumento inválido, não numero");
        verificar.insert(c);
    }
    if(verificar.size()!=valor.size())
        throw std::invalid_argument("Argumento inválido, número repetido");
}
void Matricula::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}
Matricula::Matricula(std::string valor){
    validar(valor);
    this->valor = valor;
}

//Senha
Senha::Senha(){
    valor = "";
}

void Senha::validar(std::string valor){
    if(valor.size()!=8)
        throw std::invalid_argument("Argumento inválido, tamanho errado senha");
    std::set<char> verificar;
    bool minimo[3] ={false, false, false};
    for(char c: valor){
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
    if(verificar.size()!=valor.size())
        throw std::invalid_argument("Argumento inválido, caracter repetido");
    if(!(minimo[0] && minimo[1] && minimo[2]))
        throw std::invalid_argument("Argumento inválido, não cumpre com o mínimo");
}

void Senha::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}

Senha::Senha(std::string valor){
    validar(valor);
    this->valor = valor;
}

//Telefone
Telefone::Telefone(){
    valor = "";
}

void Telefone::validar(std::string valor) {
    if(valor.size() != 14)
        throw std::invalid_argument("Argumento invalido, tamanho incorreto.");

    std::string specialchars, digits;
    std::vector<char> ddd;
    for (unsigned i; i < valor.size(); i++) {
        if (i == 0 || i == 3 || i == 4)
            specialchars.push_back(valor.at(i));
        else if (i == 1 || i == 2)
            ddd.push_back(valor.at(i));
        else
            digits.push_back(valor.at(i));
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

Telefone::Telefone(std::string valor){
    setValor(valor);
}

void Telefone::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}

//Codigo
Codigo::Codigo(){
    valor = "";
}

void Codigo::validar(std::string valor) {
    if(valor.size() != 6)
        throw std::invalid_argument("Argumento invalido, tamanho incorreto.");

    std::string letters, digits;
    for (unsigned i; i < valor.size(); i++) {
        if (i == 0 || i == 1)
            letters.push_back(valor.at(i));
        else
            digits.push_back(valor.at(i));
    }

    if (!std::all_of(letters.begin(), letters.end(), ::isupper))
        throw std::invalid_argument("Argumento invalido, formato incorreto. Dois primeiros caracteres nao sao letras maiusculas.");
    else if (!std::all_of(digits.begin(), digits.end(), ::isdigit))
        throw std::invalid_argument("Argumento invalido, formato incorreto. Quatro ultimos caracteres nao sao numeros.");
}

Codigo::Codigo(std::string valor){
    setValor(valor);
}

void Codigo::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}

//Horario
Horario::Horario(){
    valor = "";
}

void Horario::validar(std::string valor) {
    if(valor.size() != 5)
        throw std::invalid_argument("Argumento invalido, tamanho incorreto.");

    std::string HH, MM;
    for (unsigned i; i < valor.size(); i++) {
        if (i == 0 || i == 1)
            HH.push_back(valor.at(i));
        else if (i == 2 && valor.at(i) != ':')
            throw std::invalid_argument("Argumento invalido, formato incorreto. Utilize \"HH:MM\".");
        else if (i != 2)
            MM.push_back(valor.at(i));
    }

    std::set<int> aceitar = {00, 15, 30, 45};
    if (!std::all_of(HH.begin(), HH.end(), ::isdigit) || !std::all_of(MM.begin(), MM.end(), ::isdigit))
        throw std::invalid_argument("Argumento invalido, formato incorreto. Hora e minutos devem ser apenas digitos.");
    else if (std::stoi(HH) > 23)
        throw std::invalid_argument("Argumento invalido. Hora tem que ser de 00 a 23.");
    else if (aceitar.find(std::stoi(MM)) == aceitar.end())
        throw std::invalid_argument("Argumento invalido, Minutos tem que ser 00, 15, 30 ou 45.");
}

Horario::Horario(std::string valor){
    setValor(valor);
}

void Horario::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}

//Nome
Nome::Nome(){
    valor = "";
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

//Email
Email::Email(){
    valor = "";
}

Email::Email(std::string valor){
    setValor(valor);
}

bool checkChar(char c){
    std::string validList = "!#$%&'*+-/=?^_`{|}~";
    for(char e : validList){
        if(c==e)
            return true;
    }
    return false;
}

void Email::validar(std::string valor){
    int tamanho = valor.length();
    int atPosition=-1;
    std::string validChars = "!#$%&'*+-/=?^_`{|}~";
    if(valor[tamanho-1]=='.')
        throw std::invalid_argument("Ponto (.) como último caracter");
    if(valor[0]=='.')
        throw std::invalid_argument("Ponto (.) como primeiro caracter");
    for(int i=0; i<tamanho; i++){
        if(valor[i]=='@')
            atPosition=i;
        else if(valor[i]=='.'){
            if(i>0 && valor[i-1]=='.')
                throw std::invalid_argument("Dois pontos (.) em sequencia ");
        }else if((valor[i]>='a' && valor[i]<='z') || (valor[i]>='A' && valor[i]<='Z')){
        }else if(valor[i]>='0' && valor[i]<='9'){
        }else if(checkChar(valor[i])){
        }else{
            throw std::invalid_argument("Caracter invalido");
        }
    }

    if(atPosition==-1)
        throw std::invalid_argument("Formato invalido");
    if(atPosition>64)
        throw std::invalid_argument("parte-local longa demais");
    if(tamanho-atPosition>256)
        throw std::invalid_argument("dominio longo demais");
}
void Email::setValor(std::string valor){
    validar(valor);
    this->valor = valor;
}

//Data
Data::Data(){
    valor = "";
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
