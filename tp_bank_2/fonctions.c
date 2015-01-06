#include "bank.h"


//Fonctions Ajout d'un client

void ajout(Client* *ptab_client,int *pnb_client)
{
	//Prologue
	Client *tab_client=*ptab_client;
	int nb_client=*pnb_client;


			tab_client=realloc(tab_client,(nb_client+1)*sizeof(Client));
			printf("Veuillez renseigner votre nom: ");

				char chaine_nom[TAILLE_MAX]={0};
				fgets ( chaine_nom, TAILLE_MAX+1, stdin);
				if (chaine_nom[strlen(chaine_nom)-1]=='\n') chaine_nom[strlen(chaine_nom)-1]='\0';

					tab_client[nb_client].nom=malloc((strlen(chaine_nom)+1)*sizeof(char));
					strcpy(tab_client[nb_client].nom,chaine_nom);
	
			printf("Veuillez renseigner votre prénom: ");

				char chaine_prenom[TAILLE_MAX]={0};
				fgets ( chaine_prenom, TAILLE_MAX+1, stdin);
				if (chaine_prenom[strlen(chaine_prenom)-1]=='\n') chaine_prenom[strlen(chaine_prenom)-1]='\0';

					tab_client[nb_client].prenom=malloc((strlen(chaine_prenom)+1)*sizeof(char));
					strcpy(tab_client[nb_client].prenom,chaine_prenom);

			printf("Veuillez renseigner le montant du premier apport: ");
				scanf("%f",&tab_client[nb_client].solde);


	//Epilogue
	*ptab_client=tab_client;
	*pnb_client=nb_client+1;
}

//Trouver un client
Client* find(Client** ptab_client, int nb_client, int *num_client)
{
	//Prologue
	Client *tab_client=*ptab_client;
	int i=0;
	int vrai=0;

	printf("Saisir le nom du client: ");
		char chaine_nom[TAILLE_MAX]={0};
		fgets ( chaine_nom, TAILLE_MAX+1, stdin);
		if (chaine_nom[strlen(chaine_nom)-1]=='\n') chaine_nom[strlen(chaine_nom)-1]='\0';

	printf("Saisir le prenom du client: ");
		char chaine_prenom[TAILLE_MAX]={0};
		fgets ( chaine_prenom, TAILLE_MAX+1, stdin);
		if (chaine_prenom[strlen(chaine_prenom)-1]=='\n') chaine_prenom[strlen(chaine_prenom)-1]='\0';

		for(i=0; i<nb_client ; i++)
		{
			vrai=0;
			if (!strcmp(chaine_nom,tab_client[i].nom)) 
			{
				vrai++;
			}
			if (!strcmp(chaine_prenom,tab_client[i].prenom)) 
			{
				vrai++;
			}
			if (vrai==2) break;
		}
	if (vrai==2)
	{
	*num_client= i;
	return &tab_client[i];
	}
	else
	{
	printf("Aucun client connu à se nom.\n");
	return NULL;
	}
}
//Affichage client
void affichage_client(Client client)
{
	printf("Nom du client: %s\n",client.nom);
	printf("Prénom du client: %s\n",client.prenom);
	printf("Solde du client: %f\n",client.solde);
}
//Afficher tous les clients
void all_client(Client** ptab_client,int nb_client)
{
	Client *tab_client=*ptab_client;
	int i=0;
	for (i=0; i<nb_client ; i++)
	{
	affichage_client(tab_client[i]);
	printf("\n");
	}
	pause();
}
//Virement
void virement(Client *clienta,Client *clientb)
{
	//Prologue
	Client client1=*clienta;
	Client client2=*clientb;

	float transfere = 0;
	printf("Veuillez saisir le montant de votre virement:");
	scanf("%f",&transfere);
	getchar();
	if (client1.solde < transfere)
	{
		printf("Opération impossible vous n'avez pas les fonds nécessaire.\n");
		pause ();
	}
	else
	{
		client1.solde = client1.solde - transfere;
		client2.solde = client2.solde + transfere;
		printf("Opération effectuer avec succès!\n");
	}
//Epilogue
*clienta=client1;
*clientb=client2;
}
//Supression
void suppression(Client *client_suppr, int *num_client, Client** ptab_client,int *pnb_client)
{
	//Prologue
	Client client=*client_suppr;
	Client *tab_client=*ptab_client;
	int nb_client=*pnb_client;
	int i=*num_client;

	//Liberation mémoire des nom et prénom du client a supprimer
	free(client.nom);
	free(client.prenom);

	for(i=*num_client; i<nb_client; i++)
	{
		tab_client[i].nom=tab_client[i+1].nom;
		tab_client[i].prenom=tab_client[i+1].prenom;
		tab_client[i].solde=tab_client[i+1].solde;
	}
	//reduit le nombre de client de 1
	nb_client=nb_client-1;
	//reallocation de la taille du tableaux de client	
	tab_client=realloc(tab_client,(nb_client)*sizeof(Client));

	//Epilogue
	*pnb_client=nb_client;
	*ptab_client=tab_client;
}
/*
//Supression
void suppression(Client *client_suppr)
{
//Prologue
	Client client=*client_suppr;

	client.nom="\0";
	client.prenom="\0";
	client.solde=0;
//Epilogue
	*client_suppr=client;
}
*/


//Menu
int menu()
{
	int choix=0;
	printf("Choisiser se que vous voulez faire:\n");
	printf("1. Ajoutez un client\n");
	printf("2. Cherchez un client\n");
	printf("3. Affichez tous les clients \n");
	printf("4. Effectuez un virement\n");
	printf("5. Supprimez un client\n");
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
