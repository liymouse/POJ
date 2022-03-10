#include <stdio.h>
#include <string.h>
#include <math.h>
#define sqrt2 1.414213562373

int main()
{
int h , i , t;
double x , y;
char s[201];

	h = 0;
	while (1)
	{
		gets(s);
		if (strcmp(s , "END") == 0) break;
		i = 0; h ++; x = 0; y = 0;
		while (s[i] != 0)
		{
			t = 0;
			while ((s[i] >= '0') && (s[i] <= '9')) t = t * 10 + s[i++] - '0';
			switch (s[i])
			{
				case 'N' :
					i ++;
					if (s[i] == 'E')
					{
						i += 2; x += t / sqrt2; y += t / sqrt2;
					}
					else if (s[i] == 'W')
					{
						i += 2; x -= t / sqrt2; y += t / sqrt2;
					}
					else {i ++; y += t;}
				break;
				case 'S' :
					i ++;
					if (s[i] == 'E')
					{
						i += 2; x += t / sqrt2; y -= t / sqrt2;
					}
					else if (s[i] == 'W')
					{
						i += 2; x -= t / sqrt2; y -= t / sqrt2;
					}
					else {i ++; y -= t;}
				break;
				case 'E' :
					i += 2;
					x += t;
				break;
				case 'W' :
					i += 2;
					x -= t;
				break;
			}
		}
		printf("Map #%d\n" , h);
		printf("The treasure is located at (%.3lf,%.3lf).\n" , x , y);
		printf("The distance to the treasure is %.3lf.\n" , sqrt(x*x+y*y));
		printf("\n");
	}
	return 0;
}