#include "apartamento.h"
#include "imovel.h"
#include <string>
#include <ostream>


Apartamento :: Apartamento(int n1,int n2,int n3,int n4,string s1,string s2,string s3,string s4,float f1,int n5,float f2,bool b1,bool b2) : Imovel(n1,n2,n3,n4,s1,s2,s3,s4,f1) {
    andar = n5;
    taxa_condominio = f2;
    elevador = b1; sacada = b2;
}

int Apartamento :: getAndar(){
    return andar;
}

void Apartamento :: setAndar(int n){
    andar = n;
}

float Apartamento :: getTaxaCondominio(){
    return taxa_condominio;
}

void Apartamento :: SetTaxaCondominio(float valor){
    taxa_condominio = valor;
}

bool Apartamento :: getElevador(){
    return elevador;
}

void Apartamento :: setElevador(bool b){
    elevador = b;
}

ostream& operator<<(ostream& os,const Apartamento c){
    os << static_cast<const Imovel&>(c);
    os << c.elevador << endl;
    return os;
}