# include <stdio.h>
#define MAX_BOUCLE 5

int main () {
int entier = 0; // initialisation obligatoire
int nb_saisie = 0;
int somme = 0;
float moyenne = 0;

//===================================================================================

	while (entier >= 0 && nb_saisie < MAX_BOUCLE) 	// Tant que entier positif
							// faire la boucle
							// et Boucle max < 5 
	{
		printf ("Entrer un entier positif:");
		scanf ("%d",&entier);

		if (entier >= 0) // Si entier positif l'afficher
		{
			printf ("Cet entier est:%d\n", entier);
			nb_saisie++;
			somme = somme + entier;
		}
	}

	printf ("La somme est:%d\n", somme);
	moyenne = (float) somme / nb_saisie;
	if (nb_saisie == 0)
	{
		printf ("Erreur: Moyenne impossible\n	Divison par 0 \n");
	}
	else
	{
		printf ("La moyenne est:%.2f\n", moyenne);
	}

return 0;
}

//=================================================================================
//=================================================================================
