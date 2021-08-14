#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "algorithms.h"

/**
 * Defines a structure and methods that are auxiliary in nature.
 */

typedef struct {
  int writes;
  int reads;
  int hits;
  int pageFaults;
  int dirtyPages;
} Report;

unsigned returnFreeFrame (Memory *);

void freeFullFrame (PageTable *, Memory *, unsigned);

void initializeStructures (PageTable *, Memory *, Report *, int , int );

void loadPage (PageTable *, Memory *, unsigned, unsigned);

#endif