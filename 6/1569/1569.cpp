#include <stdio.h>

int main()
{
int n , i , a , b , c , bo , s , t , x , y , max , ba , bb , bc;
int x1 , y1 , x2 , y2 , k1 , k2;
struct Node{int x , y;}p[15];
char ss[5];

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		for (i = 0; i < n; i ++)
			scanf("%s %d %d" , ss , &p[i].x , &p[i].y);
		max = 0;
		for (a = 0; a < n-2; a ++)
			for (b = a + 1; b < n-1; b ++)
				for (c = b + 1; c < n; c ++)
				{
					x1 = p[b].x - p[a].x; y1 = p[b].y - p[a].y;
					x2 = p[c].x - p[a].x; y2 = p[c].y - p[a].y;
					if (x1 * y2 != y1 * x2)
					{
						bo = 0;
						for (i = 0; i < n; i ++)
							if ((i != a) && (i != b) && (i != c))
							{
								s = p[i].x - p[a].x; t = p[i].y - p[a].y;
								x = p[i].x - p[b].x; y = p[i].y - p[b].y;
								k1 = p[i].x - p[c].x; k2 = p[i].y - p[c].y;
								if (((s * y1 - x1 * t) * (s * y2 - x2 * t) <= 0) &&
									((x * (p[a].y - p[b].y) - y * (p[a].x - p[b].x)) * (x * (p[c].y - p[b].y) - y * (p[c].x - p[b].x)) <= 0) &&
									((k1 * (p[a].y - p[c].y) - k2 * (p[a].x - p[c].x)) * (k1 * (p[b].y - p[c].y) - k2 * (p[b].x - p[c].x)) <= 0))
								{bo = 1; break;}
							}
						if (bo == 0)
						{
							if ((x1 * y2 - y1 * x2 < 0) && (y1 * x2 - x1 * y2 > max))
							{
								max = y1 * x2 - x1 * y2;
								ba = a; bb = b; bc = c;
							}
							else if (x1 * y2 - y1 * x2 > max)
							{
								max = x1 * y2 - y1 * x2;
								ba = a; bb = b; bc = c;
							}
						}
					}
				}
		printf("%c%c%c\n" , ba + 'A' , bb + 'A' , bc + 'A');
	}
}