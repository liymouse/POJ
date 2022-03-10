#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct
{
	int a , b;
}ele;
ele x[10000];


int cmp(ele &x , ele &y)
{
	if (x.a == y.a) return (x.b > y.b);
	else return (x.a < y.a);
}

int main()
{
int n , i , j , s , t , tot;
int b[10000];

	scanf("%d" , &n);
	for (i = 0; i < n; i ++) scanf("%d %d" , &x[i].a , &x[i].b);
	sort(x , x + n , cmp);
	memset(b , 0 , sizeof(b));
	for (i = 0; i < n; i ++)
	{
		for (j = i + 1; j < n; j ++)
		{
			if (x[i].b >= x[j].b)
			{
				b[i] = 1; break;
			}
			if (x[i].b <= x[j].a) break;
		}
	}
	tot = 2;
	for (i = 0; i < n; i ++) if (b[i] == 0) {s = x[i].b-1; t = x[i].b; break;}
	i ++;
	while (i < n)
	{
		while (i < n)
		{
			if ((b[i] == 0) && (s < x[i].a)) break;
			i ++;
		}
		if (i == n) break;
		if (t < x[i].a)
		{
			s = x[i].b-1; t = x[i].b;
			tot += 2;
		}
		else
		{
			s = t; t = x[i].b;
			tot ++;
		}
		i ++;
	}
	printf("%d\n" , tot);
	return 0;
}