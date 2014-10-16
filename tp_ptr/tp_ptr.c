#include <stdio.h>
int main (){
int a=12;
int *ptr;// ptr est un pointeur sur int
//printf("%d\n", *ptr);//Déférencement d'un pointeur sauvage
printf("Adresse de a:%p\n",&a);
printf("Adresse de ptr:%p\n",&ptr);
printf("Contenue de a:%d\n",a);
ptr=&a; // On donne au pointeur une adresse (contenue dan sle pointeur)
printf("Contenue de ptr:%p\n",ptr);
printf("Contenue de l'adresse pointée par ptr (déférencement):%d\n",*ptr);
printf("Taille de ptr:%ld\n",sizeof(ptr));//8
printf("Taille de *ptr:%ld\n",sizeof(*ptr));//4
//printf("%d\n",*a);// Erreur de compilation
//printf("%d\n",*(&a));// 12
//printf("%p\n",*(&ptr));// Contenue de ptr soit Adr. de a
//printf("%d\n",*(*(&ptr)));//12
/*char c='a';
ptr=&c;// Warning compil: type pointeur incompatible
printf("%d\n",*ptr);// 3169 => incorrect*/
//ptr==>7fff......d0
int c='a';
ptr++;//Arithmétique du pointeur: incrémentation de 1*sizeof(int) car int*ptr
printf("Contenu de ptr:%p\n",ptr); //7fff......d4*/
printf("Ecart entre &c er ptr:%ld\n",ptr-&c);
return 0;
}
