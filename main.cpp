#include <iostream>
#include "vdominios.h"
int main(void){/*
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
    //Nome*/
    Nome teste5("Marc.elo. Junqueira");
    std::cout << teste5.getValor() << std::endl;
    //teste5.setValor("Abc");
    //teste5.setValor("Abcdefghijklmnopqrstuvwxyz");
    //teste5.setValor("Abcds%6.");
    //teste5.setValor("Marcelo  Junqueira");
    //teste5.setValor("Marcelo junqueira");
    std::cout << teste5.getValor() << std::endl;

    return 0;
}
