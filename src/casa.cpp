#include "casa.h"
#include "imovel.h"
#include <ostream>

Casa :: Casa(int n1,float f1, string s1, string s2, string s3, string s4, int n2, int n3, int n4, int n5,bool b) : Imovel(n1,f1,s1,s2,s3,s4,n2,n3,n4){
    andares = n5;
    sala_jantar = b;
}

int Casa :: getAndares(){
    return andares;
}
void Casa :: setAndares(int n){
    andares = n;
}
bool Casa :: getSalaJantar(){
    return sala_jantar;
}
void Casa :: setSalaJantar(bool b){
    sala_jantar = b;
}

ostream& operator<<(ostream& os, const Casa casa) {
    os << static_cast<const Imovel&>(casa)
       << "Característica Específica: Quantidade de Andares: " << casa.andares << endl;
    return os;
}
