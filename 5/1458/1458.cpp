#include <stdio.h>
#include <string.h>
#define MAX 350

int f[MAX][MAX];

int main()
{
char a[MAX] , b[MAX];
int i , j , La , Lb;

	while (scanf("%s %s" , a , b) == 2)
	{
		La = strlen(a); Lb = strlen(b);
		memset(f , 0 , sizeof(f));
		for (i = 1; i <= La; i ++)
			for (j = 1; j <= Lb; j ++)
			{
				if (a[i-1] == b[j-1]) f[i][j] = f[i-1][j-1] + 1;
				else if (f[i-1][j] > f[i][j-1]) f[i][j] = f[i-1][j]; 
					else f[i][j] = f[i][j-1];
			}
		printf("%d\n" , f[La][Lb]);
	}
	return 0;
}