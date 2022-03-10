#include <stdio.h>

int t3(int n)
{
	if (n == 1) return 1;
	return 2 * t3(n-1) + 1;
}

int t4(int n)
{
int i , res , min;
	
	if (n == 1) return 1;
	min = 999999999;
	for (i = 1; i < n; i ++)
	{
		res = 2 * t4(n-i) + t3(i);
		if (res < min) min = res;
	}
	return min;
}

int main()
{
int n;

	for (n = 1; n <= 12; n ++)
		printf("%d\n" , t4(n));
	return 0;
}
