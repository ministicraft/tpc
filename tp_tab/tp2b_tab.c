#include <stdio.h>
#define N 5
int main(){
int identique=0;
int i=0;
int j=0;
/*int k=0;*/
int equivalent=0;
char tab1[N]={'a','b','c','d','e'};
char tab2[N]={'b','a','c','a','e'};
char tab_solution[N];
//============================================================================
// Boucle de vérification de l'égalité des tableaux
//============================================================================
for (i=0 ; i<N ; i++)
	{
	if (tab1[i]==tab2[i]) // Condition d'égalité des Tablaeux
		{
		tab_solution[identique]=tab1[i];
// Incrémentation des valeurs identique dans le tableaux de solution
		identique++;		
		}
	}
//============================================================================
//============================================================================
printf ("Il y a en tout %d valeurs identiques.\n", identique);
printf ("Les valeurs identiques sont: ");
//============================================================================
// Boucle d'affichage des solutions
//============================================================================
for (i=0 ; i<identique ; i++)
	{
	printf ("%c, ", tab_solution[i]); // Affichage des solutions
	}
printf ("\b\b \n"); // Suprimer la dernière virgule
//============================================================================
// Valeurs identiques dans les 2 tableaux
//============================================================================
for (i=0 ; i<N ; i++)
	{
	for (j=0 ; j<N ; j++)
		{
		if (tab1[i]==tab2[j])
			{
			equivalent++;
			break;
			/*for (k=j+1 ; k<N ; k++)
				{
				if (tab2[k]==tab2[j])
					{
					equivalent--;
					}
				}*/
			}
		}
	}
printf ("Il y a %d caractères équivalents.\n", equivalent);
return 0;
}
