#include "arbre.h"

//-------------------------------------------------------------------------------------------
// Fonction pour insérer un mot dans l'arbre
//-------------------------------------------------------------------------------------------

Noeud *inserer(char *fr, char *en, Noeud * racine)
{
	// Lorsque l'on arrive à une feuille crée un nouveau noeud
	if (racine==NULL)
	{
		Noeud * newNoeud = NULL;
		newNoeud = malloc(sizeof(Noeud));

		newNoeud->fr = malloc((strlen(fr)+1)*sizeof(char));
		strcpy(newNoeud->fr,fr);

		newNoeud->en = malloc((strlen(en)+1)*sizeof(char));
		strcpy(newNoeud->en,en);

		newNoeud->filsG = NULL;
		newNoeud->filsD = NULL;
		newNoeud->hauteur = 0;
		racine = newNoeud;
	}
	// Fils gauche (Si le mot est supérieur dans l'ordre lexical)
	else if(strcmp(fr,racine->fr) < 0)
	{
		racine->filsG = inserer(fr, en, racine->filsG);
	}
	// Fils droit (Si le mot est inférieur dans l'ordre lexical)
	else if(strcmp(fr,racine->fr ) > 0)
	{
		racine->filsD = inserer(fr, en, racine->filsD);
	}
	// Si le mot existe déja dans le l'arbre
	else
	{
		printf("Ce mot existe déjà.\n");
		printf("FR: %s\nEN: %s\n", fr, en);
	}
	return racine;
}

//-------------------------------------------------------------------------------------------
// Fonction pour afficher la traduction d'un mot que l'on aurait rechercher dans l'arbre
//-------------------------------------------------------------------------------------------

char * traduction (char* fr, Noeud* racine)
{
	if(strcmp(fr,racine->fr) < 0)
	{
		traduction(fr, racine->filsG);
	}
	else if(strcmp(fr,racine->fr ) > 0)
	{
		traduction(fr, racine->filsD);
	}
	else if(strcmp(fr,racine->fr ) == 0)
	{
		return racine->en;
	}
	else
	{
		printf("Se mot n'existe pas dans cette bibliotheque.\n");
	}
}

//-------------------------------------------------------------------------------------------
// Fonction pour afficher un noeud (mot fr, mot en, addresse fils D et address fils G)
//-------------------------------------------------------------------------------------------

void affichage (Noeud* noeud)
{
	if (noeud != NULL)
	{
		printf("\n-----------------\n");
		printf("%s\n",noeud->fr);
		printf("%s\n",noeud->en);
		if (noeud->filsD != NULL) // Si l'addresse filsD existe l'affiche
		{
			printf("%p\n",noeud->filsD);
		}
		if (noeud->filsG != NULL) // Si l'addresse filsG existe l'affiche
		{
			printf("%p\n",noeud->filsG);
		}
		printf("-----------------\n");
	}
}

//-------------------------------------------------------------------------------------------
// Fonction pour parcourir tout l'arbre et afficher tout les noeuds avec la fonction affichage
// GRD (Gauche/Racine/Droit)
//-------------------------------------------------------------------------------------------

void parcoursGRD (Noeud* racine)
{
	if (racine->filsG != NULL)
	{
		parcoursGRD (racine->filsG);
	}
	affichage(racine);
	if (racine->filsD != NULL)
	{
		parcoursGRD (racine->filsD);
	}
}


void parcoursGRD_action (Noeud* racine, void (*f)(Noeud*))
{
	if (racine->filsG != NULL)
	{
		parcoursGRD_action (racine->filsG, affichage);
	}
	f(racine);
	if (racine->filsD != NULL)
	{
		parcoursGRD_action (racine->filsD, affichage);
	}
}

//-------------------------------------------------------------------------------------------
// Fonction pour créer un arbre à partir d'un fichier
//-------------------------------------------------------------------------------------------

Noeud *creation(char *nomfichier)
{
	Noeud *racine = NULL;
	char *pt_separateur = NULL;
	char ligne [TAILLE_MAX+1];
	FILE * fp = NULL;
	fp=fopen(nomfichier,"r");
	if (fp==NULL)
	{
		printf("Erreur impossible d'ouvrir le fichier.\n");
		return;
	}
	while (fgets(ligne,TAILLE_MAX,fp))
        {
			pt_separateur = strchr(ligne,':');
			*pt_separateur = '\0';
			racine = inserer(ligne,pt_separateur+1,racine);
        }
	fclose(fp);
	// printf("%p\n",racine);
	return racine;
}

