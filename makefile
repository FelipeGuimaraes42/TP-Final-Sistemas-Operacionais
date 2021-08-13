all:
	gcc -Wall -c src/main.c src/auxiliar.c src/fifo.c src/lru.c src/tabelaDePaginas.c
	gcc -Wall -Wextra -std=c11 -ggdb3 main.o auxiliar.o fifo.o lru.o tabelaDePaginas.o -o tp2virtual
example:
	./tp2virtual lefe logs/compilador.log 4 128
clean:
	rm tp2virtual
	rm *.o