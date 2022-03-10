#include <stdio.h>
#include <string.h>
#define max 14

int father[max];

int getfather(int x)
{
int f;

	if (father[x] == x) return x;
	else
	{
		f = getfather(father[x]);
		father[x] = f;
		return f;
	}
}

int main()
{
struct {int x , y;} a[max] = {0};
int b[max] = {0} , c[max] = {0};
int s , t , k , ok , tot , i , n;

	ok = 1; tot = 0; k = 0;
	for (i = 0; i < max; i ++) father[i] = i;
	while (scanf("%d %d" , &s , &t) == 2)
	{
		if ((s == -1) && (t == -1)) break;
		if ((s || t) == 0)
		{
			n = 0;
			for (i = 0; i < max; i ++) if (b[i]) n ++;
			if (n > 0)
			{
				if (tot != n - 1) ok = 0;
				else
				{
					for (i = 0; i < tot; i ++)
					{
						s = getfather(a[i].x);
						t = getfather(a[i].y);
						father[t] = s;
					}
					n = 0;
					for (i = 0; i < max; i ++)
						if (b[i]) c[getfather(i)] = 1;
					for (i = 0; i < max; i ++) if (c[i]) n ++;
					if (n > 1) ok = 0;
				}
			}
			memset(a , 0 , sizeof(a));
			memset(b , 0 , sizeof(b));
			memset(c , 0 , sizeof(c));
			for (i = 0; i < max; i ++) father[i] = i;
			k ++; tot = 0;
			printf("Case %d is " , k);
			if (ok) printf("a tree.\n");
			else printf("not a tree.\n");
			ok = 1;
		}
		else
		{
			a[tot].x = s; a[tot].y = t;
			b[t] = 1; b[s] = 1; tot ++;
		}
	}
}
