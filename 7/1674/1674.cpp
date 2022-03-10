#include <stdio.h>

int main()
{
int a[10001] , b[10001];
int n , i , t , x , tot;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 1; i <= n; i ++) {scanf("%d" , &a[i]); b[a[i]] = i;}
		tot = 0;
		for (i = 1; i <= n; i ++)
			if (a[i] != i)
			{
				tot ++;
				b[a[i]] = b[i];
				x = a[b[i]]; a[b[i]] = a[i]; a[i] = x;
			}
		printf("%d\n" , tot);
	}
	return 0;
}