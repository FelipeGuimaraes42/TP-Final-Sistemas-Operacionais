#include "../include/auxiliary.h"

unsigned returnFreeFrame (Memory *memory) {
  for (int i = 0; i < memory->framesQty; i++) {
    if(memory->frames[i].filledFlag == 0) {
      return i;
    }
  }
  return -1;
}

void freeFullFrame (PageTable *table, Memory *memory, unsigned frame) {
  unsigned targetPage = memory->frames[frame].page;
  // Memory changes.
  if (table->pages[targetPage].dirtyFlag == 1) {
    memory->pagesToWrite ++;
  }
  memory->occupiedFramesQty --;
  memory->frames[frame].filledFlag = 0;
  memory->frames[frame].page = 0;

  // Table changes.
  table->pages[targetPage].frame = 0;
  table->pages[targetPage].loadedClock = -1;
  table->pages[targetPage].clockAccess = 0;
  table->pages[targetPage].dirtyFlag = 0;
  table->pages[targetPage].loadedFlag = 0;
}

void initializeStructures (PageTable *table, Memory *memory, int memSize, int pageSize) {
  // Initializing the memory structure.
  memory->pagesRead = 0;
  memory->pagesToWrite = 0;
  memory->framesQty = memSize / pageSize;
  memory->occupiedFramesQty = 0;
  memory->clock = 0;
  memory->memSize = memSize;
  memory->frames = (Frame*)malloc(memory->framesQty*sizeof(Frame));
  for (int i = 0 ; i < memory->framesQty; i++) {
    memory->frames[i].filledFlag = 0;
  }

  // Initializing the page table structure.
  table->pageQty = pow(2,32) / (pageSize * pow(2,10));
  table->pageSize = pageSize;
  table->pages = (Page*)malloc(table->pageQty*sizeof(Page));
  for (int i = 0 ; i < table->pageQty; i++) {
    table->pages[i].frame = 0;
    table->pages[i].loadedClock = 0;
    table->pages[i].clockAccess = -1;
    table->pages[i].dirtyFlag = 0;
    table->pages[i].loadedFlag = 0;
  }
}

void loadPage (PageTable *table, Memory *memory, unsigned targetFrame, unsigned targetPage) {
  // Table.
  table->pages[targetPage].frame = targetFrame;
  table->pages[targetPage].loadedClock = memory->clock;
  table->pages[targetPage].clockAccess = memory->clock;
  table->pages[targetPage].dirtyFlag = 0;
  table->pages[targetPage].loadedFlag = 1;

  // Memory.
  memory->occupiedFramesQty ++;
  memory->clock ++;
  memory->frames[targetFrame].filledFlag = 1;
  memory->frames[targetFrame].page = targetPage;
}
