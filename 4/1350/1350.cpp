#include <stdio.h>
#include <string.h>

int main()
{
int n , a[4] , x , y , i , j , tot , k;

	while (scanf("%d" , &n) == 1)
	{
		if (n == -1) break;
		printf("N=%d:\n" , n);
		for (i = 0; i < 4; i ++) a[i] = 0;
		i = 0;
		while (n > 0) {a[i ++] = n % 10; n /= 10;}
		x = 0; k = i;
		for (i = 1; i < 4; i ++) if (a[i-1] != a[i]) {x = 1; break;}
		if ((x == 0) || (k != 4)) printf("No!!\n");
		else
		{
			tot = 0;
			while (1)
			{
				tot ++;
				for (i = 0; i < 4; i ++)
					for (j = 1; j < 4 - i; j ++)
						if (a[j-1] < a[j]) {x = a[j-1]; a[j-1] = a[j]; a[j] = x;}
				x = 0; y = 0;
				for (i = 0; i < k; i ++) x = x * 10 + a[i];
				for (i = 3; i >= 0; i --) y = y * 10 + a[i];
				printf("%d-%d=%d\n" , x , y , x - y);
				n = x - y; i = 0;
				if ((n == 6174) || (n == 0)) {printf("Ok!! %d times\n" , tot); break;}
				for (i = 0; i < 4; i ++) a[i] = 0;
				i = 0;
				while (n > 0) {a[i ++] = n % 10; n /= 10;} 
				k = i;
			}
		}
	}
	return 0;
}