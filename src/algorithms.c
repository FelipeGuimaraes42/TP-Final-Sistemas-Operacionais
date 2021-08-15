#include "../include/algorithms.h"

int fifo (PageTable *table, Memory *memory) {
  int faster = INT_MAX;
  int frame = 0, index;

  if(memory->occupiedFramesQty < memory->framesQty){
    for(int i = 0; i < memory->framesQty; i++) {
      if(memory->frames[i].filledFlag == 0){
        return i;
      }
    }
  }

  for(int i = 0; i < memory->framesQty; i++){
    index = memory->frames[i].page;
    if(table->pages[index].loadedClock < faster){
      frame = i;
      faster = table->pages[index].loadedClock;
    }
  }
  return frame;
}

int lru (PageTable *table, Memory *memory) {
  int faster = INT_MAX;
  int frame = 0, index;

  if(memory->occupiedFramesQty < memory->framesQty){
    for(int i = 0; i < memory->framesQty; i++) {
      if(memory->frames[i].filledFlag == 0){
        return i;
      }
    }
  }
  for(int i = 0; i < memory->framesQty; i++){
    index = memory->frames[i].page;
    if(table->pages[index].clockAccess < faster){
      frame = i;
      faster = table->pages[index].clockAccess;
    }
  }
  return frame;
}

int lefe (Memory *memory) {
  if(memory->occupiedFramesQty < memory->framesQty){
    for(int i = 0; i < memory->framesQty; i++) {
      if(memory->frames[i].filledFlag == 0){
        return i;
      }
    }
  }
  srand(time(NULL));
	return (rand() % memory->framesQty);
}