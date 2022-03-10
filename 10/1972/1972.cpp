#include <stdio.h>

int main()
{
int ca , n , i , j , max , s , x , y , t , res;
int a[10010][6];
int dui[6] = {5 , 3 , 4 , 1 , 2 , 0};

	scanf("%d" , &ca);
	while (ca --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++)
			for (j = 0; j < 6; j ++) scanf("%d" , &a[i][j]);
		res = 0;
		for (i = 0; i < 6; i ++)
		{
			x = i; y = dui[x]; max = 0;
			for (j = 0; j < 6; j ++)
				if (j != x && j != y && a[0][j] > max) max = a[0][j];
			s = max;
			for (t = 1; t < n; t ++)
			{
				for (j = 0; j < 6; j ++) if (a[t][j] == a[t-1][y]) {x = j; break;}
				y = dui[x]; max = 0;
				for (j = 0; j < 6; j ++)
					if (j != x && j != y && a[t][j] > max) max = a[t][j];
				s += max;
			}
			if (s > res) res = s;
		}
		printf("%d\n" , res);
	}
	return 0;
}
