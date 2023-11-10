#include "apartamento.h"
#include "imovel.h"
#include <string>
#include <ostream>


Apartamento :: Apartamento(int n1,float f2, string s1, string s2, string s3, string s4, int n2, int n3, int n4,int n5,float f1,bool b1,bool b2) : Imovel(n1,f2,s1,s2,s3,s4,n2,n3,n4) {
    andar = n5;
    taxa_condominio = f1;
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


ostream& operator<<(ostream& os, const Apartamento apartamento) {
    os << static_cast<const Imovel&>(apartamento);
    os << "Possui elevador: " << apartamento.elevador << endl;
    return os;
}
