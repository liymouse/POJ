#include <stdio.h>

int main()
{
int n , res , s;

	while (scanf("%d" , &n) == 1)
	{
		res = 1; s = 1;
		while (1)
		{
			if (s % n == 0) break;
			s = (s * 10 + 1) % n;
			res ++;
		}
		printf("%d\n" , res);
	}
	return 0;
}
