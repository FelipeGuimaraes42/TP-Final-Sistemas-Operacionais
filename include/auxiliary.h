#ifndef AUXILIARY_H
#define AUXILIARY_H

#include "virtualMemorySimulator.h"

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

int getOffset(int numPages);

unsigned getPage (unsigned addr, int offset);

unsigned returnFreeFrame (Memory *memory);

void returnFlagFullFrame (PageTable *table, Memory *memory, unsigned frame);

void initializeStructures (PageTable *table, Memory *memory, Report *report, int memSize, int pageSize);

void loadPage (PageTable *table, Memory *memory, unsigned frame, unsigned page);


#endif