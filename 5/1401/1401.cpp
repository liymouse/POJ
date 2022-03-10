#include <stdio.h>

int main()
{
int p[13] = {1 , 5 , 25 , 125 , 625 , 3125 , 15625 , 78125 , 390625 , 1953125 , 9765625 , 48828125 , 244140625};
int n , i , t , tot;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		tot = 0;
		for (i = 12; i > 0; i --) tot += n / p[i];
		printf("%d\n" , tot);
	}
	return 0;
}