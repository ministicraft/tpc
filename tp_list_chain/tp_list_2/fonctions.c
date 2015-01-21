# include "liste.h"

struct element* ajout (int donne, struct element *tete)
{
	struct element * newElement = NULL;
	newElement=malloc(sizeof(struct element));
	newElement->data=donne;
	newElement->suiv=tete;
	return newElement;
}

struct element* ajout_queue (int donne, struct element *queue)
{
	struct element * newElement = NULL;
	newElement=malloc(sizeof(struct element));
	newElement->data = donne;
	newElement->suiv = NULL;
	if (queue != NULL) {
		queue->suiv = newElement;
	}
	return newElement;
}

void parcours (struct element *tete)
{
	struct element * temp = tete;
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->suiv;
	}
}

void libere (struct element *tete)
{
	struct element *temp = tete;
	struct element *temp2 = NULL;
	while(temp != NULL)
	{
		temp2 = temp->suiv;
		free (temp);
		temp = temp2;
	}
}
