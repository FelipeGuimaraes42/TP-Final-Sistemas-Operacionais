#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdlib.h>
#include <time.h>

#define INT_MAX 2147483647

/**
 * Defines the structures and the method that simulate the memory
 */

typedef struct {
  unsigned frame;
  unsigned loadedClock;
  long int clockAccess;
  int dirtyFlag;
  int loadedFlag;
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

int fifo (PageTable *, Memory *);

int lru (PageTable *, Memory *);

int lefe (Memory *);

#endif