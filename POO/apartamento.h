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
        Apartamento(int,float, string, string, string, string, int, int, int, int=0,float=0,bool=false,bool=false);
        int getAndar();
        void setAndar(int);
        float getTaxaCondominio();
        void SetTaxaCondominio(float=0);
        bool getElevador();
        void setElevador(bool=false);
        friend ostream& operator<<(ostream&,const Apartamento);


};

#endif