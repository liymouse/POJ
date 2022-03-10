#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(const int &x , const int &y)
{
	return x < y;
}

int main()
{
int t , n;
int a[1000];
int i;
int tot , x , k1 , k2;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
		sort(a , a + n , cmp);
		if (n == 1) tot = a[0];
		else if (n == 2) tot = a[1];
		else
		{
			tot = 0;
			for (i = n - 1; i > 2; i -= 2)
			{
				k1 = a[1] + a[0] + a[i] + a[1];
				k2 = a[i] + a[0] + a[i-1] + a[0];
				if (k1 < k2) tot += k1; else tot += k2;
			}
			if (i == 1) tot += a[1];
			else tot += a[0] + a[1] + a[2];
		}
		printf("%d\n" , tot);
	}
	return 0;
}