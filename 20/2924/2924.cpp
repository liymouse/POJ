//PKU 2924
//n + (n+1) + ... + (m-1) + m;
#include <stdio.h>

int main()
{
int ca , h;
__int64 n , m , res;

	scanf("%d" , &ca);
	for (h = 1; h <= ca; h ++)
	{
		scanf("%I64d %I64d" , &n , &m);
		printf("Scenario #%d:\n" , h);
		res = (m + n) * (m - n + 1) / 2;
		printf("%I64d\n\n" , res);
	}
	return 0;
}
