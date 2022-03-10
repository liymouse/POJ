#include <stdio.h>
#define LEFT 1
#define RIGHT 2
#define TOP 8
#define BOTTOM 4

int xL , yt , xr , yb;

int code(int x , int y)
{
int c = 0;

	if (x < xL) c = c | LEFT; else if (x > xr) c = c | RIGHT;
	if (y < yb) c = c | TOP; else if (y > yt) c = c | BOTTOM;
	return c;
}

int right(int a , int b , int c , int d)
{
int x;

	x = a * d - c * b;
	if (x < 0) return -1; else if (x > 0) return 1; else return 0;
}

int main()
{
int n , c1 , c2 , c , p , res;
int x1 , y1 , x2 , y2 , x , y;

	scanf("%d" , &n);
	while (n --)
	{
		scanf("%d %d %d %d %d %d %d %d" , &x1 , &y1 , &x2 , &y2 , &xL , &yt , &xr , &yb);
		if (xL > xr) {c = xL; xL = xr; xr = c;}
		if (yb > yt) {c = yt; yt = yb; yb = c;}
		c1 = code(x1 , y1); c2 = code(x2 , y2);
		if (c1 == 0 || c2 == 0) res = 1;
		else if (c1 & c2) res = 0;
			else
			{
				x = x2 - x1; y = y2 - y1; res = 0;
				c = right(x , y , xL - x1 , yt - y1);
				if (c == 0) res = 1;
				else if (right(x , y , xL - x1 , yb - y1) != c) res = 1;
					else if (right(x , y , xr - x1 , yt - y1) != c) res = 1;
						else if (right(x , y , xr - x1 , yb - y1) != c) res = 1;
			}
		if (res) printf("T\n"); else printf("F\n");
	}
	return 0;
}