#include "imovel.h"
#include "casa.h"
#include "apartamento.h"
#include "chacara.h"
#include <iostream>
#include <fstream>
#include <algorithm>

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
float Imovel :: getValor()const {
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

bool compararPorValor(const Imovel* a, const Imovel* b) {
    return a->getValor() < b->getValor();
}

vector<Imovel*> obterImoveisPorTipo(const std::vector<Imovel*>& imoveis, const std::string& tipo) {
    std::vector<Imovel*> imoveisDoTipo;

    int codigoTipo = -1; // Inicialize com um valor que não corresponda a nenhum tipo válido

    if (tipo == "casa") {
        codigoTipo = 1;
    } else if (tipo == "apartamento") {
        codigoTipo = 2;
    } else if (tipo == "chacara") {
        codigoTipo = 3;
    }

    if (codigoTipo != -1) {
        for (Imovel* imovel : imoveis) {
            if (imovel->getId() == codigoTipo) {
                imoveisDoTipo.push_back(imovel);
            }
        }

        // Ordena por valor
        sort(imoveisDoTipo.begin(), imoveisDoTipo.end(), compararPorValor);
        for (const Imovel* imovel : imoveis) {
            if(tipo == "casa"){
                if (const Casa* casa = dynamic_cast<const Casa*>(imovel)) {
                    cout << *casa;
                } 
            }else if (tipo =="apartamento"){
                if(const Apartamento* apartamento = dynamic_cast<const Apartamento*>(imovel)) {
                cout << *apartamento;}
            } else if (tipo =="chacara"){
                if(const Chacara* chacara = dynamic_cast<const Chacara*>(imovel)) {
                cout << *chacara;
                }
            }
            
            cout << "------------------------" << endl;
        }
    }


    return imoveisDoTipo;
}

vector<vector <Imovel*> :: iterator> getIterators(vector<Imovel*>& imoveis, string proprietario){
    vector<vector<Imovel*> :: iterator> iteradores; //declara o vetor de iteradores
    vector<Imovel*> :: iterator it;
    
    for(it = imoveis.begin();it != imoveis.end();it++){
        if((*it)->getProprietario() == proprietario){
            iteradores.push_back(it);
        }
    }

    return iteradores;
    
}

vector<Imovel*> obterImoveisAbaixoValor(float valor, std::vector<Imovel*> &imoveis)
{
     vector<Imovel*> imoveis1;
    for(Imovel* imovel : imoveis){
        if(imovel->getValor() <= valor){
            imoveis1.push_back(imovel);
        }
    }
    return imoveis1;
}

vector<Imovel*> imoveisPorCidadeDescresc(vector<Imovel*> imoveis, string cidadeAlvo) {
    vector <Imovel*> imoveisOrdenados;
    if (!imoveis.empty()) {
        for (Imovel *imovel : imoveis) {
            if (imovel->getCidade() == cidadeAlvo) 
                imoveisOrdenados.push_back(imovel);
        }
    }

    if (!imoveisOrdenados.empty()) {
        sort(imoveisOrdenados.begin(), imoveisOrdenados.end(), [](const Imovel *imovel1, const Imovel *imovel2){
            return imovel1->getValor() > imovel2->getValor();
        });
    }

    return imoveisOrdenados;
}

vector<Imovel*> obterImoveisPorQuartos(const vector<Imovel*>& imoveis,int n){
    vector<Imovel*> imoveis1;
    for(Imovel* imovel : imoveis){
        if(imovel->getQuartos() >= n){
            imoveis1.push_back(imovel);
        }
    }
    return imoveis1;
}

