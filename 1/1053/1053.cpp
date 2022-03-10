#include <stdio.h>

char s[12][6];

int match(int i , int j , int k)
{
int t;

	for (t = 0; t < 4; t ++)
		if ((!((s[i][t] == s[j][t]) && (s[j][t] == s[k][t]))) &&
		(!((s[i][t] != s[j][t]) && (s[j][t] != s[k][t]) && (s[k][t] != s[i][t]))))
		return 0;
	return 1;
}

int main()
{
int i , j , k , tot;

	while (scanf("%s" , &s[0]) == 1)
	{
		for (i = 1; i < 12; i ++) scanf("%s" , &s[i]);
		printf("CARDS: ");
		for (i = 0; i < 12; i ++) printf(" %s" , s[i]);
		printf("\n");
		printf("SETS:   ");
		tot = 0;
		for (i = 0; i < 12; i ++)
			for (j = i+1; j < 12; j ++)
				for (k = j + 1; k < 12; k ++)
					if (match(i , j , k))
					{
						tot ++;
						if (tot > 1) printf("        ");
						printf("%d.  %s %s %s\n" , tot , s[i] , s[j] , s[k]);
					}
		if (tot == 0) printf("*** None Found ***\n");
		printf("\n");
	}
	return 0;
}