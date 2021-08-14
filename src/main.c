#include "../include/main.h"

// Leandro

int main(int argc, char **argv){
    
	char *alg = argv[1];
	FILE *file = argv[2];
	int pageSize = atoi(argv[3]);
	int memSize = atoi(argv[4]);
	double executionTime = 0.0;
    
	if(argc != 5){
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

	// Criando e preenchendo estrutura de dados ...
	PageTable table;
	Memory memory;
	Report report;
	initializeStructures(&table, &memory, &report, memSize, pageSize);

	// Algoritmo principal

	clock_t start = clock();

	virtualMemorySimulator(&table, &memory, fopen(file, "r"), alg);

	// ...

	clock_t end = clock();
	executionTime = (double)(start - end) / CLOCKS_PER_SEC;

	// ... Mensagens de saída no formato desejado ...
	fprintf(stdout, "Tempo de execucao = %lf seg\n", executionTime);

	// Armazenando dados para análise de performance.
	FILE *logTempos;
	logTempos = fopen("desempenho/tempos.csv", "a");
	if (logTempos == NULL) {
    perror("Não foi possível abrir o arquivo que armazena os tempos.\n");
	}
	fprintf(logTempos, "%lf, " ,executionTime);
	fclose(logTempos);

	printf("Arquivo de entrada: %s\n", argv[2]);
	printf("Tamanho da memoria: %s KB\n", argv[4]);
	printf("Tamanho das paginas: %s KB\n", argv[3]);
	printf("Tecnica de reposicao: %s\n", argv[1]);
	printf("Paginas lidas: %d\n", memory.pagesRead);
	printf("Paginas escritas: %d\n", memory.pagesToWrite);
	
	free(memory.frames);
	free(table.pages);

	fclose(file);

	return 0;
}