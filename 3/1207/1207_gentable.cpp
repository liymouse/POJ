#include <stdio.h>

int main()
{
int n , x , tot;

	freopen("1207.txt" , "w" , stdout);
	for (n = 1; n <= 10000; n ++)
	{
		x = n; tot = 1;
		while (x != 1)
		{
			if (x % 2 == 1) x = 3 * x + 1;
			else x = x / 2;
			tot ++;
		}
		printf("%d," , tot);
		if (n % 30 == 0) printf("\n");
	}
	return 0;
}