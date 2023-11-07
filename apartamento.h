#ifndef APARTAMENTO_H_
#define APARTAMENTO_H_
#include "imovel.h"
#include <string>

using namespace std;

class Apartamento: public Imovel{
    int andar;
    float taxa_condominio;
    bool elevador,sacada;

    public:
        Apartamento(int,int,int,int,string,string,string,string,float,int=0,float=0,bool=false,bool=false);
        int getAndar();
        void setAndar(int);
        float getTaxaCondominio();
        void SetTaxaCondominio(float=0);
        bool getElevador();
        void setElevador(bool=false);
        friend ostream& operator<<(ostream&,const Apartamento);


};

#endif