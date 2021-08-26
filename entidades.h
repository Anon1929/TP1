#ifndef ENTIDADESH
#define ENTIDADESH


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
            void setMatricula(const Matricula&);
            Matricula getMatricula() const;

            void setNome(const Nome&);
            Nome getNome() const;

            void setSobrenome(const Nome&);
            Nome getSobrenome() const;

            void setEmail(const Email&);
            Email getEmail() const;

            void setTelefone(const Telefone&);
            Telefone getTelefone() const;

            void setSenha(const Senha&);
            Senha getSenha() const;

            void setCargo(const Cargo&);
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
inline void Participante::setSenha(const Senha &Senha){
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

/*
class Entidade {
    private:
            Dominio nomeAtributo;                   // Declarar cada atributo da classe.
    public:
            void setnomeAtributo(const Dominio&);   // Declarar método set para cada atributo.
            Dominio getnomeAtributo() const;        // Declarar método get para cada atributo.
};

inline void Entidade::setnomeAtributo(const Dominio &nomeAtributo){
    this->nomeAtributo = nomeAtributo;
}

inline Dominio Entidade::getnomeAtributo() const{
    return nomeAtributo;
}
*/

#endif // ENTIDADESH
