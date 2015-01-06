#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE_MAX 100
struct client
{
	char* nom;
	char* prenom;
	float solde;
	int num;
};
typedef struct client Client;
void ajout(Client** ptab_client, int *pnb_client);
Client* find(Client** ptab_client, int nb_client, int *num_client);
void affichage_client(Client client);
void all_client(Client** ptab_client,int nb_client);
void virement(Client *clienta, Client *clientb);
void suppression(Client *client_suppr,int *num_client,Client** ptab_client,int *pnb_client);
char* saisiechaine();
int menu();
void pause();
//Avec Make file option -g rajoute des info dans le binaire executable
