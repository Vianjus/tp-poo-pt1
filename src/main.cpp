
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

  //Declarações de variáveis auxiliares
  float valor;
  int n;
  char aux = '9';
  string tipo, cidade, nomeProp;
  vector <Imovel*> imoveis = leArquivo();
  vector<Imovel*> resultado;
  
  vector <vector<Imovel*> :: iterator> iteradores;
  bool possui;

  system("clear");
  do //Menu da Imobiliária
  {
    cout<<"Menu da imobiliária"<<endl;
    cout<<"\nOpção [1] -> Verificar se o nome possui algum imóvel."<<endl;
    cout<<"Opção [2] -> Verficar imóveis compatíveis com o valor."<<endl;
    cout<<"Opção [3] -> Verificar imóveis compatíveis com a quantidade de quartos requerida."<<endl;
    cout<<"Opção [4] -> Verificar todos os imóveis por tipo."<<endl;
    cout<<"Opção [5] -> Verificar imóveis em de uma cidade."<<endl;
    cout<<"Opção [6] -> Verificar imóveis de um proprietário."<<endl;
    cout<<"Opção [7] -> Visualizar todos os dados."<<endl;
    cout<<"Opção [0] -> Encerrar o programa."<<endl;
    cout<<"\nDigite a operação:"; cin>>aux;

    

    switch (aux)
    {
    case '0': //Opção [0] -> Encerrar o programa.
      system("clear");
      cout<<"[X] Programa finalizado."<<endl;
      break;

    case '1': //Opção [1] -> Verificar se o nome possui algum imóvel
      cout << "Digite o nome:";
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
      getline(cin, nomeProp);

      system("clear");
      possui = possuiImovelDoProprietario(imoveis, nomeProp);
      if (possui) {
        cout << "O proprietário possui pelo menos um imóvel." << endl;
        } else {
        cout << "O proprietário não possui nenhum imóvel." << endl;
        }
      cout<< "\nPressione qualquer tecla para retornar.";
      getchar();
      system("clear");
      break;

    case '2': //Opção [2] -> Verficar imóveis compatíveis com o valor.
      cout << "Digite o valor: " ;
      cin >> valor;
      cout << endl;
      system("clear");

      resultado = obterImoveisAbaixoValor(valor, imoveis);
      if (resultado.begin() == resultado.end())
      {
        cout<<"[!] Não possui nenhum imóvel com esse valor ou menos!"<<endl;
      }
      else{
        for(auto it = resultado.begin();it != resultado.end(); it++){
          cout << **it << endl; 
          cout<< "-------------------------------------"<<endl;
        }
      }

      cout<< "\nPressione qualquer tecla para retornar.";
      getchar();
      getchar();
      resultado.clear();
      system("clear");
      break;

    case '3': //Opção [3] -> Verificar imóveis compatíveis com a quantidade de quartos requerida.
      cout << "Insira o número de quartos:";
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
      cin>>n;
      resultado = obterImoveisPorQuartos(imoveis,n);
      system("clear");
      if (resultado.begin()==resultado.end())
      {
        cout<<"[!] Não há propriedades com essa quantidade de quartos!"<<endl;
      }
      else{
        for(auto it = resultado.begin();it != resultado.end(); it++){
          cout << **it; 
          cout<< "-------------------------------------"<<endl;
        }
      }
      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      getchar();
      resultado.clear();
      system("clear");
      break;

    case '4': //Opção [4] -> Verificar todos os imóveis por tipo.
      
      cout << "Insira o tipo do imovel: "; 
      cin>>tipo;
      system("clear");
      resultado = obterImoveisPorTipo(imoveis, tipo);
      if(resultado.begin()==resultado.end())
        cout<<"[!] Tipo inválido ou nenhuma casa com esse tipo.\n"<<endl;

      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      getchar();
      resultado.clear();
      system("clear");
      break;

    case '5': //Opção [5] -> Verificar imóveis em de uma cidade.
      
      cout << "Digite o nome da cidade: " ;
      getchar();
      getline(cin, cidade);
      system("clear");
      resultado = imoveisPorCidadeDescresc(imoveis, cidade);
      if (resultado.begin()==resultado.end())
        cout<<"[!] Não há nenhum imóvel nessa cidade!\n"<<endl;
      
      
      for(auto it = resultado.begin();it != resultado.end(); it++){
        cout << **it; 
        cout<< "-------------------------------------"<<endl;
      }
      
      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      resultado.clear();
      system("clear");

      break;

    case '6': //Opção [6] -> Verificar imóveis de um proprietário.
      cout << "Insira o nome do proprietário: " << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
      getline(cin, nomeProp);

      system("clear");
      iteradores = getIterators(imoveis,nomeProp);

      if (iteradores.begin()==iteradores.end())
      {
        cout<<"[!] Esse nome não é proprietário de nenhum imóvel!\n"<<endl;
      }
      else{
        for(auto it = iteradores.begin();it != iteradores.end();it++){
          cout << ***it;
          cout<<"-------------------------------------"<<endl;
        }
      }
      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      iteradores.clear();
      system("clear");
      break;
    
    case '7': //Opção [7] -> Criar arquivo de saída.
      imprimirOuSalvar(imoveis);
      cout<< "Pressione qualquer tecla para retornar.";
      getchar();
      getchar();
      system("clear");
      break;
    
    default:
      cout<<"Comando não indentificado."<<endl<<"Digite qualquer tecla para reiniciar:"<<endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer
      getchar();
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