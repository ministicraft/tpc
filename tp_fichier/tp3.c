# define LMAXLIGNE 80
# include <stdio.h>

int main()
{
	FILE* fp = NULL;
	char ligne [LMAXLIGNE+1];

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

	if((fp=fopen("mon_fichier.txt","r"))==NULL)
	{
		printf("Erreur, impossible d'ouvrir le fichier");
		return 1;
	}

	struct client un_client;
	int num_client=1;
/*	while (fread (&un_client, sizeof(struct client),1,fp))
	{
		printf("client %d: %s %s a %d Euros. \n", num_client, un_client.nom, un_client.prenom, un_client.solde);
		num_client++;
	}*/

	// fseek(fp, sizeof(struct client)*1, SEEK_SET);
	// fseek(fp, sizeof(struct client)*1, SEEK_END-1);
	fseek(fp, sizeof(struct client)*1, SEEK_CUR-1);

	while (fread (&un_client, sizeof(struct client),1,fp))
	{
		printf("client %d: %s %s a %d Euros. \n", num_client, un_client.nom, un_client.prenom, un_client.solde);
		num_client++;
	}

	fclose(fp);
	return 0;
}
