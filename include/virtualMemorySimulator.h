#ifndef VIRTUAL_MEMORY_SIMULATOR_H
#define VIRTUAL_MEMORY_SIMULATOR_H

#include <stdio.h>

/**
 * Defines the structures and the method that simulate the memory.
 */

typedef struct {
  unsigned frame;
  unsigned loadedClock;
  long int clockAccess;
  int dirtyFlag;
  int loadedFlag;
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
  unsigned occupiedFramesQty;
  unsigned clock;
  unsigned memSize;
  Frame *frames;
} Memory;

void virtualMemorySimulator (PageTable *, Memory *, FILE *, char *);

#endif