#include <stdio.h>
#include <string.h>
#define MAX 4500
#define NUM 100000000

int main()
{
int n , i , j;
__int64 a[MAX] , b[MAX] , ans[MAX] , k , x;

	scanf("%d" , &n);
	printf("2\n"); n --;
	a[0] = 1; a[1] = 2;
	while (n --)
	{
		for (i = 1; i <= a[0]; i ++) b[i] = a[i];
		b[0] = a[0];
		b[1] --; i = 1;
		while (b[i] < 0) {b[i] += NUM; b[i+1] --; i ++;}
		if (b[b[0]] == 0) b[0] --;


		memset(ans , 0 , sizeof(ans));
		for (i = 1; i <= a[0]; i ++)
			for (j = 1; j <= b[0]; j ++)
			{
				ans[i + j - 1] += a[i] * b[j];
				if (ans[i + j - 1] > 9)
				{
					ans[i + j] += ans[i + j - 1]/NUM;
					ans[i + j - 1] %= NUM;
				}
			}
		if (ans[a[0] + b[0]] == 0) ans[0] = a[0] + b[0] - 1; else ans[0] = a[0] + b[0];

		ans[1] ++; i = 1;
		while (ans[i] >= NUM) {ans[i+1] ++; ans[i] -= NUM;}
		printf("%I64d" , ans[ans[0]]);
		for (i = ans[0]-1; i > 0; i --)
		{
			x = ans[i]; k = 0;
			while (x > 0) {k ++; x /= 10;}
			for (j = 0; j < 8 - k; j ++) printf("0");
			printf("%I64d" , ans[i]);
		}
		printf("\n");
		for (i = 1; i <= ans[0]; i ++) a[i] = ans[i];
		a[0] = ans[0];
	}
	return 0;
}