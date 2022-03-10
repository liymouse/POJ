#include <stdio.h>
#include <string.h>

int main()
{
int a[33][33];
int t , x , y , L , h;
int i , j;
char s[500];

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%d %d" , &x , &y);
		scanf("%s" , s);
		memset(a , 0 , sizeof(a));
		L = strlen(s);
		for (i = 0; i < L; i ++)
		{
			if (s[i] == '.') break;
			switch(s[i])
			{
				case 'E' : x ++; a[x][y] = 1; break;
				case 'S' : y --; a[x][y+1] = 1; break;
				case 'N' : y ++; a[x+1][y] = 1; break;
				case 'W' : x --; a[x+1][y+1] = 1; break;
			}
		}
		printf("Bitmap #%d\n" , h);
		for (j = 32; j > 0; j --)
		{
			for (i = 1; i <= 32; i ++)
				if (a[i][j] == 0) printf("."); else printf("X");
			printf("\n");
		}
		printf("\n");
	}
}