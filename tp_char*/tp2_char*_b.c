#include <stdio.h>
#include <string.h>
#define LG_MAX 100
int main () {
int i=0;
char chaine_src[LG_MAX],chaine_des[LG_MAX];

//===================================================================================
//Saisie de la chaine
//===================================================================================
printf("Veuiller saisir votre chaine: ");
fgets ( chaine_src, LG_MAX+1, stdin);
if (chaine_src[strlen(chaine_src)-1]=='\n') chaine_src[strlen(chaine_src)-1]='\0';
//===================================================================================
//Recopie de la chaine
//===================================================================================
while (chaine_src[i]!='\0')
	{
	chaine_des[i]=chaine_src[i];
	i++;
	}
chaine_des[i]='\0';
//===================================================================================
//Affichage de la chaine
//===================================================================================
printf("La chaine recopier est: ");
printf("%s\n", chaine_des);
return 0;
}
