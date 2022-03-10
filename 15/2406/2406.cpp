#include <stdio.h>
#include <string.h>

char s[1000010];
int next[1000010];

int main()
{
int L , i , j;

	while (scanf("%s" , s) == 1)
	{
		if (s[0] == '.') break;
		L = strlen(s);
		i = 0; next[0] = -1; j = -1;
		while (i < L)
		{
			if (j < 0 || s[i] == s[j]) { i ++; j ++; next[i] = j; }
			else j = next[j];
		}
		i -= j; //重复串的长度
		if (L % i == 0) printf("%d\n" , L / i);
		else printf("1\n");
	}
	return 0;
}