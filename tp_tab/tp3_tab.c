#include <stdio.h>
#define NB_COL 3
#define NB_LIGNE 2
int main(){
//==================================================================================
//Déclaration variable
//==================================================================================
int i=0;
int j=0;
int tab [NB_LIGNE][NB_COL] = {{12,7,18},{1,14,2}};
int add_ligne [NB_LIGNE]= {0};
int add_col[NB_COL]= {0};
int total=0;
//==================================================================================
//Calcul\affichage total ligne && Calcul colonne
//==================================================================================
for (i=0 ; i<NB_LIGNE ; i++)
	{
	
	for (j=0 ; j<NB_COL ; j++)
		{
		add_ligne[i]=add_ligne[i]+tab[i][j];
		printf ("%5d", tab[i][j]);
		add_col[j]=add_col[j]+tab[i][j];
		}
	total=total+add_ligne[i]; // calcul total
	printf ("||%5d\n", add_ligne[i]);
	}

//==================================================================================
//Affichage colonne et ligne séparatrice du bas
//==================================================================================
for (j=0 ; j<NB_COL ; j++)
	{
	printf ("=======");
	}
printf("\n");
for (j=0 ; j<NB_COL ; j++)
	{
	printf ("%5d", add_col[j]);
	}
printf ("||%5d\n", total); // Affichage total

return 0;
}
