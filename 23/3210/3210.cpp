#include <stdio.h>

int main()
{
int n;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		if (n & 1) printf("%d\n" , n - 1);
		else printf("No Solution!\n");
	}
	return 0;
}
