# How to run :

make -> runs makefile and generates the executable -> tp2virtual

The executable takes 4 arguments :

tp2virtual [substitutionAlgorithm] [logFile] [pageSize] [memorySize]

* [substitutionAlgorithm] Input one of the three available substitution algorithms [LRU], [FIFO] or a custom one designed by us [LEFE].
* [logFile] .log file containing the sequence of memory addresses accessed, such as the ones contained in the logs folder.
* [pageSize] the size of each page/memory frame, from 2 to 64 (in KB)
* [memorySize] the total size of physical memory available to the process, from 128 a 16384 (also in KB)

# Output format :

Ao final da simulação, quando a sequência de acessos à memória terminar, o programa deve gerar um pequeno relatório, contendo:

* a configuração utilizada (definida pelos quatro parâmetros);
* o número total de acessos à memória contidos no arquivo;
* o número de page faults (páginas lidas);
* o número de páginas “sujas” que tiveram que ser escritas de volta no disco (lembrando-se que páginas sujas que existam no final da execução não precisam ser escritas).

Um exemplo de saı́da poderia ser da forma (valores completamente fictı́cios):

$ tp2virtual lru arquivo.log 4 128

Executando o simulador...
Arquivo de entrada: arquivo.log
Tamanho da memoria: 128 KB
Tamanho das páginas: 4 KB
Tecnica de reposicao: lru
Paginas lidas: 520
Paginas escritas: 352
