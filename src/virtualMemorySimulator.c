#include "../include/virtualMemorySimulator.h"

void virtualMemorySimulator(PageTable *table, Memory *memory, FILE *file, char *alg) {
  unsigned addr, frame, index;
  unsigned offset = 0;
  char rw;

  // Determinando as paginas - olhar expecificação
  unsigned aux = table->pageSize * 1024;
  while (aux > 1) {
    aux = aux >> 1;
    offset ++;
  }

  while (!feof(file)) {
    fscanf(file, "%x %c", &addr, &rw);
    index = addr >> offset;

    if (!feof(file)) {
      if (table->pages[index].loadedFlag == 1) { // caso a pagina ja esteja carregada, iremos acessar normalmente
        table->pages[index].secondChanceFlag = 1;
        table->pages[index].clockAccess = memory->clock;
      }
      else { // caso contrario, deveremos encontrar um quadro para ela
        memory->pagesRead++;

        if(strcmp(alg, "fifo") == 0){
          frame = fifo(table, memory);

        }else if(strcmp(alg, "lru") == 0){
          frame = lru(table, memory);

        }else if(!strcmp(alg, "lefe") == 0){
          frame = lefe(memory);

        }else{
          printf("ERRO: Algoritmo nao encontrado\n");
          exit(1);
        }

        if (memory->frames[frame].filledFlag) {
          freeFullFrame(table, memory, frame);
        }
        
        loadPage(table, memory, frame, index);
      }
      if (rw == 'W') {
        table->pages[index].dirtyFlag = 1;
      }
    }
  }
}