#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE_MAX 100
struct client
{
	char* nom;
	char* prenom;
	float solde;
};
typedef struct client Client;
void ajout(Client** ptab_client, int *pnb_client);
void find(Client** ptab_client, int nb_client);
void affichage_client(Client client);
void all_client(Client** ptab_client,int nb_client);
char* saisiechaine();
int menu();
void pause();
//Avec Make file option -g rajoute des info dans le binaire executable
