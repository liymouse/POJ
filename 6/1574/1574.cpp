#include <stdio.h>
#include <string.h>

struct tri{int a , b , c;}tr[6];
struct sec{int L , R , f;}a[6];
int b[6] , max , tot;

void find(int x)
{
int i;

	if (x == 6)
	{
		tot = 0;
		for (i = 0; i < 6; i ++) tot += a[i].f;
		if (tot > max) max = tot;
		return;
	}
	if (x == 5)
	{
		for (i = 0; i < 6; i ++)
			if (b[i] == 0)
			{
				b[i] = 1;
				if ((tr[i].a == a[x-1].R) && (tr[i].b == a[0].L))
				{
					a[x].L = tr[i].a; a[x].R = tr[i].b; a[x].f = tr[i].c;
					find(x + 1);
				}
				if ((tr[i].b == a[x-1].R) && (tr[i].c == a[0].L))
				{
					a[x].L = tr[i].b; a[x].R = tr[i].c; a[x].f = tr[i].a;
					find(x + 1);
				}
				if ((tr[i].c == a[x-1].R) && (tr[i].a == a[0].L))
				{
					a[x].L = tr[i].c; a[x].R = tr[i].a; a[x].f = tr[i].b;
					find(x + 1);
				}
				b[i] = 0;
			}
	}
	else if (x == 0)
	{
		for (i = 0; i < 6; i ++)
			if (b[i] == 0)
			{
				b[i] = 1;
				a[x].L = tr[i].a; a[x].R = tr[i].b; a[x].f = tr[i].c;
				find(x + 1);
				a[x].L = tr[i].b; a[x].R = tr[i].c; a[x].f = tr[i].a;
				find(x + 1);
				a[x].L = tr[i].c; a[x].R = tr[i].a; a[x].f = tr[i].b;
				find(x + 1);
				b[i] = 0;
			}
	}
	else
	{
		for (i = 0; i < 6; i ++)
			if (b[i] == 0)
			{
				b[i] = 1;
				if (tr[i].a == a[x-1].R)
				{
					a[x].L = tr[i].a; a[x].R = tr[i].b; a[x].f = tr[i].c;
					find(x + 1);
				}
				if (tr[i].b == a[x-1].R)
				{
					a[x].L = tr[i].b; a[x].R = tr[i].c; a[x].f = tr[i].a;
					find(x + 1);
				}
				if (tr[i].c == a[x-1].R)
				{
					a[x].L = tr[i].c; a[x].R = tr[i].a; a[x].f = tr[i].b;
					find(x + 1);
				}
				b[i] = 0;
			}
	}
}

int main()
{
int i;
char s[5];

	while (1)
	{
		for (i = 0; i < 6; i ++) scanf("%d %d %d" , &tr[i].a , &tr[i].b , &tr[i].c);
		memset(b , 0 , sizeof(b));
		max = 0; tot = 0;
		find(0);
		if (max == 0) printf("none\n");
		else printf("%d\n" , max);
		scanf("%s" , s);
		if (s[0] == '$') break;
	}
	return 0;
}