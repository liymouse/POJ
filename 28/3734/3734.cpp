#include <stdio.h>
#include <string.h>

int is[4][4] =  {{2 , 1 , 1 , 0},
				{1 , 2 , 0 , 1},
				{1 , 0 , 2 , 1},
				{0 , 1 , 1 , 2}};
int s[4][4] , res[4][4];

void init()
{
	memset(res , 0 , sizeof(res));
	for (int i = 0; i < 4; i ++) res[i][i] = 1;
	for (int i = 0; i < 4; i ++) for (int j = 0; j < 4; j ++)
		s[i][j] = is[i][j];
}

void cheng(int a[4][4] , int b[4][4])
{
	int c[4][4];

	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
		{
			c[i][j] = 0;
			for (int k = 0; k < 4; k ++)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % 10007;
		}
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
			a[i][j] = c[i][j];
}

int main()
{
int ca;
int n;

	scanf("%d" , &ca);
	while (ca--)
	{
		scanf("%d" , &n);
		init();
		while (n)
		{
			if ((n & 1) == 1)
			{
				cheng(res , s);
			}
			cheng(s , s);
			n /= 2;
		}
		printf("%d\n" , res[0][0]);
	}
	return 0;
}
