/*
3 fonctions
	- struct element * ajout (int donne, struct element *tete);
	- void parcours (struct element *tete);
	- void libere (struct element tete)
Après avoir fais sa:
	- struct element *ajout queue (int donne, struct element *queue);
*/

# include <stdio.h>
# include <stdlib.h>

struct element
{
	int data;
	struct element * suiv;
};
struct element* ajout (int donne, struct element *tete);
void parcours (struct element *tete);
void libere (struct element *tete);
