#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
	int a , b;
}Course;

int cmp(Course a , Course b)
{
	if (a.b == b.b) return a.a < b.a;
	return a.b < b.b;
}

int main()
{
	int n;
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		Course a[301];
		for (int i = 0; i < n; i ++) scanf("%d %d" , &a[i].a , &a[i].b);
		sort(a , a + n , cmp);
		int res = 0;
		for (int i = 0; i < 5; i ++)
		{
			int choose[301] = {0};
			int num = 0;
			for (int j = i; j < 1005; j += 5)
			{
				for (int k = 0; k < n; k ++)
					if (choose[k] == 0 && a[k].a <= j && j < a[k].b)
					{
						num ++;
						choose[k] = 1;
						break;
					}
			}
			res = max(res , num);
		}
		printf("%d\n" , res);
	}
	return 0;
}