#include <stdio.h>
#include <string.h>
#define LG_MAX 100
int main () {
char chaine_src[LG_MAX],chaine_des[LG_MAX];
char *ptr_src= NULL;
char *ptr_des= NULL;

//===================================================================================
//Saisie de la chaine
//===================================================================================
printf("Veuiller saisir votre chaine: ");
fgets ( chaine_src, LG_MAX+1, stdin);
if (chaine_src[strlen(chaine_src)-1]=='\n') chaine_src[strlen(chaine_src)-1]='\0';
//===================================================================================
//Recopie de la chaine
//===================================================================================
ptr_src=chaine_src;
ptr_des=chaine_des;
while (*ptr_src != '\0')
	{
	*ptr_des=*ptr_src;
	ptr_src++;
	ptr_des++;
	}
*ptr_des='\0';
//===================================================================================
//Affichage de la chaine
//===================================================================================
printf("La chaine recopier est: ");
printf("%s\n", chaine_des);
return 0;
}
