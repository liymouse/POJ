//PKU 2926
//每一组数为x1,x2...x5，求|x1-y1|+|x2-y2|+...+|x5-y5|最大值
#include <stdio.h>
#include <string.h>

double a[100000][5];
double b[100000];

int main()
{
int n , i , j , k , t;
double max , min , res;
int sign[5];

	scanf("%d" , &n);
	for (i = 0; i < n; i ++)
		for (j = 0; j < 5; j ++)
			scanf("%lf" , &a[i][j]);
	res = 0;
	for (t = 0; t < 16; t ++)
	{
		memset(b , 0 , sizeof(b));
		k = t;
		for (i = 4; i >=0; i --)
		{
			if (k & 1) sign[i] = -1; else sign[i] = 1;
			k = k >> 1;
		}
		for (i = 0; i < n; i ++)
			for (j = 0; j < 5; j ++)
				b[i] += sign[j] * a[i][j];
		max = -100000000; min = 100000000;
		for (i = 0; i < n; i ++)
		{
			if (b[i] > max) max = b[i];
			if (b[i] < min) min = b[i];
		}
		if (max - min > res) res = max - min;
	}
	printf("%.2lf\n" , res);
	return 0;
}
