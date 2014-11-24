# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# define TAILLE_MAX 100
//============================================================================================
//Fonction voyelles
//============================================================================================
char * voyelles (const char *chaine)//char* pointeur sur char
{
	int i=0;
	int j=0;
	char *voy=malloc((strlen(chaine)+1)*sizeof(char));
	for (i=0;i<strlen(chaine);i++)
		{
		if (chaine[i]=='a' || chaine[i]=='e' || chaine[i]=='i' || chaine[i]=='o' || chaine[i]=='u' || chaine[i]=='y')
			{
			voy[j]=chaine[i];
			j++;
			}
		}
	voy[j]='\0';
	return voy;
	// retourne une adresse car un tableau est l'adresse du debut du tableau
}
//============================================================================================
//Fonction main
//============================================================================================
int main()
{
	char chaine[TAILLE_MAX+1];
	int nb_voy=0;
	char* chaine_voy=NULL;// Déclaration d'un pointeur sur char
	printf("Saisir la chaine: ");
	fgets ( chaine, TAILLE_MAX+1, stdin);
	if (chaine[strlen(chaine)-1]=='\n') chaine[strlen(chaine)-1]='\0';
	chaine_voy=voyelles(chaine);// stock le retour dans un pointeur = tableaux
	printf ("Les voyelles utiliser sont: %s\n",chaine_voy);
	printf ("Nombre de voyelles:%ld\n",strlen(chaine_voy));
	free (chaine_voy);
	return 0;
}
