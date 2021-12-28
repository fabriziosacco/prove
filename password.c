#include <stdio.h>
#include <ctype.h>

char paswd[128];

char *password(char paswd[])
{
	int i;
	int c;
	static long base=0x12345678;
	int len = strlen(paswd);
	for (i=0; i<len; i++)
	{
		
		paswd[i]=(long)paswd[i] ^ base;
		base--;
		c = paswd[i];
		while(!(isalpha(c) || isalnum(c)))
		{
			paswd[i]=(long)paswd[i] ^ base;
			base--;
			c = paswd[i];
			if (c <'A' || c > 'z')
				c=0;
		}
	}
	return(paswd);
}

int main()
{
	int i,quante;
	FILE *fd;
	if ((fd = fopen("password.txt","w"))==0)
		printf("\nNon riesco ad aprire in scruttura il file password.txt\n\7"),exit(0);
	
	printf("Password di base --->");
	gets(paswd);
	printf("Quante password genero ?--->");
	scanf("%d",&quante);
	
	for (i=0; i < quante; i++)
	{
		fprintf(fd,"Password N. [%3d] = [%s]\n",i+1,password(paswd));
	}
	fclose(fd);
	printf("\nFile password.txt creato con successo!\n");
}