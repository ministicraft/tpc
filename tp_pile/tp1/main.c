#include <stdio.h>
#define MAX_PILE 100

void push(int **top, int saisie)
{
	**top=saisie;
	printf("%p\n",*top);
	*top=++(*top);
	printf("%p\n",*top);
}

void pop (int **top)
{
	printf("%p\n",top);
	*top=--(*top);
	printf("%p\n",top);
	**top=0;
}

void peek (int *top)
{
	printf("%p\n",top);
	printf("%d\n",*top);
}

void liste (pile)
{
}

//Menu
int menu()
{
	int choix=0;
	printf("Choisiser se que vous voulez faire:\n");
	printf("1. Entrer un nombre\n");
	printf("2. Ajouter se nombre a la pile\n");
	printf("3. Enlever la dernière valeur de la pile \n");
	printf("4. Affichez la dernière valeur de la pile\n");
	printf("5. Afficher la pile\n");
	printf("6. Quitter\n");
	printf("Votre choix: ");	
	scanf("%d",&choix);
	getchar();
	printf("\n");
	return choix;
}

//Pause
void pause ()
{
	printf("Appuyer sur une touche pour continuer\n");
	getchar();
}


int main()
{
	int pile[MAX_PILE + 1] = {0};
	int *top=pile;
	printf("%p\n",&pile[0]);
	printf("%p\n",&pile[1]);
	printf("%p\n",top);
	int saisie=0;
	int choix = 0;
do
	{
		//system ("clear");
		choix = menu();
		switch (choix)
		{
			case 1:
				scanf("%d",&saisie);
				getchar();
				pause();
				break;
			case 2:
				push (&top, saisie);
				pause();
				break;
			case 3:
				pop (&top);
				pause();
				break;
			case 4:
				if (top==&)
				peek (top);
				pause();
				break;
			case 5:
				liste (pile);
				break;
		}
	} while (choix!=6);
			return 0;
}

