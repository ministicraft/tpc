#include <stdio.h>
int main () {
int i = 0;
int n = 0;
int entier = 0;
int somme = 0;
float moyenne = 0;

printf ("Combien de valeurs voulez vous saisir?:");
scanf ("%d",&n);
for (i=0; i<n; i++)
{
	printf ("Renseignez votre valeur:");
	scanf ("%d",&entier);
	somme = somme + entier;
}

printf ("La somme des valeurs est: ");
printf ("%d\n", somme);
moyenne = (float) somme / n;
printf ("La moyenne des valeurs est: ");
printf ("%f\n", moyenne);
return 0;
}

