
#ifndef DOMINIOSH
#define DOMINIOSH
#include <string>
#include <stdexcept>

/// Matrícula aluno 200028545
/// Padrão para representação de Capacadidade de entidade Sala
/// Regras de formato :
/// valor válida caso 100,200,300, 400 ou 500
class Capacidade {

    private:
        std::string  valor;
        void validar(std::string  argumento);
        public:

/// Inicializa objeto com  valor "".

        Capacidade();

/// Inicializa objeto com valor informada caso seja válida
/// Lança exceção caso valor seja inválido
/// @param valor capacidade
/// @throw invalid_argument

        Capacidade(std::string  valor);

/// Armazena valor caso valor informado seja válido
/// Lança exceção caso valor seja inválido
/// @param valor capacidade
/// @throw invalid_argument

        void setValor(std::string valor);

/// Retorna valor
/// @return valor

        std::string getValor() const;

    };
inline std::string Capacidade::getValor() const{
    return valor;
    }

/// Matrícula aluno 200028545
/// Padrão para representação de Cargo de entidade Particidade
/// Regras de formato :
/// valor válido caso ator, cenógrafo,figurinista, maquiador, sonoplasta, iluminador
class Cargo{
    private:
        std::string valor;
        void validar(std::string argumento);
    public:

/// Inicializa objeto com valor igual a ator

        Cargo();

/// Inicializa objeto com valor informado caso seja válido
/// Lança exceção caso valor seja inválido
/// @param valor cargo
/// @throw invalid_argument

        Cargo(std::string valor);

/// Armazena valor informado caso seja válido
/// Lança exceção caso valor seja inválido
/// @param valor cargo
/// @throw invalid_argument

        void setValor(std::string valor);

/// Retorna valor
/// @return valor

        std::string getValor() const;
};
inline std::string Cargo::getValor() const{
    return valor;
}

/// Matrícula aluno 200028545
/// Padrão para representação de tipo de entidade Peça
/// Regras de formato :
/// valor válido caso auto, comédia, drama, farsa, melodrama, monólogo, musical, ópera, revista
class Tipo{
    private:
        std::string valor;
        void validar(std::string argumento);

    public:

/// Inicializa objeto com valor igual a auto

        Tipo();

/// Inicializa objeto com valor informado caso seja válido
/// Lança exceção caso valor seja inválido
/// @param valor cargo
/// @throw invalid_argument

        Tipo(std::string valor);

/// Armazena valor informado caso seja válido
/// Lança exceção caso valor seja inválido
/// @param valor cargo
/// @throw invalid_argument

        void setValor(std::string valor);

/// Retorna valor
/// @return valor

        std::string getValor() const;
};
inline std::string Tipo::getValor() const{
    return valor;
}

/// Matrícula aluno 200028545
/// Padrão para representação de Classificação de entidade Peça
/// Regras de formato :
/// valor válido caso livre, 10, 12, 14, 16, 18
class Classificacao{
    private:
        std::string valor;
        void validar(std::string valor);

    public:

/// Inicializa objeto com valor igual a livre

        Classificacao();

/// Inicializa objeto com valor informada caso seja válida
/// Lança exceção caso valor seja inválida
/// @param valor calssificação
/// @throw invalid_argument

        Classificacao(std::string valor);

/// Armazena valor informada caso seja válida
/// Lança exceção caso valor seja inválida
/// @param valor calssificação
/// @throw invalid_argument

        void setValor(std::string valor);

/// Retorna valor
/// @return valor

        std::string getValor() const;
};
inline std::string Classificacao::getValor() const{
    return valor;
}

/// Matrícula aluno 200028545
/// Padrão para representação de Matricula de entidade Participante
/// Regras de formato :
/// Formato XXXXX
/// Cada X é dígito (0-9)
/// Não há dígitos duplicados
class Matricula{
private:
    std::string valor;
    void validar(std::string valor);
public:
///Inicializa objeto com valor igual a "00000"

    Matricula();

///Inicializa objeto com valor dado caso seja válido
///@param valor Matricula

    Matricula(std::string valor);

///Modifica valor dado caso seja válido
///@param valor Matricula

    void setValor(std::string valor);

///Retorna valor
///@return valor

    std::string getValor() const;
};
inline std::string Matricula::getValor() const{
    return valor;
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
    std::string valor;
    void validar(std::string valor);
public:
///Inicializa objeto com valor igual a "ABC123#$"
    Senha();

///Inicializa objeto com valor dada caso seja válida
///@param valor Senha

    Senha(std::string valor);

///Modifica valor dado caso seja válido
///@param valor Senha

    void setValor(std::string valor);

///Retorna valor
///@return valor

    std::string getValor() const;
};
inline std::string Senha::getValor() const{
    return valor;
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
    std::string valor;
    void validar(std::string valor);

public:
/// Inicializa objeto com valor igual a "(11)-000000001"
    Telefone();

/// Inicializa objeto com valor dada caso seja válida
/// @param valor Telefone
    Telefone(std::string valor);

/// Modifica valor dada caso seja válida
/// @param valor Telefone
    void setValor(std::string valor);

/// Retorna valor
/// @return valor
    std::string getValor() const;
};
inline std::string Telefone::getValor() const{
    return valor;
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
    std::string valor;
    void validar(std::string valor);

public:
/// Inicializa objeto com valor igual a "AA0000"
    Codigo();

/// Inicializa objeto com valor dada caso seja válida
/// @param valor Codigo
    Codigo(std::string valor);

/// Modifica valor dada caso seja válida
/// @param valor Codigo
    void setValor(std::string valor);

/// Retorna valor
/// @return valor
    std::string getValor() const;
};
inline std::string Codigo::getValor() const{
    return valor;
}

/// Matrícula: 200016750
/// Padrão para representação de Horário de entidade Sessão
/// Regras de formato:
/// HH:MM.
/// Em HH tem-se indicação de horário: 00 a 23
/// Em MM tem-se indicação de minuto: 00, 15, 30, 45
class Horario{
private:
    std::string valor;
    void validar(std::string valor);

public:
/// Inicializa objeto com valor igual a "00:00"
    Horario();

/// Inicializa objeto com valor dada caso seja válida
/// @param valor Horario
    Horario(std::string valor);

/// Modifica valor dada caso seja válida
/// @param valor Horario
    void setValor(std::string valor);

/// Retorna valor
/// @return valor
    std::string getValor() const;
};
inline std::string Horario::getValor() const{
    return valor;
}



#endif
