#include <stdio.h>
void increment (int *pi){
//Prologue
int i= *pi;
i++;
//Epilogue
*pi= i;
}
int main(){
int i=0;
increment (&i);
printf ("i=%d\n",i);
return 0;
}
