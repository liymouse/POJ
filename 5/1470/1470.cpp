#include <stdio.h>

int father[901] , num[901];

int main()
{
int n , x , k , y , i , j , L;
int a[900] , b[900] , s , t;
char st[5];

	while (scanf("%d" , &n) == 1)
	{
		for (i = 1; i <= n; i ++) {father[i] = i; num[i] = 0;}
		for (i = 0; i < n; i ++)
		{
			scanf("%d:(%d)" , &x , &k);
			for (j = 0; j < k; j ++)
			{
				scanf("%d" , &y);
				father[y] = x;
			}
		}
		scanf("%d\n" , &k);
		for (i = 0; i < k; i ++)
		{
			scanf("%s" , st);
			x = 0; j = 1;
			while (st[j] > 0) x = x * 10 + st[j++] - '0';
			scanf("%s" , st);
			y = 0; j = 0;
			while (st[j] != ')') y = y * 10 + st[j++] - '0';
			s = 0;
			while (father[x] != x) {a[s ++] = x; x = father[x];}
			a[s ++] = x;
			t = 0;
			while (father[y] != y) {b[t ++] = y; y = father[y];}
			b[t ++] = y;
			x = 0;
			for (j = 0; j < s; j ++)
			{
				for (L = 0; L < t; L ++)
					if (a[j] == b[L]) {num[a[j]] ++; x = 1; break;}
				if (x) break;
			}
		}
		for (i = 1; i <= n; i ++)
			if (num[i] > 0)
				printf("%d:%d\n" , i , num[i]);
	}
	return 0;
}