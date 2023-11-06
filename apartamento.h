#ifndef APARTAMENTO_H_
#define APARTAMENTO_H_

using namespace std;

class Apartamento: public Imovel{
    int andar;
    float taxa_condominio;
    bool elevador,sacada;

    public:
        Apartamento(int,int,int,int,string,string,string,string,float,int=0,float=0,float=0,bool=false,bool=false);
        int getAndar();
        void setAndar(int);
};


#endif