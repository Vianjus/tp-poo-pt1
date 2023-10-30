#include "imovel.h"
#include <iostream>

Imovel :: Imovel(int n1,int n2,int n3,int n4,string s1,string s2,string s3,string s4,float f1){
    id = n1; numero = n2; quartos = n3; banheiros = n4;
    valor = f1;
    proprietario = s1; rua = s2; bairro = s3; cidade = s4;
}
int Imovel :: getId(){
    return id;
}
void Imovel :: setId(int valor){
    id = valor;
}
float Imovel :: getValor(){
    return valor;
}
void Imovel :: setValor(float valor){
    this->valor = valor;
}
string Imovel :: getProprietario(){
    return proprietario;
}
void Imovel :: setProprietario(string nome){
    proprietario = nome;
}
string Imovel :: getRua(){
    return rua;
}
void Imovel :: setRua(string nome){
    rua = nome;
}
string Imovel :: getBairro(){
    return bairro;
}
void Imovel :: setBairro(string nome){
    bairro = nome;
}
string Imovel :: getCidade(){
    return cidade;
}
void Imovel :: setCidade(string nome){
    cidade = nome;
}
int Imovel :: getNumero(){
    return numero;
}
void Imovel :: setNumero(int numero){
    this->numero = numero;
}
int Imovel :: getQuartos(){
    return quartos;
}
void Imovel :: setQuartos(int n){
    quartos = n;
}
int Imovel :: getBanheiros(){
    return banheiros;
}
void Imovel :: setBanheiros(int n){
    banheiros = n;
}