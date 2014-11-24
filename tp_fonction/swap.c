#include <stdio.h>
void swap(int *i, int*j)
{
	int k=0;
	k=*i;
	*i=*j;
	*j=k;
}
int main()
{
	int i=12;
	int j=5;
	swap(&i,&j);
	printf("i=%d,j=%d\n",i,j);
	return 0;
}
