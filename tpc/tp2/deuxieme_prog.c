# include <stdio.h>
int main () {
int a=12;
short b=23;
char c='y';
printf ("a=%d\n",a);
printf ("b=%d\n",b);
printf ("c=%c\n",c);
printf ("c=%d\n",c);
c=122;
printf ("c=%c\n",c);
printf ("a=%x\n",a);
printf ("b=%x\n",b);
printf ("c=%x\n",c);
printf ("Taille de a:%ld\n",sizeof(a));
printf ("Taille de b:%ld\n",sizeof(b));
printf ("Taille de c:%ld\n",sizeof(c));
printf ("Adresse de a:%p\n",&a);
printf ("Adresse de b:%p\n",&b);
printf ("Adresse de c:%p\n",&c);
return 0;
}
