# include <stdio.h>
# include <stdlib.h>

struct element
{
	int data;
	struct element * suiv;
};
int main ()
{
	struct element * tete = NULL;
	/*Création du premier élément*/
	tete=malloc(sizeof(struct element));
	tete->data=12;
	tete->suiv=NULL;
	/*Création du deuxième élément*/
	struct element * newElement = NULL;
	newElement=malloc(sizeof(struct element));
	newElement->data=45;
	newElement->suiv=tete;
	tete=newElement;
	/*Affichage de la liste chainé*/
	struct element * temp = tete;
	while(temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->suiv;
	}
}
