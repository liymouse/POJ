#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

bool cmp(double &x , double &y)
{
	return x < y;
}

int main()
{
double a[20] , s;
int i , j , n , t;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++) scanf("%lf" , &a[i]);
		sort(a , a + n , cmp);
		t = 0; s = 0;
		for (i = 0; i < n; i ++)
		{
			s += a[i];
			for (j = i + 1; j < n; j ++)
				if (a[j] <= s) {t = 1; break;}
				else break;
			if (t) break;
		}
		if (t) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}