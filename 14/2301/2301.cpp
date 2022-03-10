#include <stdio.h>

int main()
{
int t , x , y;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &x , &y);
		if (((x-y) % 2 == 0) && (x >= y)) printf("%d %d\n" , (x+y)/2 , (x-y)/2);
		else printf("impossible\n");
	}
	return 0;
}