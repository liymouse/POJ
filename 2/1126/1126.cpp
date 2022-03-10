#include <stdio.h>
#include <string.h>
int main()
{
char s[300] = {0};
char f[300][300];
int i , j , k , L;

	while (scanf("%s" , s) == 1)
	{
		memset(f , 0 , sizeof(f));
		L = strlen(s);
		for (j = 0; j < L; j ++)
			if (s[j] >= 'p' && s[j] <= 'z') f[1][j] = 1; else f[i][j] = 0;
		for (i = 2; i <= L; i ++)
			for (j = 0; j <= L - i; j ++)
				if (s[j] >= 'p' && s[j] <= 'z') f[i][j] = 0;
				else if (s[j] == 'N') f[i][j] = f[i-1][j+1];
				else if (s[j] == 'C' || s[j] == 'D' || s[j] == 'I' || s[j] == 'E')
				{
					for (k = 1; k <= i - 2; k ++)
						if ((f[k][j+1] & f[i-k-1][k+j+1]) == 1) {f[i][j] = 1; break;}
				}
		if (f[L][0]) printf("YES\n");
		else printf("NO\n");
		memset(s , 0 , sizeof(s));
	}
	return 0;
}