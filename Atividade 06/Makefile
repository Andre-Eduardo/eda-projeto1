main: main.o funcoes.o identificador_de_solo.o
	gcc $(CFLAGS) -o main main.o funcoes.o identificador_de_solo.o -lm
main.o: main.c funcoes.h identificador_de_solo.h
	gcc $(CFLAGS) -c main.c -lm
funcoes.o: funcoes.c funcoes.h
	gcc $(CFLAGS) -c funcoes.c -lm
identificador_de_solo.o: identificador_de_solo.c identificador_de_solo.h
	gcc $(CFLAGS) -c identificador_de_solo.c -lm
clean:
	rm -f *.o main
