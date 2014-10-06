# include <stdio.h>
# define NB_VAL 10
int main () {
int tab_val[NB_VAL];
int val=0;
int somme=0;
int i=0;
//============================================================================
// Remplissage du tableau
//============================================================================
for (i=0 ; i<NB_VAL ; i++)
{
	printf ("Saisir une valeur:");
	scanf ("%d", &val);
	tab_val[i]=val;
}
//============================================================================
// Calcule de la somme
//============================================================================
for (i=0 ; i<NB_VAL ; i++)
{
	somme= somme + tab_val[i];
}
//============================================================================
// Affichage de la somme
//============================================================================
printf ("La somme des valeur est: %d\n\n",somme);
//============================================================================
// Affichage des valeurs dans l'ordre de saisie
//============================================================================
printf ("Les valeurs saisies dans l'ordre sont:\n");
for (i=0 ; i<NB_VAL-1 ; i++)
{
	printf ("%d,", tab_val[i]);
}
printf("\b \n\n"); // "\b " Remplacement du dernier caractère
//============================================================================
// Bug boucle infini
//============================================================================

/*printf ("Les valeurs saisies dans l'ordre sont:\n");
for (i=0 ; i<NB_VAL-1 ; i++)
{
	printf ("%d,", tab_val[i]);
	tab_val[-1]=0;
}*/

//============================================================================
// Affichage des valeurs dans l'ordre inverse de la saisie
//============================================================================
printf ("Les valeurs saisies dans l'ordre inverse sont:\n");
for (i=NB_VAL-1 ; i>=0 ; i--)
{
	printf ("%d,", tab_val[i]);
}
printf ("\b \n"); // "\b " Remplacement du dernier caractère

//============================================================================
// Affichage des adresses mémoires
//============================================================================

printf ("L'addresse mémoire de val est: %p:\n", &val);
printf ("L'addresse mémoire de i est: %p:\n", &i);
printf ("L'addresse mémoire de la somme est: %p:\n", &somme);
for (i=0 ; i<NB_VAL ; i++)
{
	printf ("L'addresse mémoire de la valeur %d du tableau est :%p\n", i+1, &tab_val[i]);
}
printf ("Taille d'une case du tableau: %ld\n", sizeof(tab_val[0]));
printf ("Taille d'un entier: %ld\n", sizeof(int));
//============================================================================
// Introduction bug : buffer over flow
//============================================================================
printf ("tab_val[10]:%d\n", tab_val[NB_VAL]);
printf ("L'adresse mémoire de tab_val[10] est:%p\n", &tab_val[NB_VAL]);
//============================================================================
// Introduction bug : buffer under flow
//============================================================================
printf ("tab_val[-1]:%d\n", tab_val[-1]);
printf ("L'adresse mémoire de tab_val[-1] est:%p\n", &tab_val[-1]);
return 0;
}
