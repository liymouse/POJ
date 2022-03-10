#include <stdio.h>

int main()
{
int a[2001] = {0};
int n , k;
int i , t , tot , x;

	scanf("%d" , &n);
	t = 2; tot = 0; k = 0;
	while (k < n) {k += t; a[t] = 1; tot ++; t ++;}
	if (k - n > 0)
	{
	    t -= 2; tot --;
        k = k - t - 1;
        x = n - k;
        if ((1 <= x) && (x <= t - 1)) {a[t+1-x] = 0;}
        else if (x == t) {a[2] = 0; a[t + 2] = 1; a[t + 1] = 0;}
	}
	for (i = 1; i <= k; i ++)
		if (a[i] == 1)
		{
			tot --;
			if (tot > 0) printf("%d " , i); else printf("%d\n" , i);
		}
	getchar(); getchar();
	return 0;
}
