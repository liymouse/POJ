#include <stdio.h>

int d(int x)
{
int tot = x;

	while (x > 0) {tot += x % 10; x /= 10;}
	return tot;
}

int main()
{
int a[10001] = {0};
int i , k;

	for (i = 1; i <= 10000; i ++)
	{
		if (a[i] == 0)
		{
			k = d(i);
			while (k <= 10000)
			{
				a[k] = 1;
				k = d(k);
			}
		}
	}
	for (i = 1; i <= 10000; i ++)
		if (a[i] == 0) printf("%d\n" , i);
	return 0;
}