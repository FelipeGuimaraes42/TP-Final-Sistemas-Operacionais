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

unsigned returnFreeFrame (Memory *memory);

void freeFullFrame (PageTable *table, Memory *memory, unsigned frame);

void initializeStructures (PageTable *table, Memory *memory, Report *report, int memSize, int pageSize);

void loadPage (PageTable *table, Memory *memory, unsigned targetFrame, unsigned targetPage);

#endif