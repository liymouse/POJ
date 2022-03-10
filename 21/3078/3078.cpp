#include <stdio.h>
#include <string.h>

int main()
{
int m , n , i , j , x , y , t;
int a[21] , b[21];
char name[21][10];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &m , &n);
		for (i = 1; i <= m; i ++) scanf("%s" , name[i]);
		memset(a , 0 , sizeof(a));
		memset(b , 0 , sizeof(b));
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d" , &x , &y);
			a[y] = x; b[x] = 1;
		}
		for (i = 1; i <= m; i ++)
			if (a[i] == 0)
				for (j = 1; j <= m; j ++)
					if (b[j] == 0) {a[i] = j; b[j] = 1; break;}
		for (i = 1; i < m; i ++)
			printf("%s " , name[a[i]]);
		printf("%s\n" , name[a[m]]);
	}
	return 0;
}