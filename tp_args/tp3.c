#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int test (char* arg)
{
	int i=0;
	int debut=0;
	if (arg[0]=='-') debut=1;
	for(i=debut;i<strlen(arg);i++)
	{
		/*if(arg[0]=='-')*/
		if(arg[i]>'9' && arg[i]<'0')
		{
			return 0;
		}
	}
	return 1;
}


int main (int argc, char **argv)
{
	int *tab_entier=NULL; // alloué dynamiquement selon le nb d'argument passé au prog
	int somme=0;
	int n=0;
	int i=0;
	float moyenne;
	tab_entier=malloc((argc-1)*sizeof(int));
	for (i=0; i<argc-1; i++)
	{
		if(!test(argv[i+1]))
		{
			n++;
			somme=somme+atoi(argv[i+1]);
			tab_entier[i]=atoi(argv[i+1]);
		}
	}
	moyenne= (float) somme/n;
	printf("Nombre d'entier: %d\nSomme: %d\nMoyenne: %f\n",n,somme,moyenne);
	free(tab_entier);
	return 0;
}
