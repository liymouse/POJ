#include <stdio.h>

int main()
{
int fi[1001];
int a , b , c , d , e , f , g , h , i , j;
int t;

	//freopen("2696in.txt" , "r" , stdin);
	//freopen("2696out.txt" , "w" , stdout);
	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d%d%d%d%d%d%d%d%d" , &a , &b , &c , &d , &e , &f , &g , &h , &i);
		fi[0] = a; fi[1] = b; fi[2] = c;
		for (j = 3; j <= i; j ++)
			if (j % 2 == 1)
			{
				fi[j] = (d * fi[j-1] + e * fi[j-2] - f * fi[j-3]) % g;
				if (fi[j] < 0) fi[j] += g;
			}
			else
			{
				fi[j] = (f * fi[j-1] - d * fi[j-2] + e * fi[j-3]) % h;
				if (fi[j] < 0) fi[j] += h;
			}
		printf("%d\n" , fi[i]);
	}
	return 0;
} 
