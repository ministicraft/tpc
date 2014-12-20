#include "bank.h"
int main ()
{
	//Déclaration
	Client* tab_client=NULL;
	int nb_client=0;
	int choix=0;
	do
	{
		system ("clear");
		choix = menu();
		switch (choix)
		{
			//Nouveaux client
			case 1:
				ajout(&tab_client,&nb_client);
				pause ();
				break;
			//Cherchez un client
			case 2:
				find(&tab_client,nb_client);
				break;
			//Afficher tous les clients
			case 3:
				all_client(&tab_client,nb_client);
				break;
			//Quitter
			case 5:
				break;
		}
	} while (choix!=5);
}
