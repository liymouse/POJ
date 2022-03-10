#include <stdio.h>
#include <string.h>

int main()
{
int n;
int a[101][200] , i , p[100] , pre[101][200] , k[101][200] , t , j , b;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		if (n == 1) {printf("1\n"); continue;}
		p[0] = 1;
		for (i = 1; i < 100; i ++) p[i] = (p[i-1] * 10) % n;
		memset(a , 0 , sizeof(a));
		a[1][1] = 1; a[1][0] = 1; b = 0;
		k[1][1] = 1; k[1][0] = 0;
		for (i = 2; i <= 100; i ++)
		{
			for (j = 0; j < n; j ++)
			{
				if (a[i-1][j] == 1)
				{
					a[i][j] = 1; 
					pre[i][j] = j; k[i][j] = 0;
					a[i][(j + p[i-1]) % n] = 1;
					pre[i][(j + p[i-1]) % n] = j;
					k[i][(j + p[i-1]) % n] = 1;
					if ((j + p[i-1]) % n == 0) b = 1;
					if (b) break;
				}
			}
			if (b) break;
		}
		t = 0;
		while (i > 0)
		{
			printf("%d" , k[i][t]);
			t = pre[i][t]; i --;
		}
		printf("\n");
	}
	return 0;
}