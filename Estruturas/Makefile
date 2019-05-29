main: main.o lista.o
	gcc $(CFLAGS) -o main main.o lista.o
main.o: main.c lista.h
	gcc $(CFLAGS) -c main.c
lista.o: lista.c lista.h
	gcc $(CFLAGS) -c lista.c
clean:
	rm -f *.o main
