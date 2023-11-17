#ifndef CASA_H_
#define CASA_H_
#include "imovel.h"
#include <string>
using namespace std;

class Casa: public Imovel { //casa herda de imovel
    int andares;
    bool sala_jantar;

    public:
        Casa(int,float, string, string, string, string, int, int, int, int=0,bool=0);
        int getAndares();
        void setAndares(int);
        bool getSalaJantar();
        void setSalaJantar(bool);
        friend ostream& operator<<(ostream&,const Casa);
};




#endif