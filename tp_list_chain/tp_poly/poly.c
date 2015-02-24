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
		//printf("Done4\n");
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
		//printf("Done1\n");
		return;
		}
	while(temp != NULL)
	{
		if (puissance == temp->e) 
		{
			temp->c = temp->c + coef;
			//printf("Done2\n");
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
			//printf("Done3\n");
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
			//printf("Done5");
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
void saisie_monome (int *coef, int *degre)
{
	int out_degre = 0;
	int out_coef = 0;
	printf("Ajout d'un monome à la chaine\n");
	printf("Veuillez saisir le degré du monome.\nDegre: ");
	scanf("%d",degre);
	printf("\nVeuillez saisir le coeficient du monome.\nCoef: ");
	scanf("%d",coef);
	printf("\n");
}
int menu()
{
	int choix=0;
	printf("Choisiser se que vous voulez faire:\n");
	printf("1. Ajout d'un Monome au polynome\n");
	printf("2. Addition de polynome\n");
	printf("3. Multiplication de polynome\n");
	printf("4. Afficher le polynome\n");
	printf("5. Quitter\n");
	printf("Votre choix: ");	
	scanf("%d",&choix);
	getchar();
	printf("\n");
	return choix;
}
void ADD (struct monome *A, struct monome *B, struct monome **C)
{	
	struct monome * temp_A = A;
	struct monome * temp_B = B;
	while (temp_A != NULL)
	{
		AjoutM (temp_A->c, temp_A->e, &temp_B);
		temp_A = temp_A->suiv;
	}
	*C = temp_B;
}
void MUL (struct monome *A, struct monome *B, struct monome **C)
{
	struct monome * temp_A = A;
	struct monome * temp_B = B;
	
	while (temp_A != NULL)
	{
		temp_B = B;
		while (temp_B != NULL)
		{
			AjoutM (temp_A->c * temp_B->c, temp_A->e + temp_B->e, C);
			temp_B = temp_B->suiv;
		}
		temp_A = temp_A->suiv;
	}
}
int main()
{
	struct monome *tete = NULL;
	struct monome *A = NULL;
	struct monome *B = NULL;
	struct monome *C = NULL;
	int degre = 0;
	int coef = 0;
	int choix = 0;
	do
	{ //Boucle pour recommencer le programme tant que l'utilisateur n'a pas choisie de quitter
		choix=menu(); // Choix du menu
		switch (choix)
		{
			case 1:
				saisie_monome (&coef, &degre);
				printf("%d\n%d\n",degre,coef);
				AjoutM (coef, degre, &tete);
				break;
			case 2:
				printf("Saisie du premier ploynome.\n");
				printf("Saisir un coeficient nul pour arrêter la saisie\n\n");
				do //Saisie du premier polynome
				{
					saisie_monome(&coef, &degre);
					if (coef != 0) AjoutM (coef, degre, &A);
				} while (coef != 0);
				printf("\n");
				parcours (A);
				printf("\n");
				printf("Saisie du deuxième ploynome\n");
				printf("Saisir un coeficient nul pour arrêter la saisie\n\n");
				do //Saisie du deuxième polynome
				{
					saisie_monome(&coef, &degre);
					if (coef != 0) AjoutM (coef, degre, &B);
				} while (coef != 0);
				printf("\n");
				parcours (B);
				printf("\n");
				ADD (A, B, &C);
				parcours (C);
				break;
			case 3:
				printf("Saisie du premier ploynome.\n");
				printf("Saisir un coeficient nul pour arrêter la saisie\n\n");
				do //Saisie du premier polynome
				{
					saisie_monome(&coef, &degre);
					if (coef != 0) AjoutM (coef, degre, &A);
				} while (coef != 0);
				printf("\n");
				parcours (A);
				printf("\n");
				printf("Saisie du deuxième ploynome\n");
				printf("Saisir un coeficient nul pour arrêter la saisie\n\n");
				do //Saisie du deuxième polynome
				{
					saisie_monome(&coef, &degre);
					if (coef != 0) AjoutM (coef, degre, &B);
				} while (coef != 0);
				printf("\n");
				parcours (B);
				printf("\n");
				MUL (A, B, &C);
				parcours (C);
				break;
			case 4:
				parcours (tete);
			case 5:
				break;
			default:
				printf("Votre choix n'est pas valide.");
		}
		printf("Appuyer sur une touche pour continuer\n");
		getchar();
	} while (choix != 5);

return 0;
}
