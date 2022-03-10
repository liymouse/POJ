#include <stdio.h>
#include <string.h>

int main()
{
int a[26][26];
char s[30];
int b[6];
int n , x , y , i , j , tot;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		memset(a , 0 , sizeof(a));
		for (i = 0; i < n; i ++)
		{
			scanf("%s" , s);
			x = s[0] - 'A';
			for (j = 2; j < strlen(s); j ++)
			{
				y = s[j] - 'A';
				a[x][y] = 1;
			}
		}
		tot = 0;
		for (i = 0; i < n; i ++)
		{
			memset(b , 0 , sizeof(b));
			for (j = 0; j < n; j ++) b[a[i][j]] = 1;
			x = 0;
			for (j = 2; j <= 5; j ++) if (b[j] == 0) {x = j; break;}
			if (x == 0) {tot = 4; break;}
			for (j = 0; j < n; j ++) if (a[j][i] > 0) a[j][i] = x;
		}
		if (tot != 4)
		{
			memset(b , 0 , sizeof(b));
			for (i = 0; i < n; i ++) for (j = 0; j < n; j ++) b[a[i][j]] = 1;
			for (i = 2; i <= 5; i ++) tot += b[i];
		}
		if (tot == 0) printf("1 channel needed.\n");
		else printf("%d channels needed.\n" , tot);
	}
	return 0;
}
