#include <stdio.h>
#include <string.h>

int max(int x , int y)
{
	return x > y ? x : y;
}

int main()
{
int a[101][101] , x , y , n , i , j , f[101][101];

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		memset(a , 0 , sizeof(a));
		for (i = 0; i < n; i ++) {scanf("%d %d" , &x , &y); a[x][y] ++;}
		memset(f , 0 , sizeof(f));
		for (i = 1; i <= 100; i ++)
			for (j = 1; j <= 100; j ++)
				f[i][j] = max(f[i-1][j] , f[i][j-1]) + a[i][j];
		printf("%d\n" , f[100][100]);
	}
	printf("*\n");
	return 0;
}