/*
Hércules Ismael de Abreu Santos - 16/0124450
André Eduardo Souza de Oliveira - 16/0111978
Hugo Aragão de Oliveira - 16/0124581
*/

// Síntese
// Objetivo: Organizar fila de vôos de aeroporto
// Entrada:
// Saída: log dos acontecimentos do aeroporto

#include <stdio.h>
#include "fila.h"

void initRelogio(char *relogio);
void incRelogio(char *relogio);

int main(){
  //Declarações:
  int i;
	char relogio[6];
  //Instruções:
  

  return 0;
}

void initRelogio(char *relogio){
	strcpy(relogio, "23:52");

	return;
}

void incRelogio(char *relogio){
	int hora=0;
	int minutos;

	minutos=*(relogio+4)-'0';
	minutos+=(*(relogio+3)-'0')*10;
	hora=*(relogio+1)-'0';
	hora+=(*(relogio)-'0')*10;

	if(minutos>=55)
		hora=(hora+1)%24;
	minutos=(minutos+5)%60;

	relogio[0]=hora/10+'0';
	relogio[1]=hora%10+'0';
	relogio[3]=minutos/10+'0';
	relogio[4]=minutos%10+'0';

	return;
}
