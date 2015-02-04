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
struct monome* AjoutM (float coef, int puissance, struct monome *tete)
{
	struct monome * newMonome = NULL;
	newMonome=malloc(sizeof(struct monome));
	newMonome->c=coef;
	newMonome->e=puissance;
	newMonome->suiv=tete;
	return newMonome;
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
void compare (newMonome, struct monome *tete)
{
	struct monome *less = NULL;
	struct monome *up = NULL;
	struct monome *temp = tete;
	while(temp != NULL)
	{
		if (newMonome->e >= temp->e)
		{
			less=temp;
			break;
		}
		else if (temp->suiv = NULL) 
		{
			up=temp;
			break;
		}
	}
	if (less != NULL)
	{
		F_AjoutM (4.5, 8, tete);
	}
	else if (up != NULL;)
	{
		ajout_queue (7.3, 3, queue);
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
	P_AjoutM (4.5, 8, &tete);
	P_AjoutM (7.3, 3, &tete);
	parcours (tete);
}
