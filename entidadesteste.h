#ifndef TESTES_E_INCLUDED
#define TESTES_E_INCLUDED
#include "entidades.h"

///Matricula aluno 200028545
class TUPeca{
private:
    Peca *peca;
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


///Matricula aluno 200023624
class TUParticipante{
private:
    Participante *participante;
    int estado;
    inline const static std::string MATRICULAVALIDA = "12345";
    inline const static std::string NOMEVALIDO = "Testeum";
    inline const static std::string SOBRENOMEVALIDO = "Testedois";
    inline const static std::string EMAILVALIDO = "teste@email.com";
    inline const static std::string SENHAVALIDA = "ABC123#$";
    inline const static std::string CARGOVALIDO = "ator";


    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};


///Matricula aluno 200016750
class TUSessao{
private:
    Sessao *sessao;
    int estado;
    inline const static std::string CODIGOVALIDO = "AA0000";
    inline const static std::string DATAVALIDA = "13/03/2002";
    inline const static std::string HORARIOVALIDO = "00:00";
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

#endif // TESTES_E_INCLUDED
