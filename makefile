all:
	gcc -Wall -c src/main.c src/auxiliary.c src/algorithms.c src/virtualMemorySimulator.c
	gcc -Wall -Wextra -std=c11 -ggdb3 main.o auxiliary.o algorithms.o virtualMemorySimulator.o -o tp2virtual
example:
	./tp2virtual lru logs/compilador.log 4 16384
clean:
	rm tp2virtual
	rm *.o