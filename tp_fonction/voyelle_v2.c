# include <stdio.h>
# include <string.h>
# define TAILLE_MAX 100
char * voyelles (const char *chaine,int *compteur){
int i=0;
int j=0;
char voy[TAILLE_MAX+1];
for (i=0;i<strlen(chaine);i++)
	{
	if (chaine[i]=='a' || chaine[i]=='e' || chaine[i]=='i' || chaine[i]=='o' || chaine[i]=='u' || chaine[i]=='y')
		{
		(*compteur)++;
		voy[j]=chaine[i];
		j++;
		}
	}
voy[j]='\0';
return voy;
}
int main(){
char chaine[TAILLE_MAX+1];
int nb_voy=0;
printf("Saisir la chaine: ");
fgets ( chaine, TAILLE_MAX+1, stdin);
if (chaine[strlen(chaine)-1]=='\n') chaine[strlen(chaine)-1]='\0';
printf ("Les voyelles utiliser sont: %s\n",voyelles(chaine, &nb_voy));
printf ("Nombre de voyelles:%d\n",nb_voy);

return 0;
}
