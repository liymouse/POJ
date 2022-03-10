//PKU 3002
//n 个数的最小公倍数
#include <stdio.h>

int gcd(int a , int b)
{
int t;

    if (a == 0) return b;
    if (b == 0) return a;
    while (1)
    {
        if (a % b == 0) return b;
        t = b; b = a % b; a = t;
    }
}

int main()
{
int c;
int n , p[5];
int i;
__int64 res;
double x;

	scanf("%d" , &c);
	while (c --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++) scanf("%d" , &p[i]);
		res = p[0];
		for (i = 1; i < n; i ++)
		{
			x = (res / gcd(res , p[i])) * p[i];
			if (x <= 1000000000) res = __int64(x);
			else {res = -1; break;}
		}
		if (res > 0) printf("%d\n" , res);
		else printf("More than a billion.\n");
	}
	return 0;
}