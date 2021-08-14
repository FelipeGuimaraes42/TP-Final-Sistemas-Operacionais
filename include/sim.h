#ifndef SIM_H
#define SIM_H

#include <stdio.h>

/**
 * Defines the structures method that simulate the memory.
 */

typedef struct {
  unsigned frame;
  unsigned loadedClock;
  long int clockAccess;
  int dirtyFlag;
  int loadFlag;
  int secondChanceFlag; // lefe = second chacne =P . se não formos fazer o algoritmo de segunda chance melhor remover depois
} Page;

typedef struct {
  unsigned pageQty;
  unsigned pageSize;
  Page *pages;
} PageTable;

typedef struct {
  unsigned page;
  int filledFlag;
} Frame;

typedef struct {
  unsigned pagesRead;
  unsigned pagesToWrite;
  unsigned framesQty;
  unsigned occupiedFrames;
  unsigned clock;
  unsigned memSize;
  Frame *frames;
} Memory;

void sim (PageTable *table, Memory *memory, FILE *arq, char *);

#endif