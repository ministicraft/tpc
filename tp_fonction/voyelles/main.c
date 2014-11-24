# include "voyelles.h"
int main()
{
	char chaine[TAILLE_MAX+1];
	int nb_voy=0;
	printf("Saisir la chaine: ");
	fgets ( chaine, TAILLE_MAX+1, stdin);
	if (chaine[strlen(chaine)-1]=='\n') chaine[strlen(chaine)-1]='\0';
	printf ("Nombre de voyelles:%d\n",voyelles(chaine));
	printf ("Les voyelles utiliser sont: %s\n",chaine);
	return 0;
}
