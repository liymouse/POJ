#include <stdio.h>

int main()
{
int n , k , i;
int a , tot = 0;

	scanf("%d" , &n);
	scanf("%d" , &k);
	for (i = 0; i < n; i ++) 
	{
		scanf("%d" , &a);
		if ((k == 1) && (a > 0)) tot += a;
		else if (k == 2) tot += a * a;
		else if ((k == 3) && (a > 0)) tot += a * a * a;
	}
	printf("%d\n" , tot);
	return 0;
}