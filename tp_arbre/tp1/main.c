#include "arbre.h"

int main ()
{
Noeud * racine = NULL;
racine = inserer("avion","plane",racine);
printf("FR: %s\nEN: %s\n",racine->fr, racine->en);
racine = inserer("age", "age", racine);
printf("FR: %s\nEN: %s\n",racine->filsG->fr, racine->filsG->en);
racine = inserer("noeud", "node", racine);
printf("FR: %s\nEN: %s\n",racine->filsD->fr, racine->filsD->en);
printf("%s\n", traduction("noeud",racine));
printf("%s\n", traduction("age",racine));
printf("%s\n", traduction("avion",racine));
parcoursGRD(racine);
}
