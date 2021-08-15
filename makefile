all:
	gcc -Wall -c src/main.c src/auxiliary.c src/algorithms.c src/virtualMemorySimulator.c
	gcc -Wall -Wextra -std=c11 -ggdb3 main.o auxiliary.o algorithms.o virtualMemorySimulator.o -o tp2virtual
data:
	rm -f *.o $(EXEC)
	gcc -Wall -c src/data.c src/auxiliary.c src/algorithms.c src/virtualMemorySimulator.c
	gcc -Wall -Wextra -std=c11 -ggdb3 data.o auxiliary.o algorithms.o virtualMemorySimulator.o -o genData
example:
	./tp2virtual lru logs/compilador.log 4 2048
clean:
	rm tp2virtual
	rm genData
	rm *.o