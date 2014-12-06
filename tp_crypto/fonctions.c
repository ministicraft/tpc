#include "crypto.h"
/*
#########################################################################
#			Fonction chiffrement				#
#	But: Chiffrement du message avec la méthode césar		#
#		 en focntion d'une cle					#
#	Parametre:							#
#	Entrée: Le caractère à crypter et la clé de cryptage		#
#	Sortie: Le caractère crypter					#
#									#
#########################################################################
*/
char chiffrement (char c, int cle)
{
	char c_retour=c; // Par défault on retourne le paramètre c
	if (c >= 'A' && c <= 'Z')
	{
		if (c+cle > 'Z')
		{
			c_retour='A'+((c+cle)-'Z')-1; // Chiffrement de César
		}
		else
		{
			c_retour=c+cle;
		}
		
	}
return c_retour;
}
/*
#########################################################################
#			Fonction dechiffrement				#
#	But: Dechiffrement du message avec la méthode césar		#
#		 en focntion d'une cle					#
#	Parametre:							#
#	Entrée: Le caractère à decrypter et la clé de cryptage		#
#	Sortie: Le caractère decrypter					#
#									#
#########################################################################
*/
char dechiffrement (char c, int cle)
{
	if (c >= 'A' && c <= 'Z')
	{
		if (c-cle < 'A')
		{
			c='Z'-('A'-(c-cle))+1; // Déchiffrement de César
		}
		else
		{
			c=c-cle;
		}
	}
return c;
}
/*
#########################################################################
#			Fonction analyseFreq				#
#	But: Analyser la frequence d'apparition des lettres 		#
#		d'un message						#
#	Parametre:							#
#	Entrée: Le texte à analyser et la taille de ce texte		#
#	Sortie: Un tableau contenant la fréquence d'apparition		#
#	 	de chaque lettre					#
#									#
#########################################################################
*/
float* analyseFreq(char* texte,int N)
{
	
	float *freq=malloc((26+1)*sizeof(float));
	int i=0;
	int nb_char=0;
	for (i=0;i<N;i++)
	{
		if(texte[i]>='A' && texte[i]<='Z')
		{
			freq[texte[i]-'A']++;
			nb_char++;
		}
	}
	for (i=0;i<26;i++)
	{
		freq[i]=((freq[i]/nb_char)*100);
	}
return freq;
}
/*
#########################################################################
#			Fonction calculeCle				#
#	But: Trouver la clé de chiffrement du message			#
#	Parametre:							#
#	Entrée: Le tableaux de frequence d'apparition des lettres	#
#		 du message crypté					#
#	Sortie: Le caractère crypter					#
#									#
#########################################################################
*/
int calculCle (float* tabFreq)
{
	int i=0;
	int cle=0;
	float tab_cle=0;
	tab_cle=tabFreq[i];
	for (i=0;i<26;i++)
	{
		if (tabFreq[i]>=tab_cle)
		{
			cle=i-4;
			tab_cle=tabFreq[i];
		}
	}
	if (cle<0)
	{
	cle=26+cle;
	}
return cle;
}
/*
#########################################################################
#			Fonction saisieChaine				#
#	But: Saisir une chaine de caractère				#
#	Parametre:							#
#	Entrée: N/A							#
#	Sortie: La chaine de caractère					#
#									#
#########################################################################
*/
char* saisieChaine()
{
	char chaine[TAILLE_MAX]={0};
	printf("Saisir la chaine: ");
	fgets ( chaine, TAILLE_MAX+1, stdin);
	if (chaine[strlen(chaine)-1]=='\n') chaine[strlen(chaine)-1]='\0';
	char *chaine2=malloc((strlen(chaine))*sizeof(char));
	chaine2=chaine;
	return chaine2;
}
/*
#########################################################################
#			Fonction saisiecle				#
#	But: Saisir la cle de chiffrement du message			#
#	Parametre:							#
#	Entrée: N/A							#
#	Sortie: La clé saisie						#
#									#
#########################################################################
*/
int saisieCle()
{
	int i=0;
	int cle=0;
	printf("Saisir la clé: ");
	scanf("%d",&cle);
	getchar();
	if (cle < 0)
	{
		printf("La clé n'est pas valide.\n");
	}
	for (i=0;cle>26;i++)
	{
		cle=cle-26;
	}
	return cle;
}
/*
#########################################################################
#			Fonction menu					#
#	But: choisir une option dans un menu				#
#	Parametre:							#
#	Entrée: N/A							#
#	Sortie: le menu choisie						#
#									#
#########################################################################
*/
int menu()
{
	int choix=0;
	printf("Choisiser se que vous voulez faire:\n");
	printf("1. Chiffrement\n");
	printf("2. Dechiffrement\n");
	printf("3. Analyse Frequence\n");
	printf("4. Dechiffrement de la Clé\n");
	printf("5. Déchiffrement automatique du msg\n");
	printf("6. Quitter\n");
	printf("Votre choix: ");	
	scanf("%d",&choix);
	getchar();
	printf("\n");
	return choix;
}
/*
#########################################################################
#			Fonction prin_Prog				#
#	But: affiche le nom du programme et sa fonction			#
#	Parametre:							#
#	Entrée: N/A							#
#	Sortie: N/A							#
#									#
#########################################################################
*/
void print_Prog()
{
	system ("clear");
	printf("#########################################################################\n");
	printf("#									#\n");
	printf("#		Programme de chiffrement/dechiffrement			#\n");
	printf("#			méthode César					#\n");
	printf("#									#\n");
	printf("#########################################################################\n");
}
