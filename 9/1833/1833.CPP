#include <stdio.h>
#include <string.h>

int main()
{
int a[1024] , b[1025];
int n , k , i , j , m;

	while (scanf("%d %d" , &n , &m) == 2)
	{
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		if (n == 1) {printf("%d\n" , a[0]); continue;}
		i = n-1;
		while (m --)
		{
			memset(b , 0 , sizeof(b));
			i = n-1;
			while ((i > 0) && (a[i-1] > a[i]))
			{
				b[a[i]] = 1; i --;
			}
			if ((i == 0) && (a[0] > a[1]))
			{
				for (j = 0; j < n; j ++) a[j] = j + 1;
			}
			else
			{
				b[a[i]] = 1; i --;
				b[a[i]] = 1; k = a[i];
				for (j = k+1; j <= n; j ++) if (b[j] == 1) break;
				a[i] = j; b[j] = 0; i ++;
				for (j = 1; j <= n; j ++)
					if (b[j] == 1) a[i ++] = j;
			}
		}
		for (i = 0; i < n-1; i ++) printf("%d " , a[i]);
		printf("%d\n" , a[n-1]);
	}
	return 0;
}
