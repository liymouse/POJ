#include <stdio.h>

int sum10(int x)
{
int sum = 0;

	while (x > 0) {sum += x % 10; x /= 10;}
	return sum;
}

int sum12(int x)
{
int sum = 0;
	
	while (x > 0) {sum += x % 12; x /= 12;}
	return sum;
}

int sum16(int x)
{
int sum = 0;

	while (x > 0) {sum += x % 16; x /= 16;}
	return sum;
}

int main()
{
int n;

	for (n = 2992; n < 10000; n ++)
		if ((sum10(n) == sum12(n)) && (sum10(n) == sum16(n))) printf("%d\n" , n);
	return 0;
}