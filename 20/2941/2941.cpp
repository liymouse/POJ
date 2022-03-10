#include <stdio.h>

int main()
{
int a[1000][1000];
int i , j , b;
int n;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++) for (j = 0; j < n; j ++) scanf("%d" , &a[i][j]);
		b = 1;
		for (i = 0; i < n - 1; i ++)
		{
			for (j = 0; j < n - 1; j ++)
				if (a[i][j] + a[i+1][j+1] != a[i+1][j] + a[i][j+1]) {b = 0; break;}
			if (b == 0) break;
		}
		if (b) printf("homogeneous\n");
		else printf("not homogeneous\n");
	}
	return 0;
}