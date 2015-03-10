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

Noeud *inserer(char *fr, char *en, Noeud * racine);
char * traduction (char* fr, Noeud* racine);
void affichage (Noeud* noeud);
void parcoursGRD (Noeud* racine);
