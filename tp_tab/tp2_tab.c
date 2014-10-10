#include <stdio.h>
#define N 5
int main(){
int identique=0;
int i=0;
char tab1[N]={'a','b','c','d','e'};
char tab2[N]={'b','a','c','a','e'};
//============================================================================
// Boucle de vérification de l'égalité des tableaux
//============================================================================
for (i=0 ; i<N ; i++)
	{
	if (tab1[i]==tab2[i])
		{
		identique++;
		printf ("Un des indices identiques est: %c\n", tab1[i]);
		}
	}
//============================================================================
// Affichage des solutions
//============================================================================
	printf ("Il y a en tout %d indices identiques\n.", identique);
return 0;
}
