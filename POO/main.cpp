#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "imovel.h"
#include "casa.h"
#include "apartamento.h"
#include "chacara.h"

using namespace std;

int main(){

ifstream arquivo("database_imoveis.txt");
vector<Imovel*> imoveis;

if (arquivo.is_open()) {
    string tipoImovel;
    while (getline(arquivo, tipoImovel, ';')) {
        cout << "Tipo de Imóvel: " << tipoImovel << endl;

        int id, numero, quartos, banheiros;
        float valor;
        string proprietario, rua, bairro, cidade;
    
        arquivo >> valor;
        cout << valor<<endl;//teste
        arquivo.ignore();
        getline(arquivo, proprietario, ';');
        getline(arquivo, rua, ';');
        getline(arquivo, bairro, ';');
        getline(arquivo, cidade, ';');
        arquivo >> numero >> quartos >> banheiros;

        cout <<numero<<endl;//teste

        if (tipoImovel == "casa") {
            int andares;
            bool salaDeJantar;

            arquivo >> andares;
            arquivo >> salaDeJantar;

            Casa* casa = new Casa(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros, andares, salaDeJantar);
            imoveis.push_back(casa);
        } else if (tipoImovel == "apartamento") {
            int andar;
            float taxa;
            bool elevador, sacada;

            arquivo >> andar;
            arquivo >> taxa;
            arquivo >> elevador >> sacada;

            Apartamento* apartamento = new Apartamento(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros, taxa, andar, elevador, sacada);
            imoveis.push_back(apartamento);
        } else if (tipoImovel == "chacara") {
            bool salaoFesta, salaoJogos, campoFut, churrasqueira, piscina;

            arquivo >> salaoFesta >> salaoJogos >> campoFut >> churrasqueira >> piscina;

            Chacara* chacara = new Chacara(id, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros, salaoFesta, salaoJogos, campoFut, churrasqueira, piscina);
            imoveis.push_back(chacara);
        }

        arquivo.ignore();
    }

    arquivo.close();
} else {
    cerr << "Erro ao abrir o arquivo de imóveis." << endl;
}


cout << "Tamanho do vetor: " << imoveis.size() << endl;//teste


 for (const Imovel* imovel : imoveis) {
        cout << "aaaa" << endl;
        cout << *imovel << endl;
}

for (const Imovel* imovel : imoveis) {
        delete imovel;
}

return 0;
}
