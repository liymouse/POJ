#include <stdio.h>

int main()
{
int a , h , m , s , b;
int mangle , hangle; //mangle 12点到分针的顺时针角度*120  hangle 12点到时针*120
int angle , num;

	while (scanf("%d %d:%d:%d" , &a , &h , &m , &s) == 4)
	{
		if (a < 0) break;
		a = a * 120;
		mangle = 6 * 120 * m + 12 * s;
		if (h < 12)	hangle = 30 * 120 * h + 60 * m + s;
		else hangle = 30 * 120 * (h - 12) + 60 * m + s;
		angle = mangle - hangle;
		if (angle < 0) angle += 360 * 120;
		num = 0;
		if (angle > a) b = 0; else b = 1;
		while (1)
		{
			if ((b == 1) && (angle >= a)) break;
			num ++; angle += 11;
			if (angle > 360 * 120) {b = 1; angle -= 360 * 120;}
		}
		if (angle > a) num --;
		s += num;
		m += s / 60; s %= 60;
		h += m / 60; m %= 60;
		if (h >= 24) h -= 24;
		if (h < 10) printf("0"); printf("%d:" , h);
		if (m < 10) printf("0"); printf("%d:" , m);
		if (s < 10) printf("0"); printf("%d\n" , s);
	}
	return 0;
}