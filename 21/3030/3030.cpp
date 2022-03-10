#include <stdio.h>

int main()
{
int r , e , c , n;

	scanf("%d" , &n);
	while (n --)
	{
		scanf("%d %d %d" , &r , &e , &c);
		if (r < e - c) printf("advertise\n");
		else if (r == e - c) printf("does not matter\n");
		else printf("do not advertise\n");
	}
	return 0;
}