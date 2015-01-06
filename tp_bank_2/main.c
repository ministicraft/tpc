#include "bank.h"
int main ()
{
	//Déclaration
	Client* tab_client=NULL;
	int nb_client=0;
	int choix=0;
	Client* pt1=NULL;
	Client* pt2=NULL;
	int num_client=0;
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
				pt1=find(&tab_client,nb_client, &num_client);
				if (pt1 != NULL)
				{
					affichage_client(*pt1);
					pause ();
				}
				else pause ();
				break;
			//Afficher tous les clients
			case 3:
				all_client(&tab_client,nb_client);
				break;
			//Virement
			case 4:
				pt1=find(&tab_client,nb_client, &num_client);
				if (pt1 == NULL)
				{			
					pause ();
					break;
				}
				pt2=find(&tab_client,nb_client, &num_client);
				if (pt2 == NULL)
				{				
					pause ();
					break;
				}
				if (pt1 != NULL && pt2 != NULL)
				{
					virement (pt1 , pt2);
				}
				break;
			//Suppression de client
			case 5:
				pt1=find(&tab_client,nb_client, &num_client);
				suppression(pt1,&num_client,&tab_client,&nb_client);
			//Quitter
			case 6:
				break;
		}
	} while (choix!=6);
}
