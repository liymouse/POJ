#include <stdio.h>

int main()
{
int t , n , i , tot , x;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		tot = 0;
		for (i = 0; i < n; i ++)
		{
			scanf("%d" , &x);
			tot += x;
		}
		printf("%d\n" , tot - n + 1);
	}
	return 0;
}
