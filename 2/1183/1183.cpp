#include <stdio.h>
#include <math.h>

int main()
{
__int64 a , i;

	scanf("%I64d" , &a);
	for (i = (int)sqrt(a * a + 1); i > 0; i --)
		if ((a * a + 1) % i == 0)
		{
			printf("%I64d\n" , i + a + (a * a + 1) / i + a);
			break;
		}
	return 0;
}