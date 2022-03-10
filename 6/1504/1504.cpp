#include <stdio.h>

int main()
{
int t , x , y , a , b , sum;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &x , &y);
		a = 0;
		while (x > 0) {a = a * 10 + x % 10; x /= 10;}
		b = 0;
		while (y > 0) {b = b * 10 + y % 10; y /= 10;}
		a = a + b;
		sum = 0;
		while (a > 0) {sum = sum * 10 + a % 10; a /= 10;}
		printf("%d\n" , sum);
	}
	return 0;
}
