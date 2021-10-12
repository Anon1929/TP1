
#ifndef ENTIDADESH
#define ENTIDADESH
#include "dominios.h"

///Matrícula do aluno: 200023624
///Classe representativa da entidade participante
class Participante {
    private:
            Matricula matricula;
            Nome nome;
            Nome sobrenome;
            Email email;
            Telefone telefone;
            Senha senha;
            Cargo cargo;
    public:
            ///Define Matrícula a partir de objeto Matricula recebido
            ///@param const Matricula& matricula
            void setMatricula(const Matricula&);
            ///Retorna atributo Matrícula
            ///@return Matricula matricula
            Matricula getMatricula() const;

            ///Define Nome a partir de objeto Nome recebido
            ///@param const Nome& nome
            void setNome(const Nome&);
            ///Retorna atributo Nome
            ///@return Nome nome
            Nome getNome() const;

            ///Define sobrenomeNome a partir de objeto Nome recebido
            ///@param const Nome& sobrenome
            void setSobrenome(const Nome& sobrenome);
            ///Retorna atributo sobrenome
            ///@return Nome sobrenome
            Nome getSobrenome() const;

            ///Define Email a partir de objeto Email recebido
            ///@param const Email& email
            void setEmail(const Email&);
            ///Retorna atributo Email
            ///@return Email email
            Email getEmail() const;

            ///Define Telefone a partir de objeto Telefone recebido
            ///@param const Telefone&
            void setTelefone(const Telefone& telefone);
            ///Retorna atributo Telefone
            ///@return Telefone telefone
            Telefone getTelefone() const;

            ///Define Senha a partir de objeto Senha recebido
            ///@param const Senha&
            void setSenha(const Senha& senha);
            ///Retorna atributo Senha
            ///@return Senha senha
            Senha getSenha() const;

            ///Define Cargo a partir de objeto Cargo recebido
            ///@param const Cargo&
            void setCargo(const Cargo& cargo);
            ///Retorna atributo Cargo
            ///@return Cargo cargo
            Cargo getCargo() const;
};
//Matricula
inline void Participante::setMatricula(const Matricula &matricula){
    this->matricula = matricula;
}
inline Matricula Participante::getMatricula() const{
    return matricula;
}

//Nome
inline void Participante::setNome(const Nome &nome){
    this->nome = nome;
}
inline Nome Participante::getNome() const{
    return nome;
}

//Sobrenome
inline void Participante::setSobrenome(const Nome &sobrenome){
    this->sobrenome = sobrenome;
}
inline Nome Participante::getSobrenome() const{
    return sobrenome;
}

//Email
inline void Participante::setEmail(const Email &email){
    this->email = email;
}
inline Email Participante::getEmail() const{
    return email;
}

//Telefone
inline void Participante::setTelefone(const Telefone &telefone){
    this->telefone = telefone;
}
inline Telefone Participante::getTelefone() const{
    return telefone;
}

//Senha
inline void Participante::setSenha(const Senha &senha){
    this->senha = senha;
}
inline Senha Participante::getSenha() const{
    return senha;
}

//Cargo
inline void Participante::setCargo(const Cargo &cargo){
    this->cargo = cargo;
}
inline Cargo Participante::getCargo() const{
    return cargo;
}


///Matricula aluno 200028545
/// Classe representativa de entidade Peça
class Peca{
private:
    Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;
public:

///Define atributo código com objeto Código passado
///@param const Codigo& codigo

    void setCodigo(const Codigo&);

///Retorna atributo código como objeto
///@return Codigo codigo

    Codigo getCodigo();


///Define atributo nome com objeto Nome passado
///@param const Nome& nome

    void setNome(const Nome&);

///Retorna atributo nome como objeto
///@return Nome nome

    Nome getNome();

///Define atributo tipo com objeto Tipo passado
///@param const Tipo& tipo

    void setTipo(const Tipo&);


///Retorna atributo tipo como objeto
///@return Tipo tipo

    Tipo getTipo();

///Define atributo classificação com objeto Classificação passado
///@param const Classificacao& classificacao

    void setClassificacao(const Classificacao&);

///Retorna atributo classificação como objeto
///@return Classificacao classificacao

    Classificacao getClassificacao();

};

inline void Peca::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline Codigo Peca::getCodigo(){
    return codigo;
}

inline void Peca::setNome(const Nome& nome){
    this->nome = nome;
}

inline Nome Peca::getNome(){
    return nome;
}

inline void Peca::setTipo(const Tipo& tipo){
    this->tipo = tipo;
}

inline Tipo Peca::getTipo(){
    return tipo;
}


inline void Peca::setClassificacao(const Classificacao& classificacao){
    this->classificacao = classificacao;
}


inline Classificacao Peca::getClassificacao(){
    return classificacao;
}

/// Matricula do Aluno 200028545
class Sala {
private:
    Codigo codigo;
    Nome nome;
    Capacidade capacidade;

public:

///Define atributo código com objeto Código passado
///@param const Codigo& codigo

    void setCodigo(const Codigo&);

///Retorna atributo código como objeto
///@return Codigo codigo

    Codigo getCodigo();

///Define atributo nome com objeto Nome passado
///@param const Nome& nome

    void setNome(const Nome&);

///Retorna atributo nome como objeto
///@return Nome nome

    Nome getNome();

///Define atributo Capacidade com objeto capacidade passado
///@param const Capacidade& capacidade

    void setCapacidade(const Capacidade&);

///Retorna atributo Capacidade como objeto
///@return Capacidade capacidade

    Capacidade getCapacidade();

};

inline void Sala::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline Codigo Sala::getCodigo(){
        return codigo;
}

inline void Sala::setNome(const Nome& nome){
    this->nome = nome;
}

inline Nome Sala::getNome(){
    return nome;
}

inline void Sala::setCapacidade(const Capacidade& capacidade){
    this->capacidade = capacidade;
}

inline Capacidade Sala::getCapacidade(){
    return capacidade;
}
/// Matrícula: 200016750
/// Classe representativa de entidade Sessao
class Sessao{
private:
    Codigo codigo;
    Data data;
    Horario horario;

public:
    void setCodigo(const Codigo& );

///Retorna atributo código como objeto
///@return Codigo codigo

    Codigo getCodigo();

///Define atributo data com objeto Data passado
///@param const Data& data

    void setData(const Data&);

///Retorna atributo data como objeto
///@return Data data

    Data getData();

///Define atributo horario com objeto Horario passado
///@param const Horario& horario

    void setHorario(const Horario&);


///Retorna atributo horario como objeto
///@return Horario horario

    Horario getHorario();
};

inline void Sessao::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

inline Codigo Sessao::getCodigo(){
    return codigo;
}

inline void Sessao::setData(const Data& data){
    this->data = data;
}

inline Data Sessao::getData(){
    return data;
}

inline void Sessao::setHorario(const Horario& horario){
    this->horario = horario;
}

inline Horario Sessao::getHorario(){
    return horario;
}




#endif // ENTIDADESH
