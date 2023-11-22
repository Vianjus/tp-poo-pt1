
#include <limits>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "casa.h"
#include "imovel.h"
#include <string.h>
#include "chacara.h"
#include "apartamento.h"

using namespace std;

vector <Imovel*> leArquivo();

int main(){

  float valor;
  string tipo;
  string cidade;
  int aux =-1,n;
  vector <Imovel*> imoveis = leArquivo();
  string nomeProp;
  vector<Imovel*> imoveisOrdenados;
  vector<Imovel*> imoveisPorQuartos;
  vector<Imovel*> imoveisPorValor;
  vector<Imovel*> imoveisPorCidade;
  
  vector <vector<Imovel*> :: iterator> iteradores;
  bool possui;

  do //Menu da Imobiliária
  {
    //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
    cout<<"Menu da imobiliária"<<endl;
    cout<<"\nOpção [1] -> Verificar se o nome possui algum imóvel."<<endl;
    cout<<"Opção [2] -> Verficar imóveis compatíveis com o valor."<<endl;
    cout<<"Opção [3] -> Verificar imóveis compatíveis com a quantidade de quartos requerida."<<endl;
    cout<<"Opção [4] -> Verificar todos os imóveis por tipo."<<endl;
    cout<<"Opção [5] -> Verificar imóveis em de uma cidade."<<endl;
    cout<<"Opção [6] -> Verificar imóveis de um proprietário."<<endl;
    cout<<"Opção [7] -> Criar arquivo de saída."<<endl;
    cout<<"Opção [0] -> Encerrar o programa."<<endl;
    cout<<"\nDigite a operação: "; cin>>aux;

    

    switch (aux)
    {
    case 0: //Opção [0] -> Encerrar o programa.
      //system("clear");
      cout<<"Fechando programa ..."<<endl;
      break;

    case 1: //Opção [1] -> Verificar se o nome possui algum imóvel
      cout << "PROPRIETARIO NOME: " << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
      getline(cin, nomeProp);

      possui = possuiImovelDoProprietario(imoveis, nomeProp);
      if (possui) {
        cout << "O proprietário possui pelo menos um imóvel." << endl;
        } else {
        cout << "O proprietário não possui nenhum imóvel." << endl;
        }
      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      system("clear");
      break;

    case 2: //Opção [2] -> Verficar imóveis compatíveis com o valor.
      cout << "Digite o valor: " ;
      cin >> valor;
      cout << endl;

      imoveisPorValor = obterImoveisAbaixoValor(valor, imoveis);
      for(auto it = imoveisPorValor.begin();it != imoveisPorValor.end(); it++){
        cout << **it << endl; 
        cout<< "-------------------------------------"<<endl;
      }

      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      getchar();
      system("clear");
      break;

    case 3: //Opção [3] -> Verificar imóveis compatíveis com a quantidade de quartos requerida.
      cout << "Insira o número de quartos" << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
      cin>>n;
      imoveisPorQuartos = obterImoveisPorQuartos(imoveis,n);
      
      for(auto it = imoveisPorQuartos.begin();it != imoveisPorQuartos.end(); it++){
        cout << **it; 
        cout<< "-------------------------------------"<<endl;
      }
      
      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      getchar();
      system("clear");
      break;
      
      break;

    case 4: //Opção [4] -> Verificar todos os imóveis por tipo.
      
      cout << "Insira o tipo do imovel: "; 
      cin>>tipo;
      imoveisOrdenados = obterImoveisPorTipo(imoveis, tipo);

      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      getchar();
      system("clear");
      break;

    case 5: //Opção [5] -> Verificar imóveis em de uma cidade.
      
      cout << "Digite o nome da cidade: " ;
      getchar();
      getline(cin, cidade);
      imoveisPorCidade = imoveisPorCidadeDescresc(imoveis, cidade);
      
      for(auto it = imoveisPorCidade.begin();it != imoveisPorCidade.end(); it++){
        cout << **it; 
        cout<< "-------------------------------------"<<endl;
      }
      
      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      system("clear");

      break;

    case 6: //Opção [6] -> Verificar imóveis de um proprietário.
      cout << "Insira o nome do proprietário: " << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
      getline(cin, nomeProp);

      system("clear");
      iteradores = getIterators(imoveis,nomeProp);

      for(auto it = iteradores.begin();it != iteradores.end();it++){
        cout << ***it << endl;
      }

      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      system("clear");
      break;
    
    case 7: //Opção [7] -> Criar arquivo de saída.
      imprimirOuSalvar(imoveis);
      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      getchar();
      system("clear");
      break;
    
    default:
      cout<<"Comando não indentificado."<<endl<<"Digite qualquer tecla para reiniciar:"<<endl;getchar();getchar();
      aux=-1;
      system("clear");
      break;
    }
  } while (aux != 0);
  
  
  return 0;
}

vector <Imovel*> leArquivo(){

  int numero,quartos,banheiros,andar;
  float valor,taxa_condominio;
  char aux;
  string tipo,proprietario,rua,bairro,cidade,valores;
  bool elevador,sacada,sala_jantar,salao_festas,salao_jogos,campo_futebol,churrasqueira,piscina;

  ifstream arquivo;
  arquivo.open("data/database_imoveis.txt");

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
      Apartamento* apartamento = new Apartamento(1, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros, taxa_condominio, andar, elevador, sacada);
      imoveis.push_back(apartamento);
    }
    else if(tipo == "casa"){
      arquivo >> aux;
      arquivo >> andar;
      arquivo >> aux;
      arquivo >> sala_jantar;
      arquivo >> aux;
      Casa* casa = new Casa(2, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros, andar, sala_jantar);
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
      Chacara* chacara = new Chacara(3, valor, proprietario, rua, bairro, cidade, numero, quartos, banheiros, salao_festas, salao_jogos, campo_futebol, churrasqueira, piscina);
      imoveis.push_back(chacara);
      }

    arquivo.ignore(numeric_limits<streamsize>::max(), '\n');

  }

//cout << "Tamanho do vetor: " << imoveis.size() << endl;//teste

  return imoveis;
}