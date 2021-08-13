#include "../include/lru.h"

int lru(TabelaDePaginas *tabela, int numPag){
  int lru = -1;
    int referencia = tabela[0].IdAlgoritmo;

    for(int i=0; i < numPag; i++){

      if(tabela[i].IdAlgoritmo <= referencia){
        lru = i;
        referencia = tabela[i].IdAlgoritmo;
      }
    }

    return lru; 
}