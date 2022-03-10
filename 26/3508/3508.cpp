#include <stdio.h>
#include <string.h>

char a[1000010] , b[1000010];

int main()
{
int cas = 0;
int i , L , x , k , j , ok;

	while (scanf("%s" , a) == 1)
	{
		if (a[0] == '0') break;
		cas ++;
		printf("%d. " , cas);
		L = strlen(a);
		j = 0; ok = 0;
		for (k = 1; k <= 10; k ++)
		{
			x = k;
			for (i = 0; i < L; i ++)
			{
				x = x * 10 + a[i] - '0';
				if (x >= 11)
				{
					b[j ++] = x / 11 + '0';
					x %= 11;
				}
				else
				{
					b[j ++] = '0';
				}
			}
			if (x == 0 && j == L)
			{
				b[j] = 0;
				ok = 1;
				break;
			}
			else j = 0;
		}
		if (ok == 1) printf("%s\n" , b);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
