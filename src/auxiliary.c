#include "../include/auxiliary.h"

// Leandro

unsigned getPage (unsigned addr, int offset) {

}

unsigned returnFreeFrame (Memory *memory) {

}

void returnFlagFullFrame (PageTable *table, Memory *memory, unsigned frame) {

}

void initializeStructures (PageTable *table, Memory *memory, int memSize, int pageSize) {

}

void loadPage (PageTable *table, Memory *memory, unsigned frame, unsigned page) {

}

int determinarOffset(int numPaginas) {
  int offset = 0;
  int tmp = numPaginas;
  while (tmp > 1) {
    tmp = tmp >> 1;
    offset ++;
  }
  return offset;
}