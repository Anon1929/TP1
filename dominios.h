#ifndef DOMINIOSH
#define DOMINIOSH
#include <string>
#include <stdexcept>
/// Matrícula aluno 200028545
/// Padrão para representação de Capacadidade de entidade Sala
/// Regras de formato :
/// quantidade válida caso 100,200,300, 400 ou 500
class Capacidade {

    private:
        int quantidade;
        void validar(int argumento);
        public:

/// Inicializa objeto com  quantidade 100.

        Capacidade();

/// Inicializa objeto com quantidade informada caso seja válida
/// Lança exceção caso valor seja inválido
/// @param quantidade capacidade
/// @throw invalid_argument

        Capacidade(int quantidade);

/// Armazena quantidade caso valor informado seja válido
/// Lança exceção caso valor seja inválido
/// @param quantidade capacidade
/// @throw invalid_argument

        void setQuantidade(int quantidade);

/// Retorna quantidade
/// @return quantidade

        int getQuantidade();

    };
inline int Capacidade::getQuantidade(){
    return quantidade;
    }

/// Matrícula aluno 200028545
/// Padrão para representação de Cargo de entidade Particidade
/// Regras de formato :
/// titulo válido caso ator, cenógrafo,figurinista, maquiador, sonoplasta, iluminador
class Cargo{
    private:
        std::string titulo;
        void validar(std::string argumento);
    public:

/// Inicializa objeto com titulo igual a ator

        Cargo();

/// Inicializa objeto com titulo informado caso seja válido
/// Lança exceção caso titulo seja inválido
/// @param titulo cargo
/// @throw invalid_argument

        Cargo(std::string titulo);

/// Armazena titulo informado caso seja válido
/// Lança exceção caso titulo seja inválido
/// @param titulo cargo
/// @throw invalid_argument

        void setTitulo(std::string titulo);

/// Retorna titulo
/// @return titulo

        std::string getTitulo();
};
inline std::string Cargo::getTitulo(){
    return titulo;
}

/// Matrícula aluno 200028545
/// Padrão para representação de tipo de entidade Peça
/// Regras de formato :
/// titulo válido caso auto, comédia, drama, farsa, melodrama, monólogo, musical, ópera, revista

class Tipo{
    private:
        std::string genero;
        void validar(std::string argumento);

    public:

/// Inicializa objeto com genero igual a auto

        Tipo();

/// Inicializa objeto com genero informado caso seja válido
/// Lança exceção caso genero seja inválido
/// @param genero cargo
/// @throw invalid_argument

        Tipo(std::string genero);

/// Armazena genero informado caso seja válido
/// Lança exceção caso genero seja inválido
/// @param genero cargo
/// @throw invalid_argument

        void setGenero(std::string genero);

/// Retorna genero
/// @return genero

        std::string getGenero();
};

inline std::string Tipo::getGenero(){
    return genero;
}

/// Matrícula aluno 200028545
/// Padrão para representação de Classificação de entidade Peça
/// Regras de formato :
/// titulo válido caso livre, 10, 12, 14, 16, 18
class Classificacao{
    private:
        std::string idade;
        void validar(std::string idade);

    public:

/// Inicializa objeto com idade igual a livre

        Classificacao();

/// Inicializa objeto com idade informada caso seja válida
/// Lança exceção caso genero seja inválida
/// @param idade calssificação
/// @throw invalid_argument

        Classificacao(std::string idade);

/// Armazena idade informada caso seja válida
/// Lança exceção caso genero seja inválida
/// @param idade calssificação
/// @throw invalid_argument

        void setIdade(std::string idade);

/// Retorna idade
/// @return idade

        std::string getIdade();
};

inline std::string Classificacao::getIdade(){
    return idade;
}

/// Matrícula aluno 200028545
/// Padrão para representação de Matricula de entidade Participante
/// Regras de formato :
/// Formato XXXXX
/// Cada X é dígito (0-9)
/// Não há dígitos duplicados
class Matricula{
private:
    std::string registro;
    void validar(std::string registro);
public:
///Inicializa objeto com registro igual a "00000"

    Matricula();

///Inicializa objeto com registro dado caso seja válido
///@param registro Matricula

    Matricula(std::string registro);

///Modifica registro dado caso seja válido
///@param registro Matricula

    void setRegistro(std::string registro);

///Retorna registro
///@return registro

    std::string getRegistro();
};
inline std::string Matricula::getRegistro(){
    return registro;
}

/// Matrícula aluno 200028545
/// Padrão para representação de Senha de entidade Participante
/// Regras de formato :
/// Formato XXXXXXXX.
/// Cada X é letra (A-Z ou a-z), dígito(0-9) ou caracter especial.
/// São possíveis os caracteres especiais ! @ # $ % & ?.
/// Não existe caracter repetido.
/// Existe pelo menos uma letra (maiúscula ou minúscula), um dígito e um caracter especial.
class Senha{
private:
    std::string entrada;
    void validar(std::string entrada);
public:
///Inicializa objeto com entrada igual a "ABC123#$"
    Senha();

///Inicializa objeto com entrada dada caso seja válida
///@param entrada Senha

    Senha(std::string entrada);

///Modifica entrada dado caso seja válido
///@param entrada Senha

    void setEntrada(std::string entrada);

///Retorna entrada
///@return entrada

    std::string getEntrada();
};

inline std::string Senha::getEntrada(){
    return entrada;
}

