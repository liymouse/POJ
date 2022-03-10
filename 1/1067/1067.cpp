#include <stdio.h>
#define x 1.61803398874989484820458683436564
#define y 2.6180339887498948482045868343656

int main()
{
int a , b , c , i;

	while (scanf("%d %d" , &a , &b) == 2)
	{
		if (a > b) {c = a; a = b; b = c;}
		c = (int)(a * 1.0 / x);
		for (i = c - 2; i <= c + 2; i ++)
			if (((int)(i * x) == a) && ((int)(i * y) == b)) {c = -1; break;}
		if (c == -1) printf("0\n"); else printf("1\n");
	}
	return 0;
}
