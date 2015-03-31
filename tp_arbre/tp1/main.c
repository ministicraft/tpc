#include "arbre.h"

int main (int argc , char *argv[])
{
	if (argc == 1)
	{
		printf("Erreur: Il faut passer le nom du fichier à ouvrir en argument.\n");
		return 1;
	}
	int hauteur = 0;
	Noeud * racine = NULL;
	racine = creation(argv[1]);
	printf("La hauteur de l'arbre est: %d\n",hauteur_arbre (racine));
	DSWBalancingAlgorithm(racine);
	printf("La hauteur de l'arbre est: %d\n",hauteur_arbre (racine));
	libere_noeud(racine);

	return 0;
}
