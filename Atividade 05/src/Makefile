main: main.o arvore.o
	gcc $(CFLAGS) -o main main.o arvore.o
main.o: main.c arvore.h
	gcc $(CFLAGS) -c main.c
arvore.o: arvore.c arvore.h
	gcc $(CFLAGS) -c arvore.c
clean:
	rm -f *.o main