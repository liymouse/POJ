#include <stdio.h>

int t[102][102] , a[102][102];
int f , v , i , j , k;

int main()
{
	scanf("%d %d" , &f , &v);
	for (i = 0; i < f; i ++)
		for (j = 0; j < v; j ++)
			scanf("%d" , &a[i][j]);
	for (i = 0; i <= f; i ++) t[i][v] = -10000;
	for (i = v-1; i >= 0; i --)
		if (t[f-1][i + 1] > a[f-1][i]) t[f-1][i] = t[f-1][i+1];
		else t[f-1][i] = a[f-1][i];
	for (i = f-2; i >= 0; i --)
	{
		for (j = v-1; j >= 0; j --)
			if (t[i][j+1] > t[i+1][j+1] + a[i][j]) t[i][j] = t[i][j+1];
			else t[i][j] = t[i+1][j+1] + a[i][j];
	}
	printf("%d\n" , t[0][0]);
    return 0;
}

