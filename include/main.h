#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <errno.h>
#include <time.h>

typedef struct {
  int idAlg;
  int bitValido;
  int bitSujo;
  char end[8]; // Endereço de memória
  unsigned int numPag;
} TabelaPaginas;

#endif