#include <stdio.h>
#include <algorithm>
using namespace std;

struct kk{char name[2]; int x , y;}a[26];

bool cmp(kk &x , kk &y)
{
	return x.name[0] < y.name[0];
}

int main()
{
int n , i , j , k , L , x , y , totx , toty , b , h , have;

	h = 0;
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		h ++; have = 0;
		for (i = 0; i < n; i ++)
			scanf("%s %d %d" , a[i].name , &a[i].x , &a[i].y);
		printf("Point set %d:" , h);
		sort(a , a + n , cmp);
		for (i = 0; i < n; i ++)
			for (j = 0; j < n; j ++)
				if (i != j)
				for (k = 0; k < n; k ++)
					if ((k != i) && (k != j))
					for (L = 0; L < n; L ++)
						if ((L != i) && (L != j) && (L != k))
						{
							if ((a[i].x < a[j].x) && (a[i].y > a[L].y) &&
								(a[i].x == a[L].x) && (a[i].y == a[j].y) &&
								(a[k].x == a[j].x) && (a[k].y == a[L].y))
							{
								if (have % 10 == 0) printf("\n");
								have ++;
								printf(" %s%s%s%s" , a[i].name , a[j].name , a[k].name , a[L].name);
							}
						}
		if (have == 0) printf(" No rectangles");
		printf("\n");
	}
	return 0;
}