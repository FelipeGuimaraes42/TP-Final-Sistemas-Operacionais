#include "../include/main.h"

int main(int argc, char **argv){
    
	char *alg = argv[1];
	FILE *file = fopen(argv[2], "r");
	int pageSize = atoi(argv[3]);
	int memSize = atoi(argv[4]);
	double executionTime = 0.0;

	// Validando entradas.
	if(file == NULL) {
		fprintf(stderr, "ERRO: Arquivo nao existe %s\n", argv[2]);
		return 1;
	}
    
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

	// Criando e preenchendo estrutura de dados.
	PageTable table;
	Memory memory;
	initializeStructures(&table, &memory, memSize, pageSize);

	// Algoritmo principal.
	clock_t start = clock();

	virtualMemorySimulator(&table, &memory, file, alg);

	clock_t end = clock();
	executionTime = (double)(end - start) / CLOCKS_PER_SEC;

	// Mensagens de saída no formato desejado.
	fprintf(stdout, "Executando o simulador ... \n");
  fprintf(stdout, "Arquivo de entrada: %s \n", argv[2]);
	fprintf(stdout, "Tamanho da memoria: %d KB \n", memSize);
	fprintf(stdout, "Tamanho das paginas: %d KB \n", pageSize);
	fprintf(stdout, "Tecnica de reposicao: %s \n", alg);
	fprintf(stdout, "Paginas lidas: %d \n", memory.pagesRead);
	fprintf(stdout, "Paginas escritas: %d \n", memory.pagesToWrite);
	fprintf(stdout, "Tempo de execucao = %lf segundos. \n", executionTime);

	// Armazenando dados para análise de performance.
	FILE *logTempos;
	logTempos = fopen("desempenho/tempos.csv", "a");
	if (logTempos == NULL) {
    perror("Não foi possível abrir o arquivo que armazena os tempos.\n");
	}
	fprintf(logTempos, "%lf, " ,executionTime);

	// Libera memória alocada dinamicamente.
	free(memory.frames);
	free(table.pages);

	//Fecha arquivos.
	fclose(logTempos);
	fclose(file);

	return 0;
}