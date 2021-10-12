#include "dominios.h"
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

// Matrícula aluno 200023624
class TUNome {
    private:
    inline static const std::string VALOR_VALIDO = "Marcelo Junqueira";
    inline static const std::string VALOR_INVALIDO = "m@rc3lo.  junqueira";
    Nome *nome;
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

// Matrícula aluno 200023624
class TUEmail {
    private:
    inline static const std::string VALOR_VALIDO = "teste@email.com";
    inline static const std::string VALOR_INVALIDO = "!teste@ email.com";
    Email *email;
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

// Matrícula aluno 200023624
class TUData {
    private:
    inline static const std::string VALOR_VALIDO = "01/01/2000";
    inline static const std::string VALOR_INVALIDO = "00/00/0000";
    Data *data;
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

// Matrícula aluno 200023624
class TUTelefone {
    private:
    inline static const std::string VALOR_VALIDO = "(11)-111111111";
    inline static const std::string VALOR_INVALIDO = "000000000";
    Telefone *telefone;
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

// Matrícula aluno 200023624
class TUCodigo {
    private:
    inline static const std::string VALOR_VALIDO = "AA0000";
    inline static const std::string VALOR_INVALIDO = "11AAAA";
    Codigo *codigo;
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

// Matrícula aluno 200023624
class TUHorario {
    private:
    inline static const std::string VALOR_VALIDO = "00:00";
    inline static const std::string VALOR_INVALIDO = "Meio dia";
    Horario *horario;
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

