#ifndef VDOMINIOSH
#define VDOMINIOSH
#include <string>
#include <stdexcept>
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
///Inicializa objeto com entrada igual a "ABC123@#$"

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

#endif
