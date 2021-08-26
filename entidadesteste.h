#ifndef TESTES_E_INCLUDED
#define TESTES_E_INCLUDED
#include "entidades.h"

///Matricula aluno 200028545
class TUPeça{
private:
    Peça *peca;
    int estado;
    inline const static std::string CODIGOVALIDO = "AA0000";
    inline const static std::string NOMEVALIDO = "Testeum";
    inline const static std::string TIPOVALIDO = "farsa";
    inline const static std::string CLASSICACAOVALIDA = "10";
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

/*
class TUProjeto {
private:
    const static int VALOR_VALIDO   = 20;   // Definição de constante para evitar número mágico.
    Projeto *projeto;                       // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};
*/

#endif // TESTES_E_INCLUDED
