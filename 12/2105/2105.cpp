#include <stdio.h>

int main()
{
int t;
int p[8] = {1 , 2 , 4 , 8 , 16 , 32 , 64 , 128};
int i , x , y;
char s[33];

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%s" , s);
		for (i = 0; i < 4; i ++)
		{
			x = 7; y = 0;
			while (x >= 0) y += (s[i * 8 + 7 - x] - '0') * p[x--];
			if (i == 3) printf("%d\n" , y);
			else printf("%d." , y);
		}
	}
	return 0;
}