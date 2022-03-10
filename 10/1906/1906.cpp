#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pow(int *a , int x)
{
int k , i , j;

	k = 1;
	a[0] = 1;
	for (i = 1; i <= x; i ++)
	{
		for (j = 0; j < k; j ++)
			a[j] *= 3;
		for (j = 0; j < k; j ++)
			if (a[j] > 9)
			{
				a[j + 1] += a[j] / 10;
				a[j] %= 10;
			}
		if (a[k] > 0) k ++;
	}
	return k;
}

int change(char *n , char *jz2)
{
int a[30];
int i , j , L , k;


	L = strlen(n); k = 0;
	for (i = 0; i < L; i ++) a[i] = n[L - i - 1] - '0';
	while (L > 0)
	{
		jz2[k ++] = a[0] & 1;
		for (i = L-1; i > 0; i --)
		{
			a[i-1] += (a[i] & 1) * 10;
			a[i] /= 2;
		}
		a[0] /= 2;
		if (a[L-1] == 0) L --;
	}
	jz2[0] --;
	i = 0;
	while (jz2[i] < 0) {jz2[i] = 1; jz2[i + 1] --; i ++;}
	if (jz2[k-1] == 0) k --;
	return k;
}

int main()
{
char n[30];
int i , k , j , t , f;
char jz2[70];
int a[100];

	while (scanf("%s" , n) == 1)
	{
		if (n[0] == '0') break;
		k = change(n , jz2);
		printf("{ ");
		f = 0;
		for (i = 0; i < k; i ++)
			if (jz2[i])
			{
				if (f) printf(", ");
				else f = 1;
				memset(a , 0 , sizeof(a));
				t = pow(a , i);
				for (j = t - 1; j >= 0; j --) printf("%d" , a[j]);
				
			}
		printf(" }\n");
	}
	return 0;
}
