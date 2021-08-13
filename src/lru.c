#include "../include/lru.h"

int lru(TabelaDePaginas *tabela, int numPag){
  int referencia;
  int lru = -1;
  referencia = tabela[0].IdAlgoritmo;
  for(int i = 0; i < numPag; i ++){
    if(referencia > tabela[i].IdAlgoritmo){
      referencia = tabela[i].IdAlgoritmo;
      lru = i;
    }
  }
  return lru; 
}