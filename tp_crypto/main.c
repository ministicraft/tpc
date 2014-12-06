#include "crypto.h"
int main()
{
//===========================================================================================
//Déclaration
//===========================================================================================
	char* chaine=NULL;
	int i=0;
	float* freq=NULL;
	int cle=0;	
	int choix=0;
do{ //Boucle pour recommencer le programme tant que l'utilisateur ne la pas décidé
	print_Prog(); // Affichage styliser du pragramme
	choix=menu(); // Choix du menu
	switch (choix)
	{
//===========================================================================================
//1er menu
//Chiffrement d'un msg d'après la méthode César en fonction d'une clé
//===========================================================================================
	case 1:
		chaine=saisieChaine(); // Saisie de la chaine
		cle=saisieCle(); // Saisie de la clé
		printf("\nLe message crypté est:\n");
		for (i=0;i<strlen(chaine);i++) // boucle pour chiffrer un à un les caractère 
						//de la chaine
		{
			printf("%c",chiffrement(chaine[i],cle));
		}
		printf("\n\n");
		break;
//===========================================================================================
//2ème menu
//Dechiffrement d'un msg d'après la méthode César en fonction d'une clé
//===========================================================================================
	case 2:
		chaine=saisieChaine(); // Saisie de la chaine
		cle=saisieCle(); // Saisie de la clé
		printf("\nLe message décrypté est:\n");
		for (i=0;i<strlen(chaine);i++) // booucle pour déchiffrer un à un les 
						//caractère de la chaine
		{
			printf("%c",dechiffrement(chaine[i],cle));
		}
		printf("\n\n");
		break;
//===========================================================================================
//3ème menu
//Analyse de la fréquence d'aparition des lettres du msg en %
//===========================================================================================
	case 3:
		chaine=saisieChaine(); // Saisie de la chaine
		freq=analyseFreq(chaine, strlen(chaine));
		//Calcule de la fréquence d'aparition des lettres dans la chaine
		printf("La fréquence d'apparition des lettres sont:\n");
		for(i=0;i<26;i++) // boucle pour afficher la fréquence de chaque lettre
		{
			printf("'%c': ",('A'+i));
			printf("%f\n",freq[i]);
		}
		break;
//===========================================================================================
//4ème menu
//Récupération de la clé après Analyse de la fréquence d'apparition des lettres dans le msg
//===========================================================================================
	case 4:
		chaine=saisieChaine(); // Saisie de la chaine
		freq=analyseFreq(chaine, strlen(chaine));
		//Calcule de la fréquence d'aparition des lettres dans la chaine
		printf("La clé du msg est: %d\n",calculCle(freq));
		// Affichage de la clé de la chaine après analyse et calcule de la clé
		printf("\n");
		break;
//===========================================================================================
//5ème menu
//Déchiffrement automatique du message après récupération de la clé
//===========================================================================================
	case 5:
		chaine=saisieChaine();
		freq=analyseFreq(chaine, strlen(chaine));
		cle=calculCle(freq);
		for (i=0;cle>26;i++)
		{
			cle=cle-26;
		}
		printf("\n\nLe message décrypté est:\n");
		for (i=0;i<strlen(chaine);i++)
		{
			printf("%c",dechiffrement(chaine[i],cle));
		}
		printf("\n\n");
		break;
//===========================================================================================
//6ème menu
//Sortie du programme
//===========================================================================================
	case 6:
		break;
//===========================================================================================
//Default
//Affichage par défault si la choix ne correspond à aucun menu
//===========================================================================================
	default:
		printf("Votre choix n'est pas valide.");
	}
	printf("Appuyer sur une touche pour continuer\n");
	getchar();
} while (choix != 6);
system ("clear");
return 0;
}
