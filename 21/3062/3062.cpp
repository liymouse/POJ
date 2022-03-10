#include <stdio.h>

int main()
{
	char ch[10000];
	while (gets(ch))
	{
		printf("%s\n",ch);
	}
	return 0;
}
