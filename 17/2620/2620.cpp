#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct kk{int x , y;}a[100000];

bool cmp(kk &x , kk &y)
{
	if (x.x == y.x) return x.y < y.y;
	else return x.x < y.x;
}

int main()
{
int m , i , n , max , x , y , big , t , can , tot;
char b[100000];

	//freopen("2620in.txt" , "r" , stdin);
	//freopen("2620.txt" , "w" , stdout);
	scanf("%d" , &m);
	n = 0;
	while (scanf("%d %d" , &x , &y) == 2)
	{
		if ((x == 0) && (y == 0)) break;
		if (x < y) {a[n].x = x; a[n].y = y;}
		else {a[n].y = x; a[n].x = y;}
		n ++;
	}
	memset(b , 0 , sizeof(b));
	max = 0; tot = 0;
	sort(a , a + n , cmp);
	t = -1; big = 0;
	for (i = 0; i < n; i ++)
		if ((a[i].x <= max) && (a[i].y > big))
		{
			big = a[i].y; t = i;
		}
		else if (a[i].x > max)
		{
			if (t == -1) {can = 0; break;}
			big = 0; max = a[t].y; b[t] = 1;
			tot ++; t = -1;	i --;
			if (max >= m) {can = 1; break;}
		}
	if (max < m)
	{
		if (t == -1) can = 0;
		else {max = a[t].y; b[t] = 1; tot ++; if (max >= m) can = 1; else can = 0;}
	}
	if (can)
	{
		printf("%d\n" , tot);
		for (i = 0; i < n; i ++) if (b[i]) printf("%d %d\n" , a[i].x , a[i].y);
	}
	else printf("No solution\n");
	return 0;
}