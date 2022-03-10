#include <stdio.h>
#include <string.h>

int main()
{
char s[6];
int i , L , tot , b , j;

	while (scanf("%s" , s) == 1)
	{
		L = strlen(s); b = 0;
		for (i = 1; i < L; i ++)
			if (s[i] <= s[i-1]) {b = 1; break;}
		if (b == 1) printf("0\n");
		else
		{
			tot = 0;
			while (1)
			{
				if (L == 1) {tot += s[0] - 'a' + 1; break;}
				else
				{
					tot += s[L-1] - s[L-2];
					i = L-2;
					while ((i > 0) && (s[i] - 1 == s[i-1])) i --;
					if ((i == 0) && (s[0] == 'a'))
					{
						L --;
						for (j = L-1; j >= 0; j --) s[j] = 'z' + j - L + 1;
					}
					else
					{
						s[i] --;
						for (j = L - 1; j > i; j --) s[j] = 'z' + j - L + 1;
					}
				}
			}
			printf("%d\n" , tot);
		}
	}
}