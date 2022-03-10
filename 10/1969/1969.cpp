#include <stdio.h>

int main()
{
int n , k , s;

	while (scanf("%d" , &n) == 1)
	{
		k = 1; s = 0;
		while (s < n) {s += k; k ++;}
		k --; s -= k;
		printf("TERM %d IS " , n);
		n -= s;
		if (k % 2 == 1) printf("%d/%d\n" , k + 1 - n , n);
		else printf("%d/%d\n" , n , k + 1 - n);
	}
	return 0;
}