#include <stdio.h>
#include <string.h>

int main()
{
int a[800] , b[10];
int n , i , j , k;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		memset(a , 0 , sizeof(a));
		memset(b , 0 , sizeof(b));
		a[0] = 1; k = 1;
		for (i = 2; i <= n; i ++)
		{
			for (j = 0; j < k; j ++)
				a[j] *= i;
			for (j = 0; j < k; j ++)
				if (a[j] > 9)
				{
					a[j+1] += a[j]/10;
					a[j] %= 10;
				}
			if (a[k] > 0) k ++;
			while (a[k-1] > 9) {a[k] += a[k-1] / 10; a[k-1] %= 10; k ++;}
		}
		for (i = 0; i < k; i ++) b[a[i]] ++;
		printf("%d! --\n" , n);
		printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n" , b[0] , b[1] , b[2] , b[3] , b[4]);
		printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n" , b[5] , b[6] , b[7] , b[8] , b[9]);
	}
	return 0;
}