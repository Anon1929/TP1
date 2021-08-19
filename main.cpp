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

    Telefone teste4;
    std::cout << teste4.getEntrada() << std::endl;
    teste4.setEntrada("(99)-012345678");
    std::cout << teste4.getEntrada() << std::endl;

    Codigo teste5;
    std::cout << teste5.getEntrada() << std::endl;
    teste5.setEntrada("YZ6789");
    std::cout << teste5.getEntrada() << std::endl;

    Horario teste6;
    std::cout << teste6.getEntrada() << std::endl;
    teste6.setEntrada("23:45");
    std::cout << teste6.getEntrada() << std::endl;

    return 0;
}
