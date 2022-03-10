#include <stdio.h>

int num(int n , int x)
{
int i , tot;

	tot = 0;
	if ((x == 1) || (x == n)) return 1;
	if (x > n) return 0;
	for (i = 1; i <= x; i ++)
		tot += num(n - x , i);
	return tot;
}

int main()
{
int t , m , n , i , tot;

	scanf("%d" , &t);
	while (t --)
	{
		tot = 0;
		scanf("%d %d" , &m , &n);
		for (i = 1; i <= n; i ++)
			tot += num(m , i);
		printf("%d\n" , tot);
	}
	return 0;
}
