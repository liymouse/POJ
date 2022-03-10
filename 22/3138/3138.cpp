#include <stdio.h>
#include <string.h>

int main()
{
int num[101] , b[101];
int s , t , m , x , y , k , h , i;

	h = 0;
	while (scanf("%d %d %d" , &s , &t , &m) == 3)
	{
		if (t == 0) break;
		h ++;
		memset(num , 0 , sizeof(num));
		memset(b , 0 , sizeof(b));
		for (i = 0; i < s; i ++)
		{
			scanf("%d %d %d" , &k , &x , &y);
			num[k] += x + y;
		}
		for (i = 0; i < t; i ++)
		{
			scanf("%d %d" , &k , &x);
			if (x >= m && b[k] == 0) {num[k] ++; b[k] = 1;}
		}
		k = 0;
		for (i = 1; i <= s; i ++) k += num[i];
		printf("Case %d: %d\n" , h , k);
	}
	return 0;
}
