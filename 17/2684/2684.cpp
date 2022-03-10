#include <stdio.h>
#include <math.h>
#include <string.h>

struct kk{int Long[10] , f[10];}a[51];
int m[51];

int check(int L , kk x , kk y)
{
int i , b;

	b = 1;
	for (i = 0; i < L-1; i ++) if (x.Long[i] != y.Long[i]) {b = 0; break;}
	for (i = 0; i < L-2; i ++) if (x.f[i] != y.f[i]) {b = 0; break;}
	if (b == 0)
	{
		b = 1;
		for (i = L-2; i >= 0; i --) if (x.Long[i] != y.Long[L-2-i]) {b = 0; break;}
		if (b)
		{
			for (i = 0; i < L-2; i ++)
				if (x.f[i] == 1) x.f[i] = -1;
				else x.f[i] = 1;
			for (i = L-3; i >= 0; i --) if (x.f[i] != y.f[L-3-i]) {b = 0; break;}
		}
	}
	return b;
}

int main()
{
int n , i , j , x1 , y1 , x2 , y2 , x3 , y3;
int b[51];

	//freopen("2684in2.txt" , "r" , stdin);
	//freopen("2684out.txt" , "w" , stdout);
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		memset(a , 0 , sizeof(a));
		for (i = 0; i <= n; i ++)
		{
			scanf("%d" , &m[i]);
			scanf("%d %d" , &x1 , &y1);
			scanf("%d %d" , &x2 , &y2);
			if (x1 == x2) a[i].Long[0] = int(fabs(y1-y2));
			else a[i].Long[0] = int(fabs(x1-x2));
			for (j = 2; j < m[i]; j ++)
			{
				scanf("%d %d" , &x3 , &y3);
				if (x3 == x2)
				{
					a[i].Long[j-1] = int(fabs(y3 - y2));
					if ((y3 < y2) && (x2 > x1)) a[i].f[j-2] = 1;
					else if ((y3 < y2) && (x2 < x1)) a[i].f[j-2] = -1;
						else if ((y3 > y2) && (x2 > x1)) a[i].f[j-2] = -1;
							else a[i].f[j-2] = 1; 
				}
				else
				{
					a[i].Long[j-1] = int(fabs(x3 - x2));
						if ((x3 < x2) && (y1 < y2)) a[i].f[j-2] = -1;
						else if ((x3 > x2) && (y1 < y2)) a[i].f[j-2] = 1;
							else if ((x3 < x2) && (y1 > y2)) a[i].f[j-2] = 1;
								else a[i].f[j-2] = -1;
				}
				x1 = x2; y1 = y2;
				x2 = x3; y2 = y3;
			}
		}
		memset(b , 0 , sizeof(b));
		for (i = 1; i <= n; i ++)
			if ((m[i] == m[0]) && check(m[0] , a[i] , a[0])) b[i] = 1;
		for (i = 1; i <= n; i ++) if (b[i]) printf("%d\n" , i);
		printf("+++++\n");
	}
	return 0;
}

