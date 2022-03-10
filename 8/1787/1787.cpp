#include <stdio.h>
#include <string.h>
#define NO printf("Charlie cannot buy coffee.\n")

int main()
{
int c1 , c2 , c3 , c4 , a1 , a2 , a3 , a4 , p , k;

	//freopen("1787in.txt" , "r" , stdin);
	//freopen("1787.txt" , "w" , stdout);
	while (scanf("%d %d %d %d %d" , &p , &c1 , &c2 , &c3 , &c4) == 5)
	{
		if ((p || c1 || c2 || c3 || c4) == 0) break;
		k = p % 5;
		if (c1 < k) {NO; continue;}
		a1 = k; p -= a1;
		while ((a1 + 5 <= c1) && (p >= 5)) {a1 += 5; p -= 5;}
		k = (p % 10) / 5;
		if (c2 + 5 * c4 < k) {NO; continue;}
		a2 = k; p -= a2 * 5;
		while ((a2 + 2 <= c2 + 5 * c4) && (p >= 10)) {a2 += 2; p -= 10;}
		a3 = p / 10;
		if (a3 > c3) {NO; continue;}
		a4 = 0;
		while ((a2 > c2) && (a3 < c3) && (a2 > 1)) {a2 -= 2; a3 ++;}
		while ((a2 > c2) && (a2 > 4)) {a2 -= 5; a4 ++;}
		if ((a2 > c2) && (a2 - c2 <= 3) && (a3 > 0) && (a2 > 2) && (a4 < c4))
			{a2 -= 3; a3 --; a4 ++;}
		if ((a2 > c2) && (a2 == 1) && (a3 > 1) && (a4 < c4)) {a2 --; a3 -= 2; a4 ++;}
		if ((a2 > c2) && (a2 == 4) && (a3 > 2) && (a4 + 1 < c4)) {a2 -= 4; a3 -= 3; a4 += 2;}
		if ((a2 == 2) && (c2 == 1) && (a3 > 1) && (a4 < c4)) {a2 --; a3 -= 2; a4 ++;}
		if ((a2 == 2) && (c2 == 0) && (a3 > 0) && (a1 > 4) && (a4 < c4)) {a2 -= 2; a3 --; a1 -= 5; a4 ++;}
		while ((a2 + 2 <= c2) && (a3 > 0)) {a2 += 2; a3 --;}
		if (a2 > c2) NO;
		else printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n" , a1 , a2 , a3 , a4);
	}
	return 0;
}