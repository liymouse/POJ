#include <stdio.h>
#include <string.h>

#define OFFSET 450

int n , m;
struct 
{
	int sum;
	int sub;
}a[210];
struct
{
	char choose[210];
	int sum;
	int have;
}p[910] , q[910] , *f , *h , *temp;

int main()
{
int cas = 0;
int i , j , x , y , max , k , t , min;

	//freopen("1015.in" , "r" , stdin);
	//freopen("1015.out" , "w" , stdout);
	while (scanf("%d %d" , &n , &m) == 2)
	{
		if (n == 0 && m == 0) break;
		cas ++;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &x , &y);
			a[i].sum = x + y;
			a[i].sub = x - y;
		}
		memset(p , 0 , sizeof(p));
		memset(q , 0 , sizeof(q));
		f = p; h = q;
		f[OFFSET].have = 1;
		for (i = 0; i < m; i ++)
		{
			for (j = 0; j <= 2 * OFFSET; j ++)
			{
				max = -1;
				for (k = 0; k < n; k ++)
					if (j >= a[k].sub && f[j-a[k].sub].have == 1 && f[j-a[k].sub].choose[k] == 0)
					{
						if (f[j-a[k].sub].sum + a[k].sum > max)
						{
							max = f[j-a[k].sub].sum + a[k].sum;
							t = k;
						}
					}
				if (max >= f[j].sum)
				{
					h[j].sum = max;
					h[j].have = 1;
					for (k = 0; k < n; k ++)
						h[j].choose[k] = f[j-a[t].sub].choose[k];
					h[j].choose[t] = 1;
				}
			}
			temp = h; h = f; f = temp;
			for (j = 0; j <= 2 * OFFSET; j ++)
			{
				h[j].have = 1;
				h[j].sum = 0;
			}
		}
		max = 0; min = 10000; k = -1;
		for (i = 0; i <= 2 * OFFSET; i ++)
			if (f[i].have == 1)
			{
				x = 0;
				for (j = 0; j < n; j ++) x += f[i].choose[j];
				if (x != m) continue;
				t = i > OFFSET ? i - OFFSET : OFFSET - i;
				if ((t < min) || (min == t && f[i].sum > max))
				{
					k = i; min = t;
					max = f[i].sum;
				}
			}
		x = 0; y = 0;
		for (i = 0; i < n; i ++)
			if (f[k].choose[i] == 1)
			{
				x += (a[i].sum + a[i].sub) / 2;
				y += (a[i].sum - a[i].sub) / 2;
			}
		printf("Jury #%d\n" , cas);
		printf("Best jury has value %d for prosecution and value %d for defence:\n" , x , y);
		for (i = 0; i < n; i ++)
			if (f[k].choose[i] == 1) printf(" %d" , i + 1);
		printf("\n\n");
	}

	return 0;
}
