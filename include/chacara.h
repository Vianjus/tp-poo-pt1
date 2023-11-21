#ifndef CHACARA_H_
#define CHACARA_H_
#include "imovel.h"

class Chacara: public Imovel{
    bool salao_festa,salao_jogos,campo_futebol,churrasqueira,piscina;

    public:
        Chacara(int, float, string, string, string, string, int, int, int,bool=false,bool=false,bool=false,bool=false,bool=false);
        bool getSalaoFesta();
        void setSalaoFesta(bool=false);
        bool getSalaoJogos();
        void setSalaoJogos(bool=false);
        bool getCampoFutebol();
        void setCampoFutebol(bool=false);
        bool getChurrasqueira();
        void setChurrasqueira(bool=false);
        bool getPiscina();
        void setPiscina(bool=false);
        friend ostream& operator<<(ostream&,const Chacara);
};



#endif