#ifndef IMOVEL_H_
#define IMOVEL_H_
#include <string>

using namespace std;

class Imovel{

    int id,numero,quartos,banheiros;
    float valor;
    string proprietario,rua,bairro,cidade;

    public:
        Imovel(int=0,int=0,int=0,int=0,string="",string="",string="",string="",float=0);
        int getId();
        void setId(int);
        float getValor();
        void setValor(float);
        string getProprietario();
        void setProprietario(string);
        string getRua();
        void setRua(string);
        string getBairro();
        void setBairro(string);
        string getCidade();
        void setCidade(string);
        int getNumero();
        void setNumero(int);
        int getQuartos();
        void setQuartos(int);
        int getBanheiros();
        void setBanheiros(int);

};

#endif