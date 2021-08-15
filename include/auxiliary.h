#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "algorithms.h"

/**
 * Defines a structure and methods that are auxiliary in nature.
 */

unsigned returnFreeFrame (Memory *);

void freeFullFrame (PageTable *, Memory *, unsigned);

void initializeStructures (PageTable *, Memory *, int , int );

void loadPage (PageTable *, Memory *, unsigned, unsigned);

char* itoa(int, char*, int);

#endif