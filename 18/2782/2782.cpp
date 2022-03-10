#include <stdio.h>

int min(int a , int b){return a < b ? a : b;}

int main()
{
int n , L;
int a[10001] = {0};
int i , j , k , x , res;

	scanf("%d" , &n);
	scanf("%d" , &L);
	for (i = 0; i < n; i ++)
	{
		scanf("%d" , &k);
		a[k] ++;
	}
	res = a[L];
	for (i = L-1; i >= 1; i --)
		if (a[i])
		{
			x = min(L - i , i);
			for (j = x; j >= 1; j --)
				if (a[j])
				{
					if (i == j) {res += a[i] / 2; a[i] = a[i] % 2;}
					else
					{
						k = a[i] > a[j] ? a[j] : a[i];
						res += k;
						a[i] -= k; a[j] -= k;
					}
				}
		}
	for (i = 1; i < L; i ++) if (a[i]) res += a[i];
	printf("%d\n" , res);
	return 0;
}
