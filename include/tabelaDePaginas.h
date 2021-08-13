#ifndef TABELA_PAGINAS_H
#define TABELA_PAGINAS_H

#include <string.h>

typedef struct {
  int bitValido;
  int numeroPagina;
  int bitSujo;
  char endereco[8];
  int IdAlgoritmo; 
} TabelaDePaginas;


void inicializaTabela(TabelaDePaginas *tabela, int numPaginas);

int encontrarEndereco(TabelaDePaginas * tabela, int numPaginas, char *endereco);

#endif