#include <stdio.h>
#include <math.h>
#define Pi 3.14159

int main()
{
char s[10];
int x , y , z , last;
double d;

	while (scanf("%s" , s) == 1)
	{
		if (s[0] == 'E') break;
		scanf("%d %d %d" , &x , &y , &z);
		if (z > 180) z = 360 - z;
		d = (x * z * Pi) / 180.0;
		if (2 * d <= y * 5)
		{
			last = floor(y - 2 * d / 5);
			printf("YES %d\n" , last);
		}
		else
		{
			last = y * 5;
			printf("NO %d\n" , last);
		}
		scanf("%s" , s);
	}
	return 0;
}