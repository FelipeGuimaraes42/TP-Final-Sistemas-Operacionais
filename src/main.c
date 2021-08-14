#include "../include/main.h"

// Leandro

int main(int argc, char **argv){
    
	char *alg = argv[1];
	char *arq = argv[2];
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

	// Criando variáveis e determinando o offset ...
	char rw; // Caractere que representa a operação - 'R' = read ; 'W' = write.
	char end[7]; // Endereço de memória em hexadecimal.
	int offset, pagEncontradaEm, pagLivreEm, idAlg;
	unsigned numPagVirt;
	unsigned int endInt;

	offset = determinarOffset(numPag); // Necessário para determinar a página virtual
	pagEncontradaEm = pagLivreEm = idAlg = 0;

	clock_t inicio = clock();

	FILE *lerArq = fopen(arq, "r");
	if (lerArq != NULL) {
		while (fscanf(lerArq, "%s %c", end, &rw) != EOF) {
			
			end[7] = '\0';
			endInt = (int) strtol(end, NULL, 16);
			numPagVirt = endInt >> offset;
			pagEncontradaEm = encontrarEndereco(tabela, numPag, end);
      idAlg++;

			if (rw == 'R') {
				rel.oppValidas ++;
				rel.leituras ++;
			}
			else if (rw == 'W') {
				rel.oppValidas ++;
				rel.escritas ++;
			}
			else {
				rel.oppInvalidas ++;
			}

			// Se não encontrar um endereço para a iteração atual
      if(pagEncontradaEm == -1){
        rel.pageFaults ++;
        pagLivreEm = encontrarPaginaLivre(tabela, numPag);
				// Se não houver páginas livres
        if(pagLivreEm == -1){
          if(rw == 'W'){
            rel.pagSujas ++;
          }

					if(!strcmp(alg,"fifo")){
						pagLivreEm = fifo(tabela, numPag);
						escreverNaTabela(tabela, numPag, end, numPagVirt);
						tabela[pagLivreEm].IdAlgoritmo = idAlg;
					}
					else if(!strcmp(alg,"lefe")){
						fprintf(stderr, "Lefe ainda não foi implementado. \n");
					}
					else if(!strcmp(alg, "lru")){
            pagLivreEm = lru(tabela, numPag);
            escreverNaTabela(tabela, numPag, end, numPagVirt);
            tabela[pagLivreEm].IdAlgoritmo = idAlg; 
          }
        }
				else{
					escreverNaTabela(tabela, numPag, end, numPagVirt);
					if(!strcmp(alg,"fifo") || !strcmp(alg,"lru")) {
						tabela[pagLivreEm].IdAlgoritmo = idAlg;
					}
					// ...
				}
      }
			// Do contrário, houve hits, ou seja achamos o desejado na
			// pagina encontrada para a iteração atual.
			else {
				rel.hits ++;
				// ...
			}
		}
	}
	else {
		fprintf(stderr, "Não foi possível ler o arquivo de entrada.\n");
		return 1;
	}

	fclose(lerArq);

	clock_t fim = clock();
	executionTime = (double)(inicio - fim) / CLOCKS_PER_SEC;

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

	return 0;
}