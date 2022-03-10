#include <stdio.h>

int main()
{
int h , u , d , f;
double up , p , tot;
int day;

	while (scanf("%d %d %d %d" , &h , &u , &d , &f) == 4)
	{
		if (h == 0) break;
		tot = 0; day = 0; p = u * f * 1.0 / 100; up = u;
		while (1)
		{
			day ++;
			tot += up;
			if (tot > h) break;
			tot -= d;
			if (tot < 0) break;
			up -= p;
			if (up < 0) up = 0;
		}
		if (tot >= h) printf("success on day %d\n" , day);
		else printf("failure on day %d\n" , day);
	}
	return 0;
}