//PKU 2992
//求C(n , k)约数个数
#include <stdio.h>
#include <string.h>
#define NUM 83

int prime[NUM];
int num[440];
int factor[432][10];
int tot[440];

void findprime()
{
char c[432] = {0};
int i , k;

	for (i = 2; i <= 21; i ++)
		if (c[i] == 0)
		{
			k = i + i;
			while (k <= 431)
			{
				c[k] = 1;
				k += i;
			}
		}
	k = 0;
	for (i = 2; i <= 431; i ++) if (c[i] == 0) prime[k ++] = i;
}

void dis(int x)
{
int i , k;

	k = x; num[x] = 0;
	for (i = 0; i < NUM; i ++)
	{
		if (k == 1) break;
		while (k % prime[i] == 0)
		{
			factor[x][num[x] ++] = prime[i];
			k /= prime[i];
		}
	}
}

int main()
{
int n , k , i , j;
__int64 res;

	findprime();
	for (i = 2; i <= 431; i ++) dis(i);
	while (scanf("%d %d" , &n , &k) == 2)
	{
		memset(tot , 0 , sizeof(tot));
		if (k < n - k) k = n - k;
		for (i = k + 1; i <= n; i ++)
			for (j = 0; j < num[i]; j ++) tot[factor[i][j]] ++;
		for (i = 2; i <= n - k; i ++)
			for (j = 0; j < num[i]; j ++) tot[factor[i][j]] --;
		res = 1;
		for (i = 0; i < 432; i ++) if (tot[i] > 0) res *= tot[i] + 1;
		printf("%I64d\n" , res);
	}
	return 0;
}
