#ifndef AUXILIARY_H
#define AUXILIARY_H

#include "sim.h"

/**
 * Defines methods that are auxiliary in nature.
 */

unsigned getPage (unsigned addr, int offset);

unsigned returnFreeFrame (Memory *memory);

void returnFlagFullFrame (PageTable *table, Memory *memory, unsigned frame);

void initializeStructures (PageTable *table, Memory *memory, int memSize, int pageSize);

void loadPage (PageTable *table, Memory *memory, unsigned frame, unsigned page);


#endif