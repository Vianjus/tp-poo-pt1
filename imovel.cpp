#include "imovel.h"
#include "casa.h"
#include "apartamento.h"
#include "chacara.h"
#include <iostream>
#include <fstream>

Imovel :: Imovel(int n1,float f1,string s1,string s2,string s3,string s4,int n2,int n3,int n4){
    id = n1; numero = n2; quartos = n3; banheiros = n4;
    proprietario = s1; rua = s2; bairro = s3; cidade = s4;
    valor = f1;
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
string Imovel :: getProprietario()const{
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

ostream& operator<<(ostream& os, const Imovel imovel) {
    os << "Proprietário: " << imovel.proprietario << endl
       << "Preço: " << imovel.valor << endl
       << "Número de Quartos: " << imovel.quartos << endl
       << "Rua: " << imovel.rua << endl
       << "Bairro: " << imovel.bairro << endl
       << "Cidade: " << imovel.cidade << endl;
    return os;
}

bool possuiImovelDoProprietario(const vector<Imovel*>& imoveis, const string& proprietario) {
    for (const Imovel* imovel : imoveis) {
        if (imovel->getProprietario() == proprietario) {
            return true;
        }
    }
    return false;
}

void imprimirOuSalvar(const vector<Imovel*>& imoveis) {
    char escolha;

    cout << "Deseja salvar ou imprimir? (S para salvar, I para imprimir): ";
    cin >> escolha;

    if (escolha == 'S' || escolha == 's') {
        ofstream arquivo("saida.txt");

        if (!arquivo.is_open()) {
            cout << "Erro ao abrir o arquivo de saída." << endl;
            return;
        }

        for (const Imovel* imovel : imoveis) {
            if (const Casa* casa = dynamic_cast<const Casa*>(imovel)) {
                arquivo << *casa;
            } else if (const Apartamento* apartamento = dynamic_cast<const Apartamento*>(imovel)) {
                arquivo << *apartamento;
            } else if (const Chacara* chacara = dynamic_cast<const Chacara*>(imovel)) {
                arquivo << *chacara;
            }
            arquivo << "------------------------" << endl;
        }

        cout << "Saída salva no arquivo 'saida.txt'." << endl;

    } else if (escolha == 'I' || escolha == 'i') {
        for (const Imovel* imovel : imoveis) {
            if (const Casa* casa = dynamic_cast<const Casa*>(imovel)) {
                cout << *casa;
            } else if (const Apartamento* apartamento = dynamic_cast<const Apartamento*>(imovel)) {
                cout << *apartamento;
            } else if (const Chacara* chacara = dynamic_cast<const Chacara*>(imovel)) {
                cout << *chacara;
            }
            cout << "------------------------" << endl;
        }

    } else {
        cout << "Escolha inválida. Nada será feito." << endl;
    }
}
