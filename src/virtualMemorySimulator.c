#include "../include/virtualMemorySimulator.h"

// Felipe

void virtualMemorySimulator(PageTable *table, Memory *memory, FILE *arq, char *alg) {
  unsigned addr, frame, index;
  unsigned offset = 0;
  char rw;

  // Determinando as paginas - olhar expecificação
  unsigned tmp = table->pageSize * 1024;
  while (tmp > 1) {
    tmp = tmp >> 1;
    offset ++;
  }

  while (!feof(arq)) {
    fscanf(arq, "%x %c", &addr, &rw);
    index = addr >> offset;

    if (!feof(arq)) {
      if (table->pages[index].loadedFlag == 1) { // caso a pagina ja esteja carregada, iremos acessar normalmente
        table->pages[index].secondChanceFlag = 1;
        table->pages[index].clockAccess = memory->clock;
      }
      else { // caso contrario, deveremos encontrar um quadro para ela
        memory->pagesRead++;

        // uma vez que a quantidade de letras do algoritmo é diferente, podemos
        // utilizar o tamanho da tecnica de reposição passada pra executar
        switch (strlen(alg)) {
        case 2: // CASO 1: 2A - SEGUNDA CHANCE -
          frame = segunda_chance(memory, table);
          break;
        case 3: // CASO 2: LRU
          frame = lru(memory, table);
          break;
        case 4: // CASO 3: FIFO
          frame = fifo(memory, table);
          break;
        case 6: // CASO 4: RANDOM
          frame = aleatorio(memory);
          break;
        default:
          printf("Tecnica de respoicao nao conhecida");
        }

        if (memory->frames[frame].filledFlag) {
          libera_frame_flagPreenchido(memory, table, frame);
          carrega_pagina(memory, table, index, frame);
        }
      }
      if (rw == 'W') {
        table->pages[index].dirtyFlag = 1;
      }
    }
  }
}