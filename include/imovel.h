#ifndef IMOVEL_H_
#define IMOVEL_H_
#include <string>
#include <vector>
using namespace std;

class Imovel{

    int id,numero,quartos,banheiros;
    string proprietario,rua,bairro,cidade;
    float valor;

    public:
        Imovel(int=0,float=0,string="",string="",string="",string="",int = 0, int = 0, int = 0);
        int getId();
        void setId(int);
        float getValor() const;
        void setValor(float);
        string getProprietario() const;
        void setProprietario(string);
        string getRua();
        void setRua(string);
        string getBairro();
        void setBairro(string);
        string getCidade();
        void setCidade(string);
        int getNumero();
        void setNumero(int);
        int getQuartos();
        void setQuartos(int);
        int getBanheiros();
        void setBanheiros(int);
        friend ostream& operator<<(ostream&,const Imovel);

        virtual ~Imovel() = default; // Destrutor virtual
};
bool possuiImovelDoProprietario(const vector<Imovel*>&, const string&);
void imprimirOuSalvar(const vector<Imovel*>& );
bool compararPorValor(const Imovel*, const Imovel*);
vector<vector <Imovel*>:: iterator> getIterators(vector<Imovel*>&, string);
vector<Imovel*> obterImoveisPorTipo(const std::vector<Imovel*>&, const std::string&);
        

#endif

