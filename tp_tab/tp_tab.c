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
// Affichage des valeurs dans l'ordre inverse de la saisie
//============================================================================
printf ("Les valeurs saisies dans l'ordre inverse sont:\n");
for (i=NB_VAL-1 ; i>=0 ; i--)
{
	printf ("%d,", tab_val[i]);
}
printf ("\b \n"); // "\b " Remplacement du dernier caractère
return 0;
}
