# include <stdio.h>
# include <stdlib.h>

//Définition d'un monome a insérer dans une liste chainé

struct monome
{
	float c;
	int e;
	struct monome * suiv;
};

//Première fonction d'ajout d'un monome (inutile actuellement)
/*
struct monome* F_AjoutM (float coef, int puissance, struct monome *tete)
{
	struct monome * newMonome = NULL;
	newMonome=malloc(sizeof(struct monome));
	newMonome->c=coef;
	newMonome->e=puissance;
	newMonome->suiv=tete;
	return newMonome;
}
*/

//Procédure Ajout du premier monome

void P_AjoutM (float coef, int puissance, struct monome **tete)
{
	struct monome * newMonome = NULL;
	newMonome=malloc(sizeof(struct monome));
	newMonome->c = coef;
	newMonome->e = puissance;
	newMonome->suiv=*tete;
	*tete = newMonome;
}

//Fonction pour ajouter n'importe quel monome au polynome

void AjoutM (float coef, int puissance, struct monome **tete)
{
	struct monome *temp = *tete;
	struct monome *precedent = NULL;

	//Ajout du premier monome
	
	if (temp == NULL)
	{
		P_AjoutM (coef, puissance, &*tete);
		//printf("Done4\n");
		return;
	}

	//Ajout d'un monome en tête

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

	//Parcours de la liste pour insérer un monome

	while(temp != NULL)
	{

		//Si la puissance existe déja, additione simplement les coef

		if (puissance == temp->e) 
		{
			temp->c = temp->c + coef;
			//printf("Done2\n");
			break;
		}

		// Si il existe une puissance inférieur et supérieur insertion du monome

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

		//Ajout en queue du monome si aucun monome inférieur

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

//Parcours du polynome et affichage

void parcours (struct monome *tete)
{
	struct monome * temp = tete;
	while(temp != NULL)
	{
		printf("%fx^%d\n", temp->c,temp->e);
		temp = temp->suiv;
	}
}

//Affichage pour entré un monome

void saisie_monome (int *coef, int *degre)
{
	printf("Ajout d'un monome à la chaine\n");
	printf("Veuillez saisir le degré du monome.\nDegre: ");
	scanf("%d",degre);
	printf("\nVeuillez saisir le coeficient du monome.\nCoef: ");
	scanf("%d",coef);
	printf("\n");
}

//Menu de sélection des actions

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

//Fonction pour additioner 2 polynome

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

//Fonction pour multiplié 2 polynome

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

//Fonction principale

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
