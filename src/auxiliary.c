#include "../include/auxiliary.h"

// Leandro

unsigned returnFreeFrame (Memory *memory) {
  for (int i = 0; i < memory->framesQty; i++) {
    if(memory->frames[i].filledFlag == 0) {
      return i;
    }
  }
}

void freeFullFrame (PageTable *table, Memory *memory, unsigned frame) {

}

void initializeStructures (PageTable *table, Memory *memory, Report *report, int memSize, int pageSize) {
  // Initializing the report structure.
  report->writes = 0;
  report->reads = 0;
  report->hits = 0;
  report->pageFaults = 0;
  report->dirtyPages = 0;
  // Initializing the memory structure.
  memory->pagesRead = 0;
  memory->pagesToWrite = 0;
  memory->framesQty = memSize / pageSize;
  memory->occupiedFrames = 0;
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
    table->pages[i].loadFlag = 0;
    table->pages[i].secondChanceFlag = 0;
  }
}

void loadPage (PageTable *table, Memory *memory, unsigned frame, unsigned page) {

}
