#include "../include/main.h"

int main(int argc, char **argv){
    
	char *alg = argv[1];
	char *arq = argv[2];
	int tamPag = atoi(argv[3]);
	int tamMem = atoi(argv[4]);
	double tempoGasto = 0.0;
    
	if(argc != 5){
		fprintf(stderr, "ERRO: Numero de argumentos incorreto para a executacao do programa.\n");
		return 1;
	}

	if(tamPag < 2 || tamPag > 64){	
		fprintf(stderr, "ERRO: O tamanho de cada pagina nao deve ser menor que 2 nem maior que 64.\n");
		return 1;
	}
		
	if(tamMem < 128 || tamMem > 16384){
		fprintf(stderr, "ERRO: O tamanho da memoria nao deve ser menor que 128 nem maior que 16384.\n");
		return 1;
	}

	// Não sei se essa logica funciona ainda, mas acredito que sim.
	if((strcmp(alg, "lru") != 0) && (strcmp(alg, "fifo") != 0) && (strcmp(alg,"lefe") != 0)){
		fprintf(stderr, "ERRO: O algoritmo deve ser lru, fifo ou lefe.\n");
		return 1;
	}

	// ... Criação da estrutura TabelaPaginas e seu preenchimento ...

	clock_t inicio = clock();

	FILE *lerArq = fopen(arq, "r");
	if (lerArq != NULL) {
		// ... 
	}
	else {
		fprintf(stderr, "Não foi possível ler o arquivo de entrada.\n");
		return 1;
	}

	fclose(lerArq);

	clock_t fim = clock();
	tempoGasto = (double)(inicio - fim) / CLOCKS_PER_SEC;

	// ... Mensagens de saída no formato desejado ...

	fprintf(stdout, "Tempo de execucao = %lf seg", tempoGasto);

	// Armazenando dados para análise de performance.
	FILE *logTempos;
	logTempos = fopen("desempenho/tempos.csv", "a");
	if (logTempos == NULL) {
    perror("Não foi possível abrir o arquivo que armazena os tempos.\n");
	}
	fprintf(logTempos, "%lf, " ,tempoGasto);
	fclose(logTempos);

	return 0;
}