# include "liste.h"

int main ()
{
	struct element *tete = NULL, *queue = NULL;
	//tete = ajout(12, tete);
	//queue = tete;
	queue = ajout_queue (12, queue);
	tete=queue;
	queue = ajout_queue (45, queue);
	queue = ajout_queue (63, queue);
	parcours (tete);
	libere (tete);
	return;
}
