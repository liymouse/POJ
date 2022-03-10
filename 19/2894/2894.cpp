#include <stdio.h>
#include <string.h>

int main()
{
int a[1002];
char c[3];
int x , y , i , j , w , n;

	scanf("%d" , &w);
	while (w --)
	{
		memset(a , 0 , sizeof(a));
		scanf("%d" , &n);
		for (i = 0; i < n; i ++)
		{
			scanf("%s %d %d" , c , &x , &y);
			for (j = x; j < y; j ++) a[j] ++;
		}
		for (i = 0; i < 1000; i ++) if (a[i]) printf("%c" , (char)(a[i] + 'A' - 1));
		printf("\n");
	}
	return 0;
}
