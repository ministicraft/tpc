#include <stdio.h>
#include <string.h>
#define LG_MAX 10
int main (){
int compteur=0;
int i=0;
char chaine [LG_MAX];
printf("Rentrer votre chaine de caractère:");
//====================================================================================
//Saisie de la chaine
//====================================================================================

//Avec controle de la longueur

fgets(chaine,LG_MAX,stdin); // Plus recommander que gets
if (chaine[strlen(chaine)-1] == '\n') chaine[strlen(chaine)-1]='\0'; // obligatoire avec fgets contrairement à gets

//Sans controle de la longueur

//gets (chaine); // Pas idéal source de hack
//====================================================================================
//Calcule de la longueur de la chaine
//====================================================================================
for (i=0; i<LG_MAX; i++)
	{
	if (chaine[i]=='\0')
		{
		break;
		}
	compteur++;
	}
//====================================================================================
//Affichage de la longueur
//====================================================================================
printf ("La chaine fais %d carcactère.\n", compteur);
return 0;
}
