# define LMAXLIGNE 80
# include <stdio.h>

int main()
{
	FILE* fp = NULL;
	char ligne [LMAXLIGNE+1];

	//Etape 1

	if((fp = fopen("mon_fichier.txt","w"))==NULL)
	{
		printf("Erreur, impossible d'ouvrir le fichier");
		return 1;
	}
	fprintf(fp,"Ici c'est les CIR\n");
	fclose(fp);
	getchar();

	//Etape 2

	if((fp = fopen("mon_fichier.txt","r"))==NULL)
	{
		printf("Erreur, impossible d'ouvrir le fichier");
		return 1;
	}
	int compteur_ligne = 0;
	while (fgets(ligne,LMAXLIGNE,fp))
	{
		printf("%s",ligne);
		compteur_ligne++;
	}
	printf("Il y a %d ligne",compteur_ligne);
	fclose(fp);
	getchar();

	//Etape 3

	if((fp=fopen("mon_fichier.txt","a"))==NULL)
	{
		printf("Erreur, impossible d'ouvrir le fichier");
		return 1;
	}
	fprintf(fp,"Bonjour\ntout le monde\n");
	fclose (fp);
	return 0;
}
