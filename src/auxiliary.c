#include "../include/auxiliary.h"

// Leandro

unsigned getPage (unsigned addr, int offset) {

}

unsigned returnFreeFrame (Memory *memory) {

}

void returnFlagFullFrame (PageTable *table, Memory *memory, unsigned frame) {

}

void initializeStructures (PageTable *table, Memory *memory, Report *report, int memSize, int pageSize) {

}

void loadPage (PageTable *table, Memory *memory, unsigned frame, unsigned page) {

}

int getOffset(int numPages) {
  int offset = 0;
  int tmp = numPages;
  while (tmp > 1) {
    tmp = tmp >> 1;
    offset ++;
  }
  return offset;
}