// Quante volte NON ti sei ricordato una password?
// puoi provare questo programma: ti da un tabulato
// di quante password vuoi tu: ricordati solo il numero
// della password usata e ... non dimenticarti l'unica password
// iniziale!!!
// Nb: cancella pure il tabulato delle password,
// lo puoi sempre ricreare identico, ricordandoti 
// SOLO la password iniziale 

//NB: password create della lunghezza della parola iniziale
//    e ottenute con minuscole/MAIUSCOLE/punteggiatura

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char paswd[128+2]; // Max lunghezza password 128 caratteri

char *password(char paswd[]) {
	int i;
	int c;
	static long base=0x12345678;
	int len = strlen(paswd);
	for (i=0; i<len; i++) {

		paswd[i]=(long)paswd[i] ^ base;
		base--;
		c = paswd[i];
		while(!(isalpha(c) || isalnum(c) || ispunct(c))) {
			paswd[i]=(long)paswd[i] ^ base;
			base--;
			c = paswd[i];
			if (c <'!' || c > 'z' || (ispunct(c) && (i % 4 !=0)))
				c=0;
		}
	}
	return(paswd);
}

int main() {
	int i,quante;
	FILE *fd;
	if ((fd = fopen("password.txt","w"))==0)
		printf("\nNon riesco ad aprire in scrittura il file password.txt\n\7"),exit(0);

	printf("Password di base (Almeno 8 caratteri)--->");
	gets(paswd);
	printf("Quante password genero ?--->");
	scanf("%d",&quante);

	fprintf(fd,"Password Base=[%s]\n",paswd);
	for (i=0; i < quante; i++) {
		fprintf(fd,"Password N. [%3d] = %s\n",i+1,password(paswd));
	}
	fclose(fd);
	printf("\nFile password.txt creato con successo!\n");
}
