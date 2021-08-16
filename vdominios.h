#ifndef VDOMINIOSH
#define VDOMINIOSH

/// Capacidade
/// Regras de formato :
/// Quantidade válida caso 100,200,300, 400 ou 500
class Capacidade {

    private:
        int quantidade;
        void validar(int argumento);
    public:

/// Inicializa objeto com  quantidade 100.
///
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

class Cargo{
private:
    std::string titulo;
    void validar(std::string argumento)
public:
    void setTitulo(std::string titulo);
    std::string getTitulo();
};
inline std::string Cargo::getTitulo(){
    return titulo
}

class Tipo{
private:
    std::string genero;
    void validar(std::string argumento)

public:
    void setGenero(std::string genero);
    std::string getGenero();
};

inline std::string Tipo::getGenero(){
    return genero
}
#endif
