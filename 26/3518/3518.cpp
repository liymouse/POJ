#include <stdio.h>
#include <string.h>

char x[1300001] = {0};

int main()
{
int n , i , k;

	for (i = 2; i <= 1141; i ++)
	{
		k = i + i;
		while (k < 1300000)
		{
			x[k] = 1;
			k += i;
		}
	}
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		k = 0;
		if (x[n] == 0) printf("0\n");
		else
		{
			i = n;
			while (i > 1 && x[i] == 1) {k ++; i --;}
			i = n + 1;
			while (i < 1300000 && x[i] == 1) {k ++; i ++;}
			printf("%d\n" , k+1);
		}
	}
	return 0;
}
