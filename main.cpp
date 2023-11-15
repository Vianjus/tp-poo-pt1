#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include "imovel.h"
#include "casa.h"
#include "apartamento.h"
#include "chacara.h"

using namespace std;

vector <Imovel*> leArquivo();

int main(){

  vector <Imovel*> imoveis = leArquivo();
  
}

vector <Imovel*> leArquivo(){

  int id,numero,quartos,banheiros,andar;
  float valor,taxa_condominio;
  char aux;
  string tipo,proprietario,rua,bairro,cidade,valores;
  bool elevador,sacada,sala_jantar,salao_festas,salao_jogos,campo_futebol,churrasqueira,piscina;

  ifstream arquivo;
  arquivo.open("database_imoveis.txt");

  if(!arquivo.is_open()){
    cerr << "erro ao abrir o arquivo" << endl;
  }

  vector <Imovel*> imoveis; // vetor de ponteiro de imoveis

  while(!arquivo.eof()){

    getline(arquivo,tipo,';');
    arquivo >> valor;
    arquivo >> aux;
    getline(arquivo,proprietario,';');
    getline(arquivo,rua,';');
    getline(arquivo,bairro,';');
    getline(arquivo,cidade,';');
    arquivo >> numero;
    arquivo >> aux;
    arquivo >> quartos;
    arquivo >> aux;
    arquivo >> banheiros;

    if(tipo == "apartamento"){
      arquivo >> aux;
      arquivo >> andar;
      arquivo >> aux;
      arquivo >> taxa_condominio;
      arquivo >> aux;
      arquivo >> elevador;
      arquivo >> aux;
      arquivo >> sacada;
      arquivo >> aux;
      Apartamento* apartamento = new Apartamento(0,numero,quartos,banheiros,proprietario,rua,bairro,cidade,valor,andar,taxa_condominio,elevador,sacada);
      imoveis.push_back(apartamento);
    }
    else if(tipo == "casa"){
      arquivo >> aux;
      arquivo >> andar;
      arquivo >> aux;
      arquivo >> sala_jantar;
      arquivo >> aux;
      Casa* casa = new Casa(0,numero,quartos,banheiros,proprietario,rua,bairro,cidade,valor,andar,sala_jantar);
      imoveis.push_back(casa);
    }
    else if(tipo == "chacara"){
      arquivo >> aux;
      arquivo >> salao_festas;
      arquivo >> aux;
      arquivo >> salao_jogos;
      arquivo >> aux;
      arquivo >> campo_futebol;
      arquivo >> aux;
      arquivo >> churrasqueira;
      arquivo >> aux;
      arquivo >> piscina;
      arquivo >> aux;
      Chacara* chacara = new Chacara(0,numero,quartos,banheiros,proprietario,rua,bairro,cidade,valor,salao_festas,salao_jogos,campo_futebol,churrasqueira,piscina);
      imoveis.push_back(chacara);
      }

    arquivo.ignore(numeric_limits<streamsize>::max(), '\n');

  }

  return imoveis;
}