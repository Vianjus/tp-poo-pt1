#include <iostream>
#include "imovel.h"
#include "casa.h"

int main(int argv, char* argc[])
{
  Casa imovel(11,134,4,2,"favela","geraldoquirino","baux","op",176.5,2,true);

  cout << imovel << endl;

  return 0;

} 