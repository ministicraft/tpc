# include <stdio.h>
# define Majoriter 18
# define Solde_Min 100
# define Solde_Sup 100000
# define Age_Max 150
# define Age_Min 0
int main()
{
int age = 0;
int solde = 0;

printf ("Bonjour et bienvenue dans l'assistant de création de compte.\n");
printf ("Pour créer votre compte,\n \n");

printf ("Veuillez renseigner votre âge:");
scanf ("%d",&age);
while (getchar()!='\n');
printf ("\n");

printf ("Veuillez renseigner le montant de votre dépôt initial:");
scanf ("%d",&solde);
while (getchar()!='\n');
printf ("\n");

if (age > Age_Min && age < Majoriter && solde >= Solde_Sup)
{
	printf ("Félicitation, votre création de compte est validée\n");
	return 0;
}

else if (age >= Majoriter && age < Age_Max && solde >= Solde_Min)
{
	printf ("Félicitation, votre création de compte est validée\n");
	return 0;
}
else
{
	printf ("Erreur: Votre âge est invalide ou le montant de votre" 		" solde est inférieur au minimum requis pour la"
		" validation de votre compte\n");
	return 1;
}
return 0;
}
