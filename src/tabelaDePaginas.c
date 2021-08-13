#include "tabelaDePaginas.h"

void inicializaTabela(TabelaDePaginas *tabela, int numPaginas) {
  for(int i= 0; i< numPaginas; i++){
    tabela[i].bitSujo = -1;
    tabela[i].numeroPagina = -1;
    tabela[i].IdAlgoritmo = 0;
    tabela[i].bitValido = 0;
    memcpy(tabela[i].endereco, "", strlen("")+1);
  }
}

int encontrarEndereco(TabelaDePaginas * tabela, int numPaginas, char *endereco){
  for(int i=0; i < numPaginas; i++){
    if(tabela[i].bitValido == 1){
      if(strncmp(tabela[i].endereco, endereco, sizeof(char[8]))){
        return i;
      } 
    }
  }
  return -1;
}