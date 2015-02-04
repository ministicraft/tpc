# include <stdio.h>
# include <stdlib.h>
struct monome
{
	float c;
	int e;
	struct monome * suiv;
};
struct monome* F_AjoutM (float coef, int puissance, struct monome *tete)
{
	struct monome * newMonome = NULL;
	newMonome=malloc(sizeof(struct monome));
	newMonome->c=coef;
	newMonome->e=puissance;
	newMonome->suiv=tete;
	return newMonome;
}
void P_AjoutM (float coef, int puissance, struct monome **tete)
{
	struct monome * newMonome = NULL;
	newMonome=malloc(sizeof(struct monome));
	newMonome->c = coef;
	newMonome->e = puissance;
	newMonome->suiv=*tete;
	*tete = newMonome;
}
struct monome* ajout_queue (float coef, int puissance, struct monome *queue)
{
	struct monome * newMonome = NULL;
	newMonome=malloc(sizeof(struct monome));
	newMonome->c=coef;
	newMonome->e=puissance;
	newMonome->suiv = NULL;
	if (queue != NULL) {
		queue->suiv = newMonome;
	}
	return newMonome;
}
void AjoutM (float coef, int puissance, struct monome **tete)
{
	struct monome *temp = *tete;
	struct monome *precedent = NULL;
	if (temp == NULL)
	{
		P_AjoutM (coef, puissance, &*tete);
		printf("Done4\n");
		return;
	}
	if (puissance > temp->e)
	{
		struct monome * newMonome = NULL;
		newMonome=malloc(sizeof(struct monome));
		newMonome->c=coef;
		newMonome->e=puissance;
		newMonome->suiv= *tete;
		*tete = newMonome;
		printf("Done1\n");
		return;
		}
	while(temp != NULL)
	{
		if (puissance == temp->e) 
		{
			temp->c = temp->c + coef;
			printf("Done2\n");
			break;
		}
		else if (puissance > temp->e && puissance < precedent->e)
		{
			struct monome * newMonome = NULL;
			newMonome=malloc(sizeof(struct monome));
			newMonome->c=coef;
			newMonome->e=puissance;
			newMonome->suiv=temp;
			precedent->suiv=newMonome;
			printf("Done3\n");
			printf("%d\n%d\n", temp->e, puissance);
			break;
		}
		else if (temp->suiv == NULL)
		{
			struct monome * newMonome = NULL;
			newMonome=malloc(sizeof(struct monome));
			newMonome->c=coef;
			newMonome->e=puissance;
			newMonome->suiv=NULL;
			temp->suiv=newMonome;
			printf("Done5");
			break;
		}
		precedent = temp;
		temp = temp->suiv;
	}
}
void parcours (struct monome *tete)
{
	struct monome * temp = tete;
	while(temp != NULL)
	{
		printf("%fx^%d\n", temp->c,temp->e);
		temp = temp->suiv;
	}
}
int main()
{
	struct monome *tete = NULL;
	AjoutM (1, 3, &tete);
	AjoutM (3, 7, &tete);
	AjoutM (4, 2, &tete);
	AjoutM (5, 3, &tete);
	AjoutM (2, 8, &tete);
	AjoutM (6, 5, &tete);
	parcours (tete);
}
