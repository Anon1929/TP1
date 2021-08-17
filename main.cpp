#include <iostream>
#include "vdominios.h"
int main(void){
    Cargo teste;
    teste.setTitulo("figurinista");
    std::cout << teste.getTitulo() << std::endl;
    Matricula teste2;
    std::cout << teste2.getRegistro() << std::endl;
    teste2.setRegistro("12453");
    std::cout << teste2.getRegistro() << std::endl;
    Senha teste3;
    std::cout << teste3.getEntrada() << std::endl;
    teste3.setEntrada("123456a!");
    std::cout << teste3.getEntrada() << std::endl;

    return 0;
}
