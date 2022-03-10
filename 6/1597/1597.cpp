#include <stdio.h>
#include <string.h>

int main()
{
int n , m , x , tot;
char a[100000];

	while (scanf("%d %d" , &n , &m) == 2)
	{
		memset(a , 0 , sizeof(a));
		x = 0; tot = 0;
		while (1)
		{
			if (a[x] == 0) {a[x] = 1; tot ++;}
			else break;
			x = (x + n) % m;
		}
		printf("%10d%10d    " , n , m);
		if (tot < m) printf("Bad Choice\n"); else printf("Good Choice\n");
		printf("\n");
	}
	return 0;
}