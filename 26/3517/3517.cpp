#include <stdio.h>

int main()
{
int n , m , k , i , s;

	while (scanf("%d %d %d" , &n , &k , &m) == 3)
	{
		if (n == 0) break;
		s = 0;
		for (i = 2; i <= n; i ++) s = (s + k) % i;
		s = (s + m - k) % n;
		while (s < 0) s += n;
		printf("%d\n" , s + 1);
	}
	return 0;
}
