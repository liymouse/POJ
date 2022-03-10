#include <stdio.h>

int main()
{
char s[20];
int a[10][10] , b[9][9] , r , c;
int i , j;
	
	while (scanf("%s" , s) == 1)
	{
		if (s[0] == 'E') return 0;
		scanf("%d %d\n" , &r , &c);
		for (i = 0; i < r; i ++)
		{
			gets(s);
			for (j = 0; j < c; j ++) a[i][j] = s[j] - '0';
		}
		gets(s);
		for (i = 0; i < r - 1; i ++)
		{
			for (j = 0; j < c - 1; j ++)
			{
				b[i][j] = (a[i][j] + a[i][j+1] + a[i+1][j] + a[i+1][j+1]) / 4;
				printf("%d" , b[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
