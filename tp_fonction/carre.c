#include <stdio.h>
double carre (double a)
	{
	return a*a;
	}
int main (){
double x=0;
printf("x=");
scanf("%lf", &x);
x=carre (x);
printf("Le carré de x est %lf\n", x);
return 0;
}