//-------------------------------------------------------------------------------------------
// Fonction de calcul de hauteur de l'arbre
//-------------------------------------------------------------------------------------------

int hauteur_arbre (Noeud * racine) //21
{
	if ( racine == NULL )
	{
		return 0;
	}
	else
	{
		return 1 + MAX(hauteur_arbre(racine->filsG), hauteur_arbre(racine->filsD));
	}
}

//-------------------------------------------------------------------------------------------
// Fonction de libération d'un noeud
//-------------------------------------------------------------------------------------------

void libere_noeud(Noeud * noeud)
{
	if (noeud->filsG != NULL)
	{
		libere_noeud (noeud->filsG);
	}

	free(noeud->en);
	free(noeud->fr);

	if (noeud->filsD != NULL)
	{
		libere_noeud (noeud->filsD);
	}

	free(noeud);
}

//-------------------------------------------------------------------------------------------
// Fonction pour ajouter un élément à une file
//-------------------------------------------------------------------------------------------

File* enfiler (File ** p_file, Noeud * noeud)
{
	File *p_nouveau = malloc(sizeof *p_nouveau); //création d'un nouvel élément pour la file
	p_nouveau->noeud = noeud; //donnéer contenue dans la fille
	p_nouveau->suivant = NULL;
	if (*p_file == NULL) //si la file est vide
	{
		*p_file = p_nouveau;
	}
	else //sinon
	{
		File *p_tmp = *p_file; 
		// on va jusqu'à la fin de la file
		while (p_tmp->suivant != NULL)
		{
			p_tmp = p_tmp->suivant; 
		}
		p_tmp->suivant = p_nouveau; // On ajoute le nouvel élément à la fin
	}
}

//-------------------------------------------------------------------------------------------
// Fonction enlever et retourner un élément d'une file
//-------------------------------------------------------------------------------------------

Noeud* defiler (File **p_file)
{
	Noeud* ret_noeud = NULL; // Notre variable de retour
	if (*p_file != NULL) // si la file n'est pas vide
	{
		File *p_tmp = (*p_file)->suivant; // l'élément suivant est stocker temporairement
		// la donnéer du première élément est stocker dans notre variable de retour
		ret_noeud = (*p_file)->noeud;
		free(*p_file), *p_file = NULL; // Libération du premier élément et il  devient NULL
		*p_file = p_tmp; // L'élément suivant devient le premier élément
	}
	return ret_noeud; // retour de la donnéer de l'élément
}

//-------------------------------------------------------------------------------------------
// Fonction pour parcourire et afficher en largeur
//-------------------------------------------------------------------------------------------

void plargeur(Noeud * racine)
{
	Noeud * noeud_tmp = NULL;
	File * file = NULL;
	enfiler(&file, racine); // Ajout du premier noeud à la file
	while (file != NULL) //tant que la file n'est pas vide
	{
		noeud_tmp = defiler (&file); // On enlève le premier de la file
		affichage(noeud_tmp); // On l'affiche
		if (noeud_tmp->filsG != NULL)
		{
			enfiler(&file,noeud_tmp->filsG); // On ajoute sont filsG à la file
		}
		if (noeud_tmp->filsD != NULL)
		{
			enfiler(&file,noeud_tmp->filsD); // On ajoute sont filsD à la file
		}
	}
}


