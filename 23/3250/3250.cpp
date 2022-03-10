#include <stdio.h>

int main()
{
int n , i , s , t , m , mm , k;
int a[80000] , b[80000];
unsigned int res;

	scanf("%d" , &n);
	for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
	m = 0; res = 0;
	b[0] = a[0];
	for (i = 1; i < n; i ++)
	{
		if (a[i] > b[0])
		{
			m = 0; b[0] = a[i];
		}
		else if (a[i] < b[m])
		{
			m ++; b[m] = a[i];
		}
		else
		{
			s = 0; t = m; k = 0;
			while (s < t)
			{
				mm = (s + t) / 2;
				if (b[mm] > a[i]) {s = mm + 1; k = 1;}
				else {t = mm; k = 0;}
			}
			m = mm + k;
			b[m] = a[i];
		}
		res += m;
	}
	printf("%u\n" , res);
	return 0;
}