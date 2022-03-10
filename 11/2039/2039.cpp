#include <stdio.h>
#include <string.h>

int main()
{
int n , i , j , L;
char str[201];
char s[20][100];

	while (scanf("%d\n" , &n) == 1)
	{
		if (n == 0) break;
		scanf("%s" , str);
		L = strlen(str);
		for (i = 0; i < L; i ++)
			if ((i/n) % 2 == 0)
				s[i/n][i%n] = str[i];
			else s[i/n][n - i%n -1] = str[i];
		for (j = 0; j < n; j ++) for (i = 0; i < L / n; i ++) printf("%c" , s[i][j]);
		printf("\n");
	}
	return 0;
}