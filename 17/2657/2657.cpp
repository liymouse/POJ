#include <stdio.h>
#include <string.h>

char f[1002] , b[1002];
int n , z , m;

int ans()
{
int i , j;

	for(i = 1; i < z; i ++)
	{
		memset(f , 0 , sizeof(f));
		j = 1;
		while((f[j]==0) && (b[j]==0))
		{
			f[j] = 1;
			if(j == z) return i;
			j += i; j = (j - 1) % n+1;
		}
	}
	return z-1;
}

int main ()
{
int i , t;

	while(scanf("%d %d %d" , &n , &z , &m) ==3)
	{
		memset(b , 0 , sizeof(b));
		for (i = m; i <= n; i ++) {scanf("%d" , &t); b[t] = 1;}
		printf("%d\n" , ans());
	}
	return 0;
}