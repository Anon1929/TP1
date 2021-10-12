#include <iostream>
#include "dominios.h"
#include "dominiosteste.h"
#include "entidades.h"
#include "entidadesteste.h"
int main(void){
    std::cout << "----Dominios---" << std::endl;
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
    TUTelefone testeTelefone;
    std::cout << "Telefone: " << testeTelefone.run() << std::endl;
    TUCodigo testeCodigo;
    std::cout << "Codigo: " << testeCodigo.run() << std::endl;
    TUHorario testeHorario;
    std::cout << "Horario: " << testeHorario.run() << std::endl;
    std::cout << "----Entidades---" << std::endl;
    TUPeca testepeca;
    std::cout << "Peça: " << testepeca.run() << std::endl;
    TUParticipante testeParticipante;
    std::cout << "Participante: " << testeParticipante.run() << std::endl;
    TUSala testesala;
    std::cout << "Sala: " << testesala.run() << std::endl;
    TUSessao testeSessao;
    std::cout << "Sessao: " << testeSessao.run() << std::endl;

    return 0;
}
