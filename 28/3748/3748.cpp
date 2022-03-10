#include <stdio.h>

int n;

void change(int x , int t)
{
	if ((n & (1 << x)) != t)
	{
		if (t == 1) n |= 1 << x;
		else n &= ~(1 << x);
	}
}
int main()
{
	int x , y;
	scanf("%x,%d,%d" , &n , &x , &y);
	change(x , 0);
	change(y , 1);
	change(y-1, 1);
	change(y-2, 0);
	printf("%x\n" , n);
	return 0;
}
