#include "crypto.h"

char chiffrement (char c, int cle)
{
	if (c >= 'A' & c <= 'Z')
	{
		c=c+cle
	}
printf("%c\n",c);
}
