#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct agency
{
	char name[20];
	int a , b , tot;
}a[100];

bool cmp(agency &x , agency &y)
{
	if (x.tot != y.tot)	return x.tot < y.tot;
	return strcmp(x.name , y.name) < 0;
}

int main()
{
int n , m , L , x , y , t , h;
int i , j;
char s[100];

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%d %d %d" , &n , &m , &L);
		memset(a , 0 , sizeof(a));
		for (i = 0; i < L; i ++)
		{
			scanf("%s" , s);
			j = 0;
			while ((s[j] >= 'A') && (s[j] <= 'Z')) {a[i].name[j] = s[j]; j ++;}
			a[i].name[j] = 0;
			j ++;
			while ((s[j] >= '0') && (s[j] <= '9')) {a[i].a = a[i].a * 10 + s[j] - '0'; j ++;}
			j ++;
			while ((s[j] >= '0') && (s[j] <= '9')) {a[i].b = a[i].b * 10 + s[j] - '0'; j ++;}
			x = n; y = m;
			while (x / 2 >= y)
			{
				if ((x - (x / 2)) * a[i].a < a[i].b)
				{
					a[i].tot += (x - y) * a[i].a;
					x = y;
					break;
				}
				else
				{
					a[i].tot += a[i].b;
					x = x / 2;
				}
			}
			if (x > y) a[i].tot += (x - y) * a[i].a;
		}
		sort(a , a + L , cmp);
		printf("Case %d\n" , h);
		for (i = 0; i < L; i ++)
			printf("%s %d\n" , a[i].name , a[i].tot);
	}
	return 0;
}
