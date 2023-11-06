#include "casa.h"
#include "imovel.h"

Casa :: Casa(int n1,int n2,int n3,int n4,string s1,string s2,string s3,string s4,float f1,int n5,bool b) : Imovel(n1,n2,n3,n4,s1,s2,s3,s4,f1){
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