/// Matrícula: 200016750
/// Padrão para representação de Telefone de entidade Participante
/// Regras de formato:
/// Formato (XX)-YYYYYYYYY.
/// XX é um dos seguintes códigos 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33, 34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99.
/// Cada Y é dígito (0-9).
/// Não existe número de telefone 000000000.
class Telefone{
private:
    std::string entrada;
    void validar(std::string entrada);

public:
/// Inicializa objeto com entrada igual a "(11)-000000001"
    Telefone();

/// Inicializa objeto com entrada dada caso seja válida
/// @param entrada Telefone
    Telefone(std::string entrada);

/// Modifica entrada dada caso seja válida
/// @param entrada Telefone
    void setEntrada(std::string entrada);

/// Retorna entrada
/// @return entrada
    std::string getEntrada();
};

inline std::string Telefone::getEntrada(){
    return entrada;
}

///Matricula: 200023624
///Padrão para representação de Nome
///Regras de formato:
///5 a 20 caracteres
///Cada caracter é letra, ponto ou espaco em branco
///Ponto e precedido por letra
///nao ha espacos em branco em sequencia
///primeira letra de cada termo maiuscula
class Nome {
    private:
        std::string valor;                      // Atributo para armazenar valor.
        void validar(std::string);              // Método para validar valor.
    public:
    ///Inicializa objeto com valor padrão "Nome Padrao"
        Nome();
    ///Inicializa objeto com entrada dada caso seja valida
    ///@param nome
        Nome(std::string);
    ///Modifica valor de nome caso entrada seja valida
    ///@param nome
        void setValor(std::string);             // Método para atribuir valor.
    ///retorna valor de nome
    ///@return nome
        std::string getValor() const;           // Método para recuperar valor.
};

inline std::string Nome::getValor() const{
    return valor;
}

///Matricula: 200023624
///Padrão para representação de Email
///Regras de formato:
///Formato parte-local@domínio
///parte-local é composta por até 64 caracteres.
///domínio é composto por até 255 caracteres.
///Caractere pode ser letra maiúscula (A-Z) ou letra minúscula (a-z).
///Caractere pode ser dígito (0-9).
///Caractere pode ser ! # $ % & ' * + - / = ? ^ _ ` { | } ~
///Caracere pode ser ponto (.) desde que não seja o primeiro ou o último caractere e que não ocorra em sequência.
class Email {
    private:
        std::string valor;                      // Atributo para armazenar valor.
        void validar(std::string);              // Método para validar valor.
    public:
    ///Inicializa objeto com valor padrão teste@email.com
        Email();

    ///Inicializa objeto com entrada dada caso seja valida
    ///@param email
        Email(std::string);
    ///Modifica valor de email caso entrada seja valida
    ///@param email
        void setValor(std::string);             // Método para atribuir valor.
    ///retorna valor de email
    ///@return email
        std::string getValor() const;           // Método para recuperar valor.
};

inline std::string Email::getValor() const{
    return valor;
}

///Matricula: 200023624
///Padrão para representação de Data
///Regras de formato:
///Formato DD/MM/AAAA
///01 a 31 em DD.
///01 e 12 em MM.
///2000 a 9999 em AAAA.
///Data considera a ocorrência de anos bissextos.
class Data {
    private:
        std::string valor;                      // Atributo para armazenar valor.
        void validar(std::string);              // Método para validar valor.
    public:
    ///Inicializa data com valor "13/03/2002"
        Data();

    ///Inicializa objeto com entrada dada caso seja valida
    ///@param data
        Data(std::string);
    ///Modifica valor de data caso entrada seja valida
    ///@param data
        void setValor(std::string);             // Método para atribuir valor.
    ///retorna valor de data
    ///@return data
        std::string getValor() const;           // Método para recuperar valor.
};

inline std::string Data::getValor() const{
    return valor;
}

/// Matrícula: 200016750
/// Padrão para representação de Código
/// Regras de formato:
/// Formato LLDDDD.
/// Cada L é letra maiúscula (A-Z).
/// Cada D é dígito (0-9).
class Codigo{
private:
    std::string entrada;
    void validar(std::string entrada);

public:
/// Inicializa objeto com entrada igual a "AA0000"
    Codigo();

/// Inicializa objeto com entrada dada caso seja válida
/// @param entrada Codigo
    Codigo(std::string entrada);

/// Modifica entrada dada caso seja válida
/// @param entrada Codigo
    void setEntrada(std::string entrada);

/// Retorna entrada
/// @return entrada
    std::string getEntrada();
};

inline std::string Codigo::getEntrada(){
    return entrada;
}

/// Matrícula: 200016750
/// Padrão para representação de Horário de entidade Sessão
/// Regras de formato:
/// HH:MM.
/// Em HH tem-se indicação de horário: 00 a 23
/// Em MM tem-se indicação de minuto: 00, 15, 30, 45
class Horario{
private:
    std::string entrada;
    void validar(std::string entrada);

public:
/// Inicializa objeto com entrada igual a "00:00"
    Horario();

/// Inicializa objeto com entrada dada caso seja válida
/// @param entrada Horario
    Horario(std::string entrada);

/// Modifica entrada dada caso seja válida
/// @param entrada Horario
    void setEntrada(std::string entrada);

/// Retorna entrada
/// @return entrada
    std::string getEntrada();
};

inline std::string Horario::getEntrada(){
    return entrada;
}

#endif
