#include <stdio.h>
#include <math.h>

int main()
{
int n , b , a;

	while (scanf("%d %d" , &b , &n) == 2)
	{
		if (n == 0 && b == 0) break;
		a = (int)(pow(b , 1.0/n));
		if (b - pow(a , n) <= pow(a+1 , n) - b) printf("%d\n" , a);
		else printf("%d\n" , a + 1); 
	}
	return 0;
}


