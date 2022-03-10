#include <stdio.h>
#include <string.h>

int a[100][100][100];

int main()
{
int t , n , x , y , z , i , j , k , tot , tmp;

	//freopen("1507.in", "r" , stdin);
	//freopen("1507.txt" , "w" , stdout);
	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++)
			for (j = 0; j < n; j ++)
				for (k = 0; k < n; k ++)
				{
					scanf("%d" , &a[i][j][k]);
					if (a[i][j][k] == 0) {z = i; y = j; x = k;}
				}
		while (x < n-1) {a[z][y][x] = a[z][y][x + 1]; x ++;}
		while (y < n-1) {a[z][y][x] = a[z][y + 1][x]; y ++;}
		while (z < n-1) {a[z][y][x] = a[z + 1][y][x]; z ++;}
		tot = 0;
		for (i = n-1; i >= 0; i --)
			for (j = n-1; j >= 0; j --)
				for (k = n-1; k >= 0; k --)
					if ((i != n-1) || (j != n-1) || (k != n-1))
					{
						while (a[i][j][k] != i * n * n + j * n + k + 1)
						{
							tmp = a[i][j][k] - 1;
							x = tmp % n; tmp /= n;
							y = tmp % n; tmp /= n;
							z = tmp;
							tmp = a[i][j][k];
							a[i][j][k] = a[z][y][x];
							a[z][y][x] = tmp;
							tot ++;
						}
					}
		if (tot % 2 == 0) printf("Puzzle can be solved.\n");
		else printf("Puzzle is unsolvable.\n");
	}
	return 0;
}

