#include "tabelaDePaginas.h"

void inicializaTabela(TabelaDePaginas *tabela, int numPaginas) {
    for(int i= 0; i< numPaginas; i++){
        tabela[i].bitSujo = -1;
        tabela[i].numeroPagina = -1;
        tabela[i].IdAlgoritmo = 0;
        tabela[i].bitValido = 0;
        memcpy(tabela[i].endereco, "", strlen("")+1);
    }
}