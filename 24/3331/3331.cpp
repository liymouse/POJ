#include <stdio.h>
#include <string.h>

int main()
{
int a[1000];
int k , n , t , d , i , j , s;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &n , &d);
		memset(a , 0 , sizeof(a));
		a[0] = 1; k = 1;
		for (i = 1; i <= n; i ++)
		{
			for (j = 0; j < k; j ++)
				a[j] *= i;
			for (j = 0; j < k; j ++)
				if (a[j] > 9)
				{
					s = a[j] / 10;
					a[j+1] += s;
					a[j] = a[j] - s * 10;
				}
			while (a[k] > 0)
			{
				if (a[k] > 9)
				{
					s = a[k] / 10; a[k+1] += s; a[k] = a[k] - s * 10;
				}
				k ++;
			}
		}
		n = 0;
		for (i = 0; i < k; i ++) if (a[i] == d) n ++;
		//for (i = k-1; i >= 0; i --) printf("%d" , a[i]);printf("\n");
		printf("%d\n" , n);
	}
	return 0;
}
