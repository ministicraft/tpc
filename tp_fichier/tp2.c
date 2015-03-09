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
	int a=12;
	fwrite(&a, sizeof(int),1,fp);
	fclose(fp);
	getchar();

	//Etape 2

	if((fp = fopen("mon_fichier.txt","w"))==NULL)
	{
		printf("Erreur, impossible d'ouvrir le fichier");
		return 1;
	}
	int tab[5] = {12,3214,26,0,7256};
	fwrite (tab, sizeof(int),5,fp);
	fclose(fp);
	getchar();

	//Etape 3

	if((fp=fopen("mon_fichier.txt","w"))==NULL)
	{
		printf("Erreur, impossible d'ouvrir le fichier");
		return 1;
	}
	struct client
	{
		char nom[10];
		char prenom[10];
		int solde;
	};
	struct client tab_client[2]={{"Dupont","Marcel",1000},{"Le Gall","Kevin",500}};
	fwrite(tab_client,sizeof(struct client),2,fp);
	fclose (fp);
	return 0;
}
