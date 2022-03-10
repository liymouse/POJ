#include <stdio.h>

int main()
{
int n , a[31] , sum1 , sum2 , x , y , i;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 1; i <= n; i ++) scanf("%d" , &a[i]);
		sum1 = 0; sum2 = 0;
		x = 0; y = n+1;
		while (x < y - 1)
		{
			if (sum1 < sum2) {x ++; sum1 += a[x];}
			else if (sum1 > sum2) {y --; sum2 += a[y];}
			else if (x < y - 2) {x ++; y --; sum1 += a[x]; sum2 += a[y];}
		}
		if (sum1 == sum2)
			printf("Sam stops at position %d and Ella stops at position %d.\n" , x , y);
		else printf("No equal partitioning.\n");
	}
	return 0;
}