main: main.o funcoes.o
	gcc $(CFLAGS) -o main main.o funcoes.o -lm
main.o: main.c funcoes.h
	gcc $(CFLAGS) -c main.c -lm 
funcoes.o: funcoes.c funcoes.h
	gcc $(CFLAGS) -c funcoes.c -lm
clean:
	rm -f *.o main
