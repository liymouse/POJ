#include <stdio.h>
#define MAX 500

int father[MAX] , no[MAX][10] , tot , n;

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

int Num(int a[])
{
int i , j , t , bb;

	t = -1;
	for (i = 0; i < tot; i ++)
	{
		bb = 0;
		for (j = 0; j < n; j ++) if (no[i][j] != a[j]) {bb = 1; break;}
		if (bb == 0) {t = i; break;}
	}
	if (t == -1)
	{
		for (i = 0; i < n; i ++) no[tot][i] = a[i];
		tot ++;
		return tot - 1;
	}
	else return t;
}

int main()
{
int s , t , a[10] , b[10];
int numa , numb;
int i , x , h;

	h = 0;
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		tot = 0;
		for (i = 0; i < MAX; i ++) father[i] = i;
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		for (i = 0; i < n; i ++) scanf("%d" , &b[i]);
		s = Num(a); t = Num(b);
		while (scanf("%d" , &x) == 1)
		{
			if (x == -1) break;
			a[0] = x;
			for (i = 1; i < n; i ++) scanf("%d" , &a[i]);
			for (i = 0; i < n; i ++) scanf("%d" , &b[i]);
			numa = Num(a); numb = Num(b);
			father[getfather(numb)] = getfather(numa);
		}
		h ++;
		printf("Maze #%d " , h);
		if (getfather(s) != getfather(t)) printf("cannot be travelled\n");
		else printf("can be travelled\n");
	}
	return 0;
}