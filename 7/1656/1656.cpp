#include <stdio.h>
#include <string.h>

int main()
{
char a[100][100];
char s[10]
int x , y , L;
int t , i , j , h , tot;

	scanf("%d" , &t);
	memset(a , 0 , sizeof(a));
	for (h = 0; h < t; h ++)
	{
		scanf("%s %d %d %d" , s , &x , &y , &L);
		if (s[0] == 'W')
		{
			for (i = x; i <= x + L - 1; i ++)
				for (j = y; j <= y + L - 1; j ++)
					a[i][j] = 0;
		}
		else if (s[0] == 'B')
		{
			for (i = x; i <= x + L - 1; i ++)
				for (j = y; j <= y + L - 1; j ++)
					a[i][j] = 1;
		}
		else
		{
			tot = 0;
			for (i = x; i <= x + L - 1; i ++)
				for (j = y; j <= y + L - 1; j ++)
					tot += a[i][j];
			printf("%d\n" , tot);
		}
	}
	return 0;
}