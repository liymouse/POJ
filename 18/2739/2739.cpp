#include <stdio.h>

int p[10000] = {0};
int pri[1230];
int num;

void prime()
{
    int i , k;

	for (i = 2; i < 100; i ++)
		if (p[i] == 0)
		{
			k = i + i;
			while (k < 10000)
			{
				p[k] = 1;
				k += i;
			}
		}
	num = 0;
	for (i = 2; i < 10000; i ++)
		if (p[i] == 0) pri[num ++] = i;
	pri[num] = 10000;
}

int main()
{
    int n , tot , k , j , i;

	prime();
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		tot = 0;
		for (i = 0; i < num; i ++)
			if (pri[i] > n) break;
			else
			{
				k = n; j = i;
				while (k > 0) k -= pri[j ++];
				if (k == 0) tot ++;
			}
		printf("%d\n" , tot);
	}
	return 0;
}
