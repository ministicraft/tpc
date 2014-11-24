# include <stdio.h>
# include <string.h>
# define TAILLE_MAX 100
//==============================================================================================
//Fonction voyelles
//==============================================================================================
int voyelles(char *chaine)//char* pointeur sur char
{
	int i=0;
	int j=0;
	for (i=0;i<strlen(chaine);i++)
		{
		if (chaine[i]=='a' || chaine[i]=='e' || chaine[i]=='i' || chaine[i]=='o' || chaine[i]=='u' || chaine[i]=='y')
			{
			chaine[j]=chaine[i];
			j++;
			}
		}
	chaine[j]='\0';
	return j;
}
//==============================================================================================
//Fonction main
//==============================================================================================
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
