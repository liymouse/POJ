#include <stdio.h>

int kk[17][7];

int change(int x , int k)
{
int i , re;

	re = 0; i = 0;
	while (x > 0) {re += (x % 10) * kk[k][i]; x /= 10; i ++;}
	return re;
}

int main()
{
int i , j , p , q , r , x , t;

	for (i = 2; i <= 16; i ++)
	{
		x = 1;
		for (j = 0; j < 7; j ++)
		{
			kk[i][j] = x;
			x *= i;
		}
	}
	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d %d" , &p , &q , &r);
		x = 0;
		j = p; while (j > 0) {if (j % 10 > x) x = j % 10; j /= 10;}
		j = q; while (j > 0) {if (j % 10 > x) x = j % 10; j /= 10;}
		j = r; while (j > 0) {if (j % 10 > x) x = j % 10; j /= 10;}
		j = 0;
		for (i = x + 1; i <= 16; i ++)
			if (change(p , i) * change(q , i) == change(r , i)) 
				{printf("%d\n" , i); j = 1; break;}
		if (j == 0) printf("0\n");
	}
	return 0;
}