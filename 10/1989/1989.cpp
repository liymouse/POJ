#include <stdio.h>
#include <string.h>

int main()
{
int a[10001] , x , n , k , tot , s , i;

	scanf("%d %d" , &n , &k);
	memset(a , 0 , sizeof(a));
	s = 0; tot = 0;
	for (i = 0; i < n; i ++)
	{
		scanf("%d" , &x);
		if (a[x] == 0) {s ++; a[x] = 1;}
		if (s == k)
		{
			tot ++; s = 0;
			memset(a , 0 , sizeof(a));
		}
	}
	printf("%d\n" , tot+1);
	return 0;
}