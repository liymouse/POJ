#include <stdio.h>

struct{
	int n , num[100];
}a[100000];
int L[100000] = {0};
int que[100000];

int main()
{
int n , i , j , s , t , p , q , done , x;

	scanf("%d" , &n);
	for (i = 0; i < n; i ++)
	{
		scanf("%d" , &x);
		scanf("%d" , &a[x].n);
		for (j = 0; j < a[x].n; j ++) scanf("%d" , &a[x].num[j]);
	}
	scanf("%d %d" , &s , &t);
	printf("%d %d " , s , t);
	p = 0; q = 0; done = 0;
	que[0] = s; L[s] = 1;
	while (1)
	{
		for (i = 0; i < a[que[p]].n; i ++)
		{
			if (L[a[que[p]].num[i]] == 0)
			{
				q ++; que[q] = a[que[p]].num[i];
				L[que[q]] = L[que[p]] + 1;
				if (que[q] == t) {done = 1; break;}
			}
		}
		p ++;
		if (done) break;
	}
	printf("%d\n" , L[que[q]] - 2);
	return 0;
}