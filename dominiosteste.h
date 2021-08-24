#include "vdominios.h"
#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED
// Matrícula aluno 200028545
class TUCapacidade {
private:
    const static int VALOR_VALIDO   = 100;   // Definição de constante para evitar número mágico.
    const static int VALOR_INVALIDO = 30;   // Definição de constante para evitar número mágico.
    Capacidade *capacidade;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};
// Matrícula aluno 200028545
class TUCargo {
    private:
    inline static const std::string VALOR_VALIDO = "figurinista";
    inline static const std::string VALOR_INVALIDO = "erro";
    Cargo *cargo;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};
// Matrícula aluno 200028545
class TUTipo {
    private:
    inline static const std::string VALOR_VALIDO = "drama";
    inline static const std::string VALOR_INVALIDO = "erro";
    Tipo *tipo;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};
// Matrícula aluno 200028545
class TUClassificacao {
    private:
    inline static const std::string VALOR_VALIDO = "10";
    inline static const std::string VALOR_INVALIDO = "erro";
    Classificacao *classificao;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};
// Matrícula aluno 200028545
class TUMatricula {
    private:
    inline static const std::string VALOR_VALIDO = "12345";
    inline static const std::string VALOR_INVALIDO = "erro";
    Matricula *matricula;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};
// Matrícula aluno 200028545
class TUSenha {
    private:
    inline static const std::string VALOR_VALIDO = "ABD123#$";
    inline static const std::string VALOR_INVALIDO = "erro";
    Senha *senha;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};


#endif

