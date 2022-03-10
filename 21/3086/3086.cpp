#include <stdio.h>

int main()
{
int ca , c , n , res , i;

	scanf("%d" , &ca);
	for (c = 1; c <= ca; c ++)
	{
		scanf("%d" , &n);
		res = 0;
		for (i = 1; i <= n; i ++) res += i * (2+i) * (i+1)/2;
		printf("%d %d %d\n" , c , n , res);
	}
	return 0;
}
