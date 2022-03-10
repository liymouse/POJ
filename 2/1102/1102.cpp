#include <stdio.h>
#include <string.h>

char a[23][105];
int n;

void draw(int x , int k)
{
int i;

/*    1
     ---
   2|   | 3
    | 4 |
     ---
   5|   | 6
    | 7 |
     ---
*/
	switch (k)
	{
		case 1 : for (i = 1; i <= n; i ++) a[0][x + i] = '-';
			break;
		case 2 : for (i = 1; i <= n; i ++) a[i][x] = '|';
			break;
		case 3 : for (i = 1; i <= n; i ++) a[i][x + n + 1] = '|';
			break;
		case 4 : for (i = 1; i <= n; i ++) a[n + 1][x + i] = '-';
			break;
		case 5 : for (i = n + 2; i <= 2 * n + 1; i ++) a[i][x] = '|';
			break;
		case 6 : for (i = n + 2; i <= 2 * n + 1; i ++) a[i][x + n + 1] = '|';
			break;
		case 7 : for (i = 1; i <= n; i ++) a[2 * n + 2][x + i] = '-';
			break;
	}
}

int main()
{
int L , i , j , k , Ls , tot;
char s[10];

	while (scanf("%d %s" , &n , s) == 2)
	{
		if (n == 0) break;
		k = 0; L = n + 3; Ls = strlen(s);
		memset(a , 0 , sizeof(a));
		for (i = 0; i < Ls; i ++)
		{
			switch (s[i])
			{
				case '0' : draw(k , 1); draw(k , 2); draw(k , 3); draw(k , 5); draw(k , 6); draw(k , 7);
					break;
				case '1' : draw(k , 3); draw(k , 6);
					break;
				case '2' : draw(k , 1); draw(k , 3); draw(k , 4); draw(k , 5); draw(k , 7);
					break;
				case '3' : draw(k , 1); draw(k , 3); draw(k , 4); draw(k , 6); draw(k , 7);
					break;
				case '4' : draw(k , 2); draw(k , 3); draw(k , 4); draw(k , 6);
					break;
				case '5' : draw(k , 1); draw(k , 2); draw(k , 4); draw(k , 6); draw(k , 7);
					break;
				case '6' : draw(k , 1); draw(k , 2); draw(k , 4); draw(k , 5); draw(k , 6); draw(k , 7);
					break;
				case '7' : draw(k , 1); draw(k , 3); draw(k , 6);
					break;
				case '8' : draw(k , 1); draw(k , 2); draw(k , 3); draw(k , 4); draw(k , 5); draw(k , 6); draw(k , 7);
					break;
				case '9' : draw(k , 1); draw(k , 2); draw(k , 3); draw(k , 4); draw(k , 6); draw(k , 7);
					break;
			}
			k += L;
		}
		tot = (n + 2) * Ls + Ls - 1;
		for (i = 0; i < 2 * n + 2; i ++)
		{
			if (a[i][tot-1] == 0)
			{
				k = tot - 1;
				while ((k >= 0) && (a[i][k] == 0)) {a[i][k] = 1; k --;}
				a[i][k+1] = 0;
			}
		}
		for (i = 0; i <= 2 * n + 2; i ++)
		{
			for (j = 0; j < tot; j ++)
				if (a[i][j] == 1) continue;
				else if (a[i][j] == 0) printf(" ");
					else printf("%c" , a[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}