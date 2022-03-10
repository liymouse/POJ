#include <stdio.h>

int main()
{
int a[31][31] = {0};
int i , j , g , L;

	for (i = 0; i <= 30; i ++) a[i][0] = i;
	for (i = 0; i <= 30; i ++) a[1][i] = 1;
	for (i = 2; i <= 30; i ++)
		for (j = 1; j <= 30; j ++) a[i][j] = 1 + a[i-1][j-1] + a[i-1][j];
	i = 0;
	while (scanf("%d %d" , &g , &L) == 2)
	{
		if ((g || L) == 0) break;
		i ++;
		printf("Case %d: %d\n" , i , a[g][L]);
	}
	return 0;
}