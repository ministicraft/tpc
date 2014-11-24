# include "voyelles.h"
int voyelles(char *chaine)//char* pointeur sur char
{
	int i=0;
	int j=0;
	for (i=0;i<strlen(chaine);i++)
		{
		if (chaine[i]=='a' || chaine[i]=='e' || chaine[i]=='i' || chaine[i]=='o' || chaine[i]=='u' || chaine[i]=='y')
			{
			chaine[j]=chaine[i];
			j++;
			}
		}
	chaine[j]='\0';
	return j;
}
