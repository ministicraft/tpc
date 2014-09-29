# include <stdio.h>
int main()
{

int age = 0;
printf ("Tapez votre age:");
scanf ("%d",&age);

if (age >= 18)
{
	printf ("vous etes majeur\n");
}
else
{
	printf ("vous etes mineur \n");
}

return 0;
}
