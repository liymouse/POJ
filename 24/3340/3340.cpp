#include <stdio.h>
#include <string.h>

int deal(char x[] , char y[])
{
int i , L , j , k;
char xx[11] , yy[11];
int res;

	L = strlen(x);
	if (L == 0) return 0;
	i = 0;
	while (x[i] == y[i]) i ++;
	if (i == L) return 0;
	if (x[i] == '?')
	{
		k = 0;
		for (j = i+1; j < L; j ++) if (x[j] == '?') k ++;
		res = '9' - y[i];
		for (j = 0; j < k; j ++) res *= 10;
		for (j = i + 1; j < L; j ++) {xx[j-i-1] = x[j]; yy[j-i-1] = y[j];}
		xx[j-i-1] = 0; yy[j-i-1] = 0;
		return res + deal(xx , yy);
	}
	else
	{
		if (x[i] > y[i])
		{
			k = 0;
			for (j = i; j < L; j ++) if (x[j] == '?') k ++;
			res = 1;
			for (j = 0; j < k; j ++) res *= 10;
			return res;
		}
		else return 0;
	}
}

int main()
{
char x[11] , y[11];

	while (scanf("%s" , x) == 1)
	{
		if (x[0] == '#') break;
		scanf("%s" , y);
		printf("%d\n" , deal(x , y));
	}
	return 0;
}
