# include <stdio.h>
int main()
{
int age = 0;
int solde = 0;

printf ("Bonjour et bienvenue dans l'assistant de création de compte.\n");
printf ("Pour créer votre compte,\n");
printf ("Veuillez renseigner votre age:");
scanf ("%d",&age);
while (getchar()!='\n');

printf ("Veuillez renseigner le montant de  votre solde créditeur:");
scanf ("%d",&solde);
while (getchar()!='\n');

if (age >=0 && age <18 && solde >= 100000)
{
	printf ("Félicitation votre création de compte est valider\n");
	
}
else
{
	printf ("Erreur: Votre age est invalide ou le mantant de votre solde est inférieur au minimum requi pour la validation de votre compte\n");
	
}

if (age >= 18 && age < 150 && solde >= 100)
{
	printf ("Félicitation votre création de compte est valider\n");
	
}
else
{
	printf ("Erreur: Votre age est invalide ou le mantant de votre solde est inférieur au minimum requi pour la validation de votre compte\n");
	
}
return 0;
}
