#include <stdio.h>
#include <string.h>

char a[100010];
char b[100010];

int main()
{
int n , c , i , j , k , t;
int num[15] , d[15];
char *p , *q , *h;

	while (scanf("%d %d" , &c , &n) == 2)
	{
		for (i = 0; i < n; i ++) scanf("%d %d" , &num[i] , &d[i]);
		memset(a , 0 , sizeof(a));
		memset(b , 0 , sizeof(b));
		p = a; q = b;
		p[0] = 1;
		for (t = 0; t < n; t ++)
		{
			for (i = 0; i <= c; i ++)
				if (p[i])
				{
					for (j = 0; j < num[t]; j ++)
						if (i + j * d[t] <= c)
							q[i + j * d[t]] = 1;
				}
			h = p; p = q; q = h;
			memset(q , 0 , sizeof(q));
		}
		for (i = c; i >= 0; i --) if (p[i]) break;
		printf("%d\n" , i);
	}
	return 0;
}