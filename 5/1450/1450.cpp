#include <stdio.h>

int main()
{
int t , h;
int n , m;

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%d %d" , &m , &n);
		printf("Scenario #%d:\n" , h);
		if (m * n % 2 == 0) printf("%d.00\n" , m * n);
		else printf("%d.41\n" , m * n);
		printf("\n");
	}
	return 0;
}
