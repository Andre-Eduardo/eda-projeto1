main: main.o arvore.o
	gcc $(CFLAGS) -o main main.o arvore.o -lm
main.o: main.c arvore.h
	gcc $(CFLAGS) -c main.c -lm 
arvore.o: arvore.c arvore.h
	gcc $(CFLAGS) -c arvore.c -lm
clean:
	rm -f *.o main