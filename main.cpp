#include <iostream>
#include "vdominios.h"
#include "dominiosteste.h"
#include "entidades.h"
#include "entidadesteste.h"
int main(void){
    TUCapacidade testecapacidade;
    std::cout << testecapacidade.run();
    TUCargo testecargo;
    std::cout << testecargo.run();
    TUTipo testetipo;
    std::cout << testetipo.run();
    TUClassificacao testeclassificacao;
    std::cout << testeclassificacao.run();
    TUMatricula testematricula;
    std::cout << testematricula.run();
    TUSenha testesenha;
    std::cout << testesenha.run();
    TUNome testeNome;
    std::cout << testeNome.run();
    TUEmail testeEmail;
    std::cout << testeEmail.run();
    TUData testeData;
    std::cout << testeData.run();
    TUPeça testepeca;
    std::cout << testepeca.run();

    return 0;
}
