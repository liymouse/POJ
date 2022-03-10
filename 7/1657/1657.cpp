#include <stdio.h>

int main()
{
char s[3];
int t , x1 , y1 , x2 , y2 , x , y;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%s" , s);
		x1 = s[0] - 'a'; y1 = s[1] - '1';
		scanf("%s" , s);
		x2 = s[0] - 'a'; y2 = s[1] - '1';
		if (x1 > x2) x = x1 - x2; else x = x2 - x1;
		if (y1 > y2) y = y1 - y2; else y = y2 - y1;
		if ((x == 0) && (y == 0)) {printf("0 0 0 0\n"); continue;}
		if (x > y) printf("%d " , x); else printf("%d " , y);
		if ((x1 == x2) || (y1 == y2) || (x1 + y1 == x2 + y2) || (x1 + 8 - y1 == x2 + 8 - y2)) printf("1 ");
		else printf("2 ");
		if ((x1 == x2) || (y1 == y2)) printf("1 ");
		else printf("2 ");
		if ((x1 + y1) % 2 != (x2 + y2) % 2) printf("Inf\n");
		else if ((x1 + y1 == x2 + y2) || (x1 + 8 - y1 == x2 + 8 - y2)) printf("1\n");
			else printf("2\n");
	}
	return 0;
}