#include "../include/main.h"

int main(int argc, char **argv){
    
	char *alg = argv[1];
	FILE *file = fopen(argv[2], "r");
	int pageSize = atoi(argv[3]);
	int memSize = atoi(argv[4]);
	char *execType = argv[5];
	double executionTime = 0.0;

	// Validando entradas.
	if(file == NULL) {
		fprintf(stderr, "ERRO: Arquivo nao existe %s\n", argv[2]);
		return 1;
	}
    
	if(argc != 6){
		fprintf(stderr, "ERRO: Numero de argumentos incorreto para a executacao do programa.\n");
		return 1;
	}

	if(pageSize < 2 || pageSize > 64){	
		fprintf(stderr, "ERRO: O tamanho de cada pagina nao deve ser menor que 2 nem maior que 64.\n");
		return 1;
	}
		
	if(memSize < 128 || memSize > 16384){
		fprintf(stderr, "ERRO: O tamanho da memoria nao deve ser menor que 128 nem maior que 16384.\n");
		return 1;
	}

	if((strcmp(alg, "lru") != 0) && (strcmp(alg, "fifo") != 0) && (strcmp(alg,"lefe") != 0)){
		fprintf(stderr, "ERRO: O algoritmo deve ser lru, fifo ou lefe.\n");
		return 1;
	}

	// Criando e preenchendo estrutura de dados.
	PageTable table;
	Memory memory;
	initializeStructures(&table, &memory, memSize, pageSize);

	// Algoritmo principal.
	clock_t start = clock();

	virtualMemorySimulator(&table, &memory, file, alg);

	clock_t end = clock();
	executionTime = (double)(end - start) / CLOCKS_PER_SEC;

	// Criando path para arquivo.
  char path[100] = "";
  char _sep_[1] = "_";
	char buffer[10];
	if ((strcmp(execType, "pageConst"))) {
		strcat(path, "desempenho/memSizeConst/");
	}
	if ((strcmp(execType, "memConst"))) {
		strcat(path, "desempenho/pageSizeConst/");
	}
  strcat(path, argv[2]);
  strcat(path, _sep_);
  strcat(path, alg);
  strcat(path, _sep_);
	itoa(pageSize, buffer, 10);
  strcat(path, buffer);
	buffer[0] = '\0';
  strcat(path, _sep_);
  itoa(memSize, buffer, 10);
  strcat(path, buffer);
  strcat(path, ".csv");

	// Armazenando dados para análise de performance.
	FILE *logTempos;
	logTempos = fopen(path, "a");
	if (logTempos == NULL) {
    perror("Não foi possível abrir o arquivo que armazena os tempos.\n");
	}
	fprintf(logTempos, "%lf," ,executionTime);

	// Libera memória alocada dinamicamente.
	free(memory.frames);
	free(table.pages);

	//Fecha arquivos.
	fclose(logTempos);
	fclose(file);

	return 0;
}