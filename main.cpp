#include <iostream>
#include "vdominios.h"
#include "dominiosteste.h"
#include "entidades.h"
#include "entidadesteste.h"
int main(void){
    TUCapacidade testecapacidade;
    std::cout << "capacidade: " << testecapacidade.run() << std::endl;
    TUCargo testecargo;
    std::cout << "cargo: " << testecargo.run() << std::endl;
    TUTipo testetipo;
    std::cout << "tipo: " << testetipo.run() << std::endl;
    TUClassificacao testeclassificacao;
    std::cout << "classificação: " << testeclassificacao.run() << std::endl;
    TUMatricula testematricula;
    std::cout << "matricula: " << testematricula.run() << std::endl;
    TUSenha testesenha;
    std::cout << "senha: " << testesenha.run() << std::endl;
    TUNome testeNome;
    std::cout << "nome: " << testeNome.run() << std::endl;
    TUEmail testeEmail;
    std::cout << "email: " << testeEmail.run() << std::endl;
    TUData testeData;
    std::cout << "data: " << testeData.run() << std::endl;
    TUPeca testepeca;
    std::cout << "Peça: " << testepeca.run() << std::endl;
    TUParticipante testeParticipante;
    std::cout << "Participante: " << testeParticipante.run() << std::endl;
    TUSessao testeSessao;
    std::cout << "Sessao: " << testeSessao.run() << std::endl;

    return 0;
}
