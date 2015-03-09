#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noeud
{
	char *fr;
	char *en;
	struct noeud * filsG;
	struct noeud * filsD;
};
typedef struct noeud Noeud;


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
		printf("filsG\n");
		racine->filsG = inserer(fr, en, racine->filsG);
	}
	else if(strcmp(fr,racine->fr ) > 0)
	{
		printf("filsD\n");
		racine->filsD = inserer(fr, en, racine->filsD);
	}
	else
	{
		printf("Se mot existe déjà.\n");
	}
	return racine;
}


int main ()
{
Noeud * racine = NULL;
racine = inserer("avion","plane",racine);
printf("FR: %s\nEN: %s\n",racine->fr, racine->en);
racine = inserer("age", "age", racine);
printf("FR: %s\nEN: %s\n",racine->filsG->fr, racine->filsG->en);
racine = inserer("noeud", "node", racine);
printf("FR: %s\nEN: %s\n",racine->filsD->fr, racine->filsD->en);

}
