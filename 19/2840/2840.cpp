#include <stdio.h>

int main()
{
int n , h , m;

	scanf("%d" , &n);
	while (n --)
	{
		scanf("%d:%d" , &h , &m);
		if (m != 0) printf("0\n");
		else if (h <= 12) printf("%d\n" , h + 12);
			else printf("%d\n" , h - 12);
	}
	return 0;
}