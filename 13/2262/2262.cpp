#include <stdio.h>

char a[1000001] = {0};

void prime()
{
int i , k;

	a[0] = 1; a[1] = 1;
	for (i = 2; i <= 1000; i ++)
	{
		k = i * i;
		while (k <= 1000000) {a[k] = 1; k += i;}
	}
}

int main()
{
int n , i , b;

	prime();
	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) return 0;
		for (i = 3; i <= n / 2; i ++) if ((a[i] == 0) && (a[n-i] == 0)) {b = 1; break;}
		if (b == 1) printf("%d = %d + %d\n" , n , i , n - i);
		else printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}