#include <stdio.h>
#include <string.h>

int main()
{
char s[100000] , t[100000];
int i , j , Ls , Lt;

	while (scanf("%s %s" , s , t) == 2)
	{
		i = 0; j = 0;
		Ls = strlen(s); Lt = strlen(t);
		for (j = 0; j < Lt; j ++)
		{
			if (s[i] == t[j]) i ++;
			if (i == Ls) break;
		}
		if (i == Ls) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}