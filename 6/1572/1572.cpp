#include <stdio.h>
#include <string.h>

int find(char s1[] , char s2[] , int L1 , int L2)
{
int i , j , b;

	for (i = 0; i <= L1 - L2; i ++)
	{
		b = 0;
		for (j = 0; j < L2; j ++)
			if (s1[i+j] != s2[j]) {b = 1; break;}
		if (b == 0) return i;
	}
	return -1;
}

int main()
{
int n , i , k , L1 , L2 , j , L;
char first[10][81] , sec[10][81];
char s[1000];

	while (scanf("%d\n" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++)
		{
			gets(first[i]); gets(sec[i]);
		}
		gets(s); L = strlen(s);
		for (i = 0; i < n; i ++)
		{
			L1 = strlen(first[i]); L2 = strlen(sec[i]);
			while (1)
			{
				k = find(s , first[i] , L , L1);
				if (k == -1) break;
				if (L1 > L2)
					for (j = k; j < L - L1; j ++) s[j + L2] = s[j + L1];
				else if (L1 < L2)
					for (j = L - 1; j >= k + L1; j --) s[j + L2 - L1] = s[j];
				L = L - L1 + L2;
				s[L] = 0;
				for (j = k; j < k + L2; j ++) s[j] = sec[i][j-k];
			}
		}
		printf("%s\n" , s);
	}
	return 0;
}