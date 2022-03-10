#include <stdio.h>
#include <string.h>

int f[410][210];

int main()
{
int ca , cas;
int i , j , k , L1 , L2 , L;
char s1[210] , s2[210] , s[500];

	scanf("%d" , &ca);
	for (cas = 1; cas <= ca; cas ++)
	{
		scanf("%s %s %s" , s1 , s2 , s);
		i = 0; j = 0; k = 0;
		L1 = strlen(s1); L2 = strlen(s2); L = strlen(s);
		memset(f , 0 , sizeof(f));

		f[0][0] = 1;
		for (k = 1; k <= L; k ++)
			for (i = 0; i <= L1; i ++)
			{
				j = k - i;
				if (j > L2 || j < 0) continue;
				if (i > 0 && s1[i-1] == s[k-1]) f[k][i] = f[k-1][i-1];
				if (f[k][i] == 0 && j > 0 && s2[j-1] == s[k-1]) f[k][i] = f[k-1][i];
			}
		
		printf("Data set %d: " , cas);
		if (f[L][L1]) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
