#include <stdio.h>

int a[2000000] , b[2000000];
int main()
{
	int ca;
	scanf("%d" , &ca);
	for (int cas = 1; cas <= ca; cas ++)
	{
		int n , k;
		scanf("%d %d" , &n , &k);
		int i = 0 , j = 0;
		a[0] = b[0] = 1;
		while (a[i] < n)
		{
			i ++;
			a[i] = b[i-1] + 1;
			while (a[j+1] * k < a[i]) j ++;
			if (a[j] * k < a[i]) b[i] = a[i] + b[j];
			else b[i] = a[i];
		}
		if (a[i] == n) printf("Case %d: lose\n" , cas);
		else
		{
			while (n) {if (n >= a[i]) n -= a[i]; i --;}
			printf("Case %d: %d\n" , cas , a[i+1]);
		}
	}
	return 0;
}