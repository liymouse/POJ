#include <stdio.h>

int main()
{
char k , c;

	k = 0;
	while (scanf("%c" , &c) != EOF)
	{
		if ((c == '"') && (k == 0)) {printf("``"); k = 1;}
		else if ((c == '"') && (k == 1)) {printf("''"); k = 0;}
			else printf("%c" , c);
	}
	return 0;

}