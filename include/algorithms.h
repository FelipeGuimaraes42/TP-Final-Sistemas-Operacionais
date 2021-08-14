#ifndef ALGORITHMS_H
#define ALGORITHMS_H

/**
 * Defines the structures and the method that simulate the memory
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

int fifo (PageTable *table, Memory *memory);

int lru (PageTable *table, Memory *memory);

int lefe (PageTable *table, Memory *memory); // lefe = second chance =P

#endif