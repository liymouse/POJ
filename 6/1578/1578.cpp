#include <stdio.h>
#include <string.h>

int main()
{
char geshi[30];
char word[21][79][30] , s[100];
int n , i , Lo[79] , t , L , j , k , sum;

	gets(geshi);
	n = strlen(geshi); k = 0;
	memset(Lo , 0 , sizeof(Lo));
	while (1)
	{
		gets(s);
		if ((s[0] != '<') && (s[0] != '>') && (s[0] != '=') && (s[0] != '*'))
		{
			t = 0; L = strlen(s); j = 0;
			for (i = 0; i < L ; i ++)
			{
				if (s[i] != '&') word[k][t][j ++] = s[i];
				else
				{
					word[k][t][j] = 0;
					j = 0; t ++;
				}
			}
			word[k][t][j] = 0; t ++;
			for (i = 0; i < n; i ++)
			{
				L = strlen(word[k][i]);
				if (L > Lo[i]) Lo[i] = L;
			}
			k ++;
		}
		else
		{
			sum = 0;
			for (i = 0; i < n; i ++) sum += Lo[i];
			printf("@");
			for (i = 0; i < sum + 3 * n - 1; i ++) printf("-");
			printf("@\n");
			for (i = 0; i < k; i ++)
			{
				for (j = 0; j < n; j ++)
				{
					printf("| ");
					L = strlen(word[i][j]);
					switch (geshi[j])
					{
						case '>' :
							for (t = 0; t < Lo[j] - L; t ++) printf(" ");
							printf("%s " , word[i][j]);
						break;
						case '<' :
							printf("%s" , word[i][j]);
							for (t = 0; t <= Lo[j] - L; t ++) printf(" ");
						break;
						case '=' :
							for (t = 0; t < (Lo[j] - L) / 2; t ++) printf(" ");
							printf("%s" , word[i][j]);
							if ((Lo[j] - L) % 2 == 0)
								for (t = 0; t <= (Lo[j] - L) / 2; t ++) printf(" ");
							else
								for (t = 0; t <= (Lo[j] - L) / 2 + 1; t ++) printf(" ");
						break;
					}
				}
				printf("|\n");
				if (i == 0)
				{
					for (j = 0; j < n; j ++)
					{
						if (j == 0) printf("|"); else printf("+");
						for (t = 0; t < Lo[j] + 2; t ++) printf("-");
					}
					printf("|\n");
				}
			}
			printf("@");
			for (i = 0; i < sum + 3 * n - 1; i ++) printf("-");
			printf("@\n");
			if (s[0] == '*') break;
			strcpy(geshi , s); n = strlen(geshi);
			k = 0;
			memset(Lo , 0 , sizeof(Lo));
		}
	}
	return 0;
}