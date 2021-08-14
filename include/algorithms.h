#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "sim.h"

/**
 * Defines the algorithms used in this project.
 */

int fifo (PageTable *table, Memory *memory);

int lru (PageTable *table, Memory *memory);

int lefe (PageTable *table, Memory *memory); // lefe = second chance =P

#endif