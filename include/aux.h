#ifndef AUX_H
#define AUX_H

/**
 * Define estruturas e métodos auxiliares,
 */

typedef struct {
  int escritas;
  int leituras;
  int oppInvalidas;
  int oppValidas;
} Relatorio;

void inicializaRel(Relatorio *rel);

int determinarOffset(int numPaginas);

#endif