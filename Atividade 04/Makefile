main: main.o fila.o
	gcc $(CFLAGS) -o main main.o fila.o
main.o: main.c fila.h
	gcc $(CFLAGS) -c main.c
fila.o: fila.c fila.h
	gcc $(CFLAGS) -c fila.c
clean:
	rm -f *.o main
