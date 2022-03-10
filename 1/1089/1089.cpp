#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct
{
	int a , b;
}no;
no a[50010] , b[50010];
int num , n;

int cmp(no &a , no &b)
{
	return a.a < b.a;
}

int main()
{
int i , x , y;

	scanf("%d" , &n);
	for (i = 0; i < n; i ++)
		scanf("%d %d" , &a[i].a , &a[i].b);
	sort(a , a + n , cmp);
	num = 0;
	x = a[0].a; y = a[0].b;
	for (i = 0; i < n; i ++)
	{
		if (a[i].a > y)
		{
			b[num].a = x; b[num].b = y; num ++;
			x = a[i].a; y = a[i].b;
		}
		else if (a[i].b > y) y = a[i].b;
	}
	b[num].a = x; b[num].b = y; num ++;
	for (i = 0; i < num; i ++)
		printf("%d %d\n" , b[i].a , b[i].b);
	return 0;
}
