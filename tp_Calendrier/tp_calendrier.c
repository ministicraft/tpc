# include <stdio.h>
int main () {

int annee = 0;
int mois = 0;

//===============================================================

printf ("Veuillez renseigner l'année voulue:"); // Saisie année
scanf ("%d",&annee);
while (getchar()!='\n');

printf ("Veuillez renseigner le mois voulue (1 à 12):"); // Saisie mois
scanf ("%d",&mois);
while (getchar()!='\n');

//================================================================

switch (mois) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: // Mois à 31 jours
		printf ("Il y a 31 jours dans se mois.");
	break;
	case 4: case 6: case 9: case 11:
		printf ("Il y a 30 jours dans se mois.");
	break;
	case 2:
		if ((annee % 4 == 0 && annee % 400 != 0) || annee % 400 == 0) // Cas des années bissextiles
		{
			printf ("Il y a 29 jours dans se mois. \n");
		}
		else // Cas des années non bissextiles
		{
			printf ("Il y a 28 jours dans se mois. \n");
		}
	break;
	default: // autres
		printf ("Le mois ou l'année entrée n'est pas valide. ");
		printf ("Veuillez vérifier votre saisie. \n");
}
return 0;
}
