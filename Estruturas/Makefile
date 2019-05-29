main: main.o pilha.o
	gcc $(CFLAGS) -o main main.o pilha.o
main.o: main.c pilha.h
	gcc $(CFLAGS) -c main.c
pilha.o: pilha.c pilha.h
	gcc $(CFLAGS) -c pilha.c
clean:
	rm -f *.o main
