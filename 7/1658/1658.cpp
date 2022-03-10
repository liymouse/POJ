#include <stdio.h>

int main()
{
int t , a , b , c , d;
	
	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d %d %d" , &a , &b , &c , &d);
		if (b + d == 2 * c) printf("%d %d %d %d %d\n" , a , b , c , d , d + d - c);
		else printf("%d %d %d %d %d\n" , a , b , c , d , d * d / c);
	}
}