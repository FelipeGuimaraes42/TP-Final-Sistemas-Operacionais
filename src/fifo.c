#include "../include/fifo.h"

int fifo (TabelaDePaginas *tabela, int numPag) {
  int referencia;
  int fifo = -1;
  referencia = tabela[0].IdAlgoritmo;
  for(int i = 0; i < numPag; i ++){
    if(referencia > tabela[i].IdAlgoritmo) {
      referencia = tabela[i].IdAlgoritmo;
      fifo = i;
    }
  }
  return fifo;
}