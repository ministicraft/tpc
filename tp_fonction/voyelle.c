# include <stdio.h>
# include <string.h>
# define TAILLE_MAX 100
int voyelles (const char *chaine,char *voy){
int i=0;
int j=0;
int compteur=0;
for (i=0;i<strlen(chaine);i++)
	{
	if (chaine[i]=='a' || chaine[i]=='e' || chaine[i]=='i' || chaine[i]=='o' || chaine[i]=='u' || chaine[i]=='y')
		{
		compteur++;
		voy[j]=chaine[i];
		j++;
		}
	}
return compteur;
}
int main(){
char chaine[TAILLE_MAX+1];
char voy[TAILLE_MAX+1]={0};
printf("Saisir la chaine: ");
fgets ( chaine, TAILLE_MAX+1, stdin);
if (chaine[strlen(chaine)-1]=='\n') chaine[strlen(chaine)-1]='\0';
printf ("Nombre de voyelles:%d\n", voyelles(chaine,voy));
printf ("Les voyelles utiliser sont: %s\n",voy);
return 0;
}

