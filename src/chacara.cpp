#include "chacara.h"
#include <ostream>
#include "imovel.h"

Chacara :: Chacara(int n1,float f1, string s1, string s2, string s3, string s4, int n2, int n3, int n4,bool b1,bool b2,bool b3,bool b4,bool b5) : Imovel(n1,f1,s1,s2,s3,s4,n2,n3,n4){
    salao_festa = b1; salao_jogos = b2; campo_futebol = b3; churrasqueira = b4; piscina = b5;
}

bool Chacara :: getSalaoFesta(){
    return salao_festa;
}

void Chacara :: setSalaoFesta(bool b){
    salao_festa = b;
}

bool Chacara :: getSalaoJogos(){
    return salao_jogos;
}

void Chacara :: setSalaoJogos(bool b){
    salao_jogos = b;
}

bool Chacara :: getCampoFutebol(){
    return campo_futebol;
}

void Chacara :: setCampoFutebol(bool b){
    salao_jogos = b;
}

bool Chacara :: getChurrasqueira(){
    return churrasqueira;
}

void Chacara :: setChurrasqueira(bool b){
    churrasqueira = b;
}

bool Chacara :: getPiscina(){
    return piscina;
}

void Chacara :: setPiscina(bool b){
    piscina = b;
}

ostream& operator<<(ostream& os, const Chacara chacara) {
    os << static_cast<const Imovel&>(chacara)
       << "Característica Específica: Possui piscina: " << (chacara.piscina ? "Sim" : "Não") << endl;
    return os;
}