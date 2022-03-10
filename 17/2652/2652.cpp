#include <stdio.h>

struct Queue{int num , t;}a[10001] , b[10001];
int rt[10001];

int min(int x , int y)
{
	return x < y ? x : y;
}

int main()
{
int c , i;
int n , m , t , tmp;
int r1 , r2 , top1 , top2 , tottime , k;
char s[10];

	scanf("%d" , &c);
	while (c --)
	{
		scanf("%d %d %d" , &n , &t , &m);
		top1 = 0; top2 = 0;
		for (i = 0; i < m; i ++)
		{
			scanf("%d %s" , &tmp , s);
			if (s[0] == 'l')
			{
				a[top1].num = i; a[top1].t = tmp;
				top1 ++;
			}
			else
			{
				b[top2].num = i; b[top2].t = tmp;
				top2 ++;
			}
		}
		r1 = 0; r2 = 0; tottime = 0; k = 0;
		a[top1].t = 999999999; b[top2].t = 999999999;
		while (1)
		{
			if ((r1 == top1) && (r2 == top2)) break;
			if (k == 0)
			{
				if ((tottime < a[r1].t) && (tottime < b[r2].t))
				{
					if (a[r1].t <= b[r2].t) tottime = a[r1].t;
					else tottime = b[r2].t;
				}
				else if (tottime >= a[r1].t)
				{
					tottime += t;
					for (i = r1; i < min(r1 + n , top1); i ++)
						if (a[i].t <= tottime-t) rt[a[i].num] = tottime;
						else break;
					r1 = i; k = 1;
				}
				else
				{
					tottime += t; k = 1;
				}
			}
			else
			{
				if ((tottime < a[r1].t) && (tottime < b[r2].t))
				{
					if (b[r2].t <= a[r1].t) tottime = b[r2].t;
					else tottime = a[r1].t;
				}
				else if (tottime >= b[r2].t)
				{
					tottime += t;
					for (i = r2; i < min(r2 + n , top2); i ++)
						if (b[i].t <= tottime-t) rt[b[i].num] = tottime;
						else break;
					r2 = i; k = 0;
				}
				else
				{
					tottime += t; k = 0;
				}
			}

		}
		for (i = 0; i < m; i ++) printf("%d\n" , rt[i]);
		printf("\n");
	}
	return 0;
}
