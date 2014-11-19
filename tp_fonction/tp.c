#include <stdio.h>
void increment (int *pi){
(*pi)++; //Parenthèse du au ordre de prioriter
}
int main(){
int i=0;
increment (&i);
printf ("i=%d\n",i);
return 0;
}
