#ifndef VIRTUAL_MEMORY_SIMULATOR_H
#define VIRTUAL_MEMORY_SIMULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliary.h"
#include "algorithms.h"

/**
 * Defines the algorithms used in this project.
 */

void virtualMemorySimulator (PageTable *, Memory *, FILE *, char *);

#endif