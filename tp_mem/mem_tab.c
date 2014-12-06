#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LG_MAX 100
int main()
{
	char chaine_saisie[LG_MAX]={0};
	printf("Saisir la chaine: ");
	fgets ( chaine_saisie, LG_MAX+1, stdin);
	if (chaine_saisie[strlen(chaine_saisie)-1]=='\n') chaine_saisie[strlen(chaine_saisie)-1]='\0';
	char*chaine_dest=malloc((strlen(chaine_saisie)+1)*sizeof(char));
	//+1 car strlen ne prend pas \0
	strcpy(chaine_dest,chaine_saisie);
	printf("Chaine dest est: %s\n", chaine_dest);
	return 0;
}
