#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 1000
#define MAX(x,y) (((x)>(y))?(x):(y))
#define SIZE(t) ((t!=NULL)?(t->hauteur):(0))

struct noeud
{
	char *fr;
	char *en;
	struct noeud * filsG;
	struct noeud * filsD;
	int hauteur;
};
typedef struct noeud Noeud;


typedef struct file

{

    Noeud * noeud;

    struct file *suivant;

} File;

Noeud *inserer(char *fr, char *en, Noeud * racine);
char * traduction (char* fr, Noeud* racine);
void affichage (Noeud* noeud);
void parcoursGRD (Noeud* racine);
void parcoursGRD_action (Noeud* racine, void (*f)(Noeud*));
Noeud *creation(char *nomfichier);
int hauteur_arbre (Noeud * racine);
void libere_noeud(Noeud * noeud);
File* enfiler (File ** file, Noeud * noeud);
Noeud* defiler (File **p_file);
void plargeur(Noeud * racine);
/*Noeud *rotation_droite(Noeud *y);
Noeud *rotation_gauche(Noeud *x);
Noeud *equilibrer_arbre(Noeud *a);
void calculer_hauteur(Noeud *a);*/
void DSWBalancingAlgorithm(Noeud * root);
int RightRotate(Noeud * node);
int LeftRotate(Noeud * node);
