#include <stdio.h>

int main()
{
int n , x , y , k , tot , i;

	scanf("%d" , &n);
	tot = 0; k = 0;
	scanf("%d" , &x);
	for (i = 1; i < n; i ++)
	{
		scanf("%d" , &y);
		if ((k == 0) && (x > y)) {tot += x; k = 1;}
		else if ((k == 1) && (x < y)) {tot -= x; k = 0;}
		x = y;
	}
	if (k == 0) tot += x;
	printf("%d" , tot);
	return 0;
}