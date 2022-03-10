#include <stdio.h>
#include <string.h>

int main()
{
int n , m , i , j , t , k , x , p;
int b[10000]; //a[100];

	while (scanf("%d %d" , &n , &m) == 2)
	{
		memset(b , 0 , sizeof(b));
		for (i = 0; i < n; i ++) {scanf("%d" , &x); b[x] = 1;}
		p = 1;
		for (i = 0; i < m; i ++)
		{
			scanf("%d %d" , &t , &k);
			for (j = 0; j < t; j ++) {scanf("%d" , &x); if (b[x] == 1) k --;}
			if (k > 0) p = 0;
		}
		if (p) printf("yes\n"); else printf("no\n");
	}
	return 0;
}