//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
/*
// calculer la hauteur des noeuds du t_arbre a
void calculer_hauteur(Noeud *a)
{
    if( a != NULL )
    {
        if( a->filsG == NULL )
        {
            if( a->filsD == NULL )
                a->hauteur = 0;
            else
            {
                calculer_hauteur( a->filsD );
                a->hauteur = a->filsD->hauteur + 1;
            }
        }
        else if( a->filsD == NULL )
        {
            if( a->filsG == NULL )
                a->hauteur = 0;
            else
            {
                calculer_hauteur( a->filsG );
                a->hauteur = a->filsG->hauteur + 1;
            }
        }
        else
        {
            calculer_hauteur( a->filsD );
            calculer_hauteur( a->filsG );
            a->hauteur = MAX( a->filsD->hauteur, a->filsG->hauteur ) + 1;
        }
    }
}

Noeud *rotation_droite(Noeud *y)
{
    Noeud* a = NULL;
 
    if (y != NULL && y->filsG != NULL)
    {
        a = y->filsG;
        y->filsG = a->filsD;
        a->filsD = y;
 
        a->filsD->hauteur = MAX(SIZE(a->filsD->filsG), SIZE(a->filsD->filsD))+1;
        if( a->filsG != NULL )
            a->filsG->hauteur = MAX(SIZE(a->filsG->filsG), SIZE(a->filsG->filsD))+1;
        a->hauteur = MAX(SIZE(a->filsG), SIZE(a->filsD))+1;
        return a;
    }
    else
        return y;
}
 
Noeud *rotation_gauche(Noeud *x)
{
    Noeud* a = NULL;
 
    if (x != NULL && x->filsD != NULL)
    {
        a = x->filsD;
        x->filsD = a->filsG;
        a->filsG = x;
 
        if( a->filsD != NULL )
            a->filsD->hauteur = MAX(SIZE(a->filsD->filsG), SIZE(a->filsD->filsD))+1;
        a->filsG->hauteur = MAX(SIZE(a->filsG->filsG), SIZE(a->filsG->filsD))+1;
        a->hauteur = MAX(SIZE(a->filsG), SIZE(a->filsD))+1;
        return a;
    }
    else
        return x;
}
 
Noeud *equilibrer_arbre(Noeud *a)
{
    int hd = 0;
    int hp = 0;
    if( a == NULL )
        return NULL;
 
    hd = SIZE(a->filsG) - SIZE(a->filsD);
 
    while( ( hd < -1 || hd > 1 ) && hd != hp && hd != ( - hp ) )
    {
        hp = hd;
        if( hd > 1 )
            a = rotation_droite(a);
        else
            a = rotation_gauche(a);
        a->filsG = equilibrer_arbre(a->filsG);
        a->filsD = equilibrer_arbre(a->filsD);
 
        hd = SIZE(a->filsG) - SIZE(a->filsD);
    }
 
    if( a->filsG == NULL && SIZE(a->filsD) > 1 )
        a->filsD = equilibrer_arbre( a->filsD );
 
    if( a->filsD == NULL && SIZE(a->filsG) > 1 )
        a->filsG = equilibrer_arbre( a->filsG );
 
    a->hauteur = MAX(SIZE(a->filsG), SIZE(a->filsD))+1;
 
    return a;
}
*/
/////////////////////////////////////
// Rotates around the current node 
int LeftRotate(Noeud * node)  // =1 if rotate works,=0 otherwise 
	{  Noeud *nd;  char * data1; char * data2;
	if(node==0 || node->filsD==0) { return 0; }	// No Right Node!!

	nd=node->filsD; node->filsD=nd->filsD;  // Move Node
	nd->filsD=nd->filsG; nd->filsG=node->filsG;
	node->filsG=nd;

	strcpy(data1, node->fr);  strcpy(node->fr,nd->fr); strcpy(nd->fr, data1);
	strcpy(data2, node->en);  strcpy(node->en,nd->en); strcpy(nd->en, data2);
	return 1;
	}


/////////////////////////////////////
// Rotate around current node
int RightRotate(Noeud * node) // =1 if rotate works, =0 otherwise
	{  Noeud *nd;  char * data1; char * data2;
	if(node==0 || node->filsG==0) { return 0; }	

	nd=node->filsG; node->filsG=nd->filsG;
	nd->filsG=nd->filsD; nd->filsD=node->filsD;
	node->filsD=nd;

	
	strcpy(data1, node->fr);  strcpy(node->fr,nd->fr); strcpy(nd->fr, data1);
	strcpy(data2, node->en);  strcpy(node->en,nd->en); strcpy(nd->en, data2);
	return 1;
	}



//////////////////////////////////////
void DSWBalancingAlgorithm(Noeud * root)
	{  Noeud *p;  int nodecount; int i;
	///////////// Create Linear Back Bone ///////////////////
	
	for(p=root,nodecount=0;p!=0;p=p->filsD,++nodecount)
		{
		while(RightRotate(p)==1) { }
		}

	////////////  Perform Balancing ///////////////////////
	for(i=nodecount/2; i>0; i/=2 )
		{  int k;
		for(p=root,k=0;k<i;++k,p=p->filsD)
			{ LeftRotate(p);  }
		}
	}


