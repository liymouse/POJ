#include <stdio.h>

int main()
{
int r , m , n , i;
double tot;

	scanf("%d %d %d" , &r , &m , &n);
	tot = 1;
	for (i = 0; i < n; i ++) tot *= 1 + r * 1.0 / 100;
	tot *= m;
	printf("%d\n" , (int)tot);
	return 0;
}