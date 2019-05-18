agenda: agenda.o listaContatos.o
	gcc $(CFLAGS) -o agenda agenda.o listaContatos.o
agenda.o: agenda.c listaContatos.h
	gcc $(CFLAGS) -c agenda.c
listaContatos.o: listaContatos.c listaContatos.h
	gcc $(CFLAGS) -c listaContatos.c
clean:
	rm -f *.o agenda
