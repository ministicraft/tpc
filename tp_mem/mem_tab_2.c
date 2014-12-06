#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LG_MAX 100
int main()
{
	int i=0;
	char chaine_saisie[LG_MAX]={0};
	char **tab_chaine=NULL;
	//Double pointeur
	//Pointeur qui pointe vers un tableaux de pointeur qui pointe vers la chaine de destination
	int nb_saisie=0;
	printf("Pour mettre fin au programme entrer fin.\n");
	do
	{
		printf("Saisir la chaine %d: ", i+1);
		fgets ( chaine_saisie, LG_MAX+1, stdin);
		if (chaine_saisie[strlen(chaine_saisie)-1]=='\n') chaine_saisie[strlen(chaine_saisie)-1]='\0';
		//Saisie de la chaine d'entrée

		if (strcmp(chaine_saisie,"fin"))
		//Condition d'arret si l'utilisateur entre "fin"
		{
			tab_chaine=realloc(tab_chaine,(1+i)*sizeof(char*));
			//Taille pointeur 8 octets
			//char* type pointeur
			//Réallocation de méoire pour le tableau de pointeur

			tab_chaine[i]=malloc((strlen(chaine_saisie)+1)*sizeof(char));
			//Allocation de memoire pour le tableaude destination

			strcpy(tab_chaine[i],chaine_saisie);
			//Copy de la saisie dans le tableau de destination

			i++;
		}
	}
	while (strcmp(chaine_saisie,"fin"));
	//Boucle infini

	nb_saisie = i;
	for (i=0;i<nb_saisie;i++)
	{
		printf("Chaine dest %d est: %s\n",i+1 ,tab_chaine[i]);
		free(tab_chaine[i]);
		//liberation de chaque tableau de destination
	}
	free(tab_chaine);
	//Liberation du tableau d'adresse
	return 0;
}
//Utilisation de valgrind pour voir les fuite mémoire et si tout les secteur sont libérer
//tab_chaine pointe vers un tableux de pointer qui pointe vers le tableau de destination [i]
