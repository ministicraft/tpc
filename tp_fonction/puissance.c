#include <stdio.h>
double puissance (double x, int n)
	{
	int i=0;
	int y=1;
	for (i=0; i<n; i++)
		{
		y=y*x;
		}
	return y;
	}
int main (){
double x=0;
int n=0;
printf("x=");
scanf("%lf", &x);
printf("n=");
scanf("%d", &n);
if (n<0)
	{
	printf("La fonction n'accepte pas les entiers négatifs\n");
else
	}
	{
	x=puissance (x,n);
	printf("Le résultat de x à la puissance %d\n est %lf\n",n ,x);
	}
return 0;
}
