#include "../include/auxiliar.h"

void inicializaRel(Relatorio *rel) {
  rel->escritas = 0;
  rel->leituras = 0;
  rel->oppInvalidas = 0;
  rel->oppValidas = 0;
}

int determinarOffset(int numPaginas) {
  int offset = 0;
  int tmp = numPaginas;
  while (tmp > 1) {
    tmp = tmp >> 1;
    offset ++;
  }
  return offset;
}