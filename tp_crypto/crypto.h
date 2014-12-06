#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE_MAX 10000
char chiffrement(char c,int cle);
char dechiffrement(char c,int cle);
float* analyseFreq(char* texte,int N);
int calculCle(float* tabFreq);
char* saisieChaine();
int saisieCle();
int menu();
void print_Prog();
