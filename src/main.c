#include "main.h"

int main(int argc, char **argv){
    
    char *algorithm = argv[1];
	char *file = argv[2];
	int pageSize = atoi(argv[3]);
	int memorySize = atoi(argv[4]);
    
    if(argc != 5){
        printf("ERRO: Numero de argumentos incorreto para a executacao do programa.\n");
        return 1;
    }

	if(pageSize < 2 || pageSize > 64){	
		printf("ERRO: O tamanho de cada pagina nao deve ser menor que 2 nem maior que 64.");
		return 1;
	}
		
	if(memorySize < 128 || memorySize > 16384){
		printf("ERRO: O tamanho da memoria nao deve ser menor que 128 nem maior que 16384.");
		return 1;
	}

    //Não sei se essa logica funciona ainda, mas acredito que sim
    if((strcmp(algorithm, "lru") != 0) && (strcmp(algorithm, "fifo") != 0) && (strcmp(algorithm,"lefe") != 0)){
		printf("ERRO: O algoritmo deve ser lru, fifo ou lefe.");
		return 1;
	}

    return 0;
}