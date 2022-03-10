#include <stdio.h>
#include <string.h>

int main()
{
int n , k , x , y , i;
int f[26][2] , b[26][2];

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		printf("Printing order for %d pages:\n" , n);
		k = n / 4; if (n % 4 != 0) k ++; x = 1;
		memset(f , 0 , sizeof(f));
		memset(b , 0 , sizeof(b));
		for (i = 1; i <= k; i ++)
		{
			if (x <= n) {f[i][1] = x; x ++;}
			else break;
			if (x <= n) {b[i][0] = x; x ++;}
			else break;
		}
		for (i = k; i >= 1; i --)
		{
			if (x <= n) {b[i][1] = x; x ++;}
			else break;
			if (x <= n) {f[i][0] = x; x ++;}
			else break;
		}
		for (i = 0; i <= k; i ++)
		{
			if ((f[i][0] > 0) || (f[i][1] > 0)) 
			{
				printf("Sheet %d, front: " , i);
				if (f[i][0] > 0) printf("%d, " , f[i][0]);
				else printf("Blank, ");
				if (f[i][1] > 0) printf("%d\n" , f[i][1]);
				else printf("Blank\n");
			}
			if ((b[i][0] > 0) || (b[i][1] > 0))
			{
				printf("Sheet %d, back : " , i);
				if (b[i][0] > 0) printf("%d, " , b[i][0]);
				else printf("Blank, ");
				if (b[i][1] > 0) printf("%d\n" , b[i][1]);
				else printf("Blank\n");
			}
		}
	}
	return 0;
}
