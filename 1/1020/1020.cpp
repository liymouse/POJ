#include <stdio.h>
#include <string.h>

int c[11] , d[41] , s , n , sum;
bool ok;
void dfs(int a)
{
	int i , j , put , p;
	bool f;
	if (a == n) ok = true;
	if (ok) return;
	put = 100;
	for(i = 1; i <= s; i ++)
		if (d[i] < put) { put = d[i]; p = i; }
	for(i = 10; i >= 1; i --)
		if (c[i] > 0 && put + i - 1 <= s && p + i - 1 <= s)
		{
			f = true;
			for (j = p; j <= p + i - 1; j ++)
				if (d[j] > put) { f = false; break;}
			if (f)
			{
				for (j = p; j <= p + i - 1; j ++) d[j] += i;
				c[i] --;
				dfs(a + 1);
				if (ok) return;
				c[i] ++;
				for (j = p; j <= p + i - 1; j ++) d[j] -= i;
			}
		}
}

int main()
{
	int t , it , i , tp;
	scanf("%d" , &t);
	for (it = 0;it < t; it ++)
	{
		scanf("%d %d" , &s , &n);
		memset(c , 0 , sizeof(c));
		for (i = 1; i <= 40; i ++) d[i] = 1;
		sum = 0;
		for (i = 1; i <= n; i ++)
		{
			scanf("%d" , &tp);
			c[tp] ++;
			sum += tp * tp;
		}
		ok = false;
		if (sum == s * s) dfs(0);
		if (ok) printf("KHOOOOB!\n");
		else printf("HUTUTU!\n");
	}
	return 0;
}
