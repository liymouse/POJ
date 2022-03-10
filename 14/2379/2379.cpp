#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct team
{
	int name , tot , time;
	int untime[21];
	int ac[21];
}a[1001] , y;
struct date
{
	int name , problem , time , ac;
}d[1001] , z;

bool cmp1(date &x , date &y)
{
	return x.time < y.time;
}

bool cmp2(team &x , team &y)
{
	if (x.tot != y.tot) return (x.tot > y.tot);
	if (x.time != y.time) return (x.time < y.time);
	return (x.name < y.name);
}

int main()
{
int c , n , i , j , x;

	while (scanf("%d %d" , &c , &n) == 2)
	{
		memset(a , 0 , sizeof(a));
		for (i = 1; i <= c; i ++) a[i].name = i;
		for (i = 0; i < n; i ++) scanf("%d %d %d %d" , &d[i].name , &d[i].problem , &d[i].time , &d[i].ac);
		sort(d , d + n , cmp1);
		for (i = 0; i < n; i ++)
		{
			if (a[d[i].name].ac[d[i].problem] == 0)
			{
				if (d[i].ac == 1)
				{
					a[d[i].name].tot ++; a[d[i].name].ac[d[i].problem] = 1;
					a[d[i].name].time += d[i].time + a[d[i].name].untime[d[i].problem];
				}
				else
				{
					a[d[i].name].untime[d[i].problem] += 1200;
				}
			}
		}
		sort(a + 1 , a + c + 1 , cmp2);
		for (i = 1; i < c; i ++) printf("%d " , a[i].name);
		printf("%d\n" , a[c].name);
	}
	return 0;
}
