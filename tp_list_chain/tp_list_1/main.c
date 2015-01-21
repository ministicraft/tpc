# include "liste.h"

int main ()
{
	struct element *tete = NULL;
	tete = ajout(12, tete);
	tete = ajout (45, tete);
	tete = ajout (17, tete);
	parcours (tete);
	libere (tete);
	return;
}
