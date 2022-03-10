#include <stdio.h>

char s[1000001];

int main()
{
int x1 , y1 , x2 , y2 , t;
__int64 area , k;
int i;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%s" , s);
		x1 = 0; y1 = 0; area = 0;
		i = 0;
		while (1)
		{
			if (s[i] == '5') break;
			switch (s[i])
			{
				case '8' : x2 = x1; y2 = y1 + 1; break;
				case '2' : x2 = x1; y2 = y1 - 1; break;
				case '6' : x2 = x1 + 1; y2 = y1; break;
				case '4' : x2 = x1 - 1; y2 = y1; break;
				case '9' : x2 = x1 + 1; y2 = y1 + 1; break;
				case '7' : x2 = x1 - 1; y2 = y1 + 1; break;
				case '3' : x2 = x1 + 1; y2 = y1 - 1; break;
				case '1' : x2 = x1 - 1; y2 = y1 - 1; break;
			}
			k = x1 * y2 - x2 * y1;
			area += k;
			x1 = x2; y1 = y2;
			i ++;
		}
		if (area < 0) area = -area;
		if (area % 2 == 1) printf("%I64d.5\n" , area/2);
		else printf("%I64d\n" , area/2);
	}
	return 0;
}
