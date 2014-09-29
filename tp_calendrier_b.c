# include <stdio.h> // test github
int main () {

int annee = 0;
int mois = 0;
int jour = 0;

//===============================================================

printf ("Veuillez renseigner l'année voulue:"); // Saisie de l'année
scanf ("%d",&annee);
while (getchar()!='\n');

printf ("Veuillez renseigner le mois voulue (1 à 12):"); // Saisie du mois
scanf ("%d",&mois);
while (getchar()!='\n');

printf ("Veuillez renseigner le jour:"); // Saisie du jour
scanf ("%d",&jour);
while (getchar()!='\n');

//=======================================================================

if (mois <= 0 || mois > 12)
{
	printf ("Le mois n'est pas valide.\n");
	return 1;	}
if (jour <= 0 || jour > 31)
{
	printf ("Le jour n'est pas valide.\n");
	return 1;
}
if (mois == 2 && jour > 29)
{
	printf ("Le jour n'est pas valide.\n");
	return 1;
}

//=======================================================================

	switch (mois)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: // Mois à 31 jours
		printf ("Il y a 31 jours dans se mois. ");
		break;
		case 4: case 6: case 9: case 11: // Mois à 30 jours
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
	}

//=======================================================================

// affichage j+1 fevrier

	if ( ( jour == 29 && mois == 2 ) && ( annee % 4 == 0 && annee % 400 != 0 ) || annee % 400 == 0 )
	{
		printf ("Le lendemain est le 1 er du ");
		mois = mois + 1;
		printf ("%d", mois);
		printf ("\n");
		return 0;
	}
	else if ( jour == 28 && mois == 2 && ( annee % 4 == 0 && annee % 400 != 0 ) || annee % 400 == 0 )
	{
		printf ("Le lendemain est le ");
		jour = jour + 1;
		printf ("%d", jour);
		printf ("\n");
		return 0;
	}
	else if ( mois == 2 && !(jour == 28 || jour == 29) )
	{
		jour = jour + 1;
		printf ("Le lendemain est les ");
		printf ("%d", jour);
		printf ("\n");
		return 0;
	}
	else if (!((annee % 4 == 0 && annee % 400 != 0) || annee % 400 == 0) && jour > 28)
	{
		printf ("Le jour n'est pas valide, année non bissextile\n");
		return 1;
	}

//=======================================================================

	switch (mois)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: // j+1 mois à 31 jours
			if (jour == 31 )
			{
				printf ("Le lendemain est le 1 er du ");
				mois = mois +1;
				printf ("%d", mois);
				printf ("\n");
				return 0;
			}
			else 
			{
				jour = jour + 1;
				printf ("Le lendemain est le ");
				printf ("%d", jour);
				printf ("\n");
				return 0;				
			}
		break;
		case 12:			
			if (jour == 31 && mois == 12) // passage à l'année sup
			{
				printf ("Le lendemain est le 1 er de l'an ");
				annee = annee +1;
				printf ("%d", annee);
				printf ("\n");
				return 0;			
			}
			else 
			{
				jour = jour + 1;
				printf ("Le lendemain est le ");
				printf ("%d", jour);
				printf ("\n");
				return 0;				
			}
		break;
		case 4: case 6: case 9: case 11: // j+1 des mois à 30 jours

			if (jour == 30)
			{
				printf ("Le lendemain est le 1 er du ");
				mois = mois +1;
				printf ("%d", mois);
				printf ("\n");
				return 0;
			}
			else
			{
				jour = jour + 1;
				printf ("Le lendemain est le ");
				printf ("%d", jour);
				printf ("\n");
				return 0;
			}
			
	}
return 0;
}
