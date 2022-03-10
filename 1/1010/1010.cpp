#include <stdio.h>
#include <string.h>
int n , kind , max , tie , ok;
int num[100] , b[100];
int a[100];

void find(int x , int s , int m , int k)
{
int i;

	if (x == 0)
	{
		if (ok == 0)
		{
			ok = 1;
			kind = k;
			for (i = 0; i < n; i ++) num[i] = b[i];
			for (i = n-1; i >= 0; i --) if (b[i] > 0) break;
			max = a[i];
		}
		else
		{
			for (i = n-1; i >= 0; i --) if (b[i] > 0) break;
			if (k > kind || (k == kind && a[i] > max))
			{
				tie = 0;
				kind = k; max = a[i];
				for (i = 0; i < n; i ++) num[i] = b[i];
			}
			else if (k == kind && a[i] == max)
				tie = 1;
		}
		return;
	}
	if (s == n) return;
	if (m == 4) return;
	//if ((4 - m) * a[n-1] < x) return;
	for (i = 0; i <= 4 - m; i ++)
		if (x - a[s] * i >= 0)
		{
			b[s] += i;
			if (i > 0) k ++;
			find(x - a[s] * i , s + 1 , m + i , k);
			if (i > 0) k --;
			b[s] -= i;
		}
}

int main()
{
int i , j , x;

	while (scanf("%d" , &x) == 1)
	{
		n = 0;
		a[n ++] = x;
		while (scanf("%d" , &x) == 1)
		{
			if (x == 0) break;
			a[n ++] = x;
		}
		for (i = 0; i < n; i ++)
			for (j = 1; j < n - i; j ++)
				if (a[j-1] > a[j]) {x = a[j-1]; a[j-1] = a[j]; a[j] = x;}
		while (scanf("%d" , &x) == 1)
		{
			if (x == 0) break;
			memset(b , 0 , sizeof(b));
			ok = 0; tie = 0; max = 0; kind = 0;
			find(x , 0 , 0 , 0);
			printf("%d " , x);
			if (!ok) printf("---- none");
			else
			{
				printf("(%d): " , kind);
				if (tie) printf("tie");
				else
				{
					for (i = 0; i < n; i ++)
						while (num[i]) {printf("%d " , a[i]); num[i] --;}
				}
			}
			printf("\n");
		}
	}
}
