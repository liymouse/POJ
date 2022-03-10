#include <stdio.h>

int main()
{
int s , i , sum;

	scanf("%d" , &s);
	i = 0; sum = 0;
	while (1)
	{
		i ++;
		sum += i;
		if ((sum >= s) && (((sum - s)&1) == 0)) break;
	}
	printf("%d\n" , i);
	return 0;
}