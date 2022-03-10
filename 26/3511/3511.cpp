#include <stdio.h>

char a[1000000] = {0};
int pri[1000000];
int cpri[1000000];

int main()
{
int i , k;
int L , U , s , t;

	a[0] = 1; a[1] = 1;
	for (i = 2; i <= 1000; i ++)
		if (a[i] == 0)
		{
			k = i + i;
			while (k < 1000000)
			{
				a[k] = 1;
				k += i;
			}
		}
	pri[0] = 0; cpri[0] = 0;
	for (i = 1; i < 1000000; i ++)
	{
		pri[i] = pri[i-1];
		cpri[i] = cpri[i-1];
		if (a[i] == 0)
		{
			pri[i] ++;
			if ((i & 3) == 1) cpri[i] ++;
			else if (i == 2) cpri[i] ++;
		}
	}
	while (scanf("%d %d" , &L , &U) == 2)
	{
		if (L == -1 && U == -1) break;
		s = L < 1 ? 1 : L; t = U < 1 ? 1 : U;
		printf("%d %d %d %d\n" , L , U , pri[t]-pri[s-1] , cpri[t] - cpri[s-1]);
	}
	return 0;
}