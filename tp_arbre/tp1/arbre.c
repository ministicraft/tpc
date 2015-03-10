#include "arbre.h"

Noeud *inserer(char *fr, char *en, Noeud * racine)
{
	if (racine==NULL)
	{
		Noeud * newNoeud = NULL;
		newNoeud = malloc(sizeof(Noeud));

		newNoeud->fr = malloc((strlen(fr)+1)*sizeof(char));
		strcpy(newNoeud->fr,fr);

		newNoeud->en = malloc((strlen(en)+1)*sizeof(char));
		strcpy(newNoeud->en,en);

		newNoeud->filsG = NULL;
		newNoeud->filsD = NULL;
		racine = newNoeud;
	}
	else if(strcmp(fr,racine->fr) < 0)
	{
		racine->filsG = inserer(fr, en, racine->filsG);
	}
	else if(strcmp(fr,racine->fr ) > 0)
	{
		racine->filsD = inserer(fr, en, racine->filsD);
	}
	else
	{
		printf("Se mot existe déjà.\n");
	}
	return racine;
}

char * traduction (char* fr, Noeud* racine)
{
	if(strcmp(fr,racine->fr) < 0)
	{
		traduction(fr, racine->filsG);
	}
	else if(strcmp(fr,racine->fr ) > 0)
	{
		traduction(fr, racine->filsD);
	}
	else if(strcmp(fr,racine->fr ) == 0)
	{
		return racine->en;
	}
	else
	{
		printf("Se mot n'existe pas dans cette bibliotheque");
	}
}


void affichage (Noeud* noeud)
{
	if (noeud != NULL)
	{
		printf("\n-----------------\n");
		printf("%s\n",noeud->fr);
		printf("%s\n",noeud->en);
		if (noeud->filsD != NULL)
		{
			printf("%p\n",noeud->filsD);
		}
		if (noeud->filsG != NULL)
		{
			printf("%p\n",noeud->filsG);
		}
		printf("-----------------\n");
	}
}

void parcoursGRD (Noeud* racine)
{
	affichage (racine);
	if (racine->filsD != NULL)
	{
		parcoursGRD (racine->filsD);
	}
	if (racine->filsD != NULL)
	{
		parcoursGRD (racine->filsG);
	}
}


