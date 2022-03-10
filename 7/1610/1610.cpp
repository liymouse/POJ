#include <stdio.h>

int a[513][513];
int p[1000] , y , x;
struct kk{int x1 , y1 , x2 , y2;}b[349525];

int check(kk x)
{
int i , j , b;

	b = a[x.x1][x.y1];
	for (i = x.x1; i <= x.x2; i ++)
		for (j = x.y1; j <= x.y2; j ++)
			if (a[i][j] != b) return 2;
	return b;
}
int main()
{
int t , n , i , j , k , num;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d" , &n);
		for (i = 1; i <= n; i ++) for (j = 1; j <= n; j ++) scanf("%d" , &a[i][j]);
		b[0].x1 = 1; b[0].y1 = 1;
		b[0].x2 = n; b[0].y2 = n;
		y = 0; x = 0; k = 0;
		while (y >= x)
		{
			num = check(b[x]);
			if (num == 2)
			{
				// Up-Left
				y ++;
				b[y].x1 = b[x].x1;
				b[y].y1 = b[x].y1; 
				b[y].x2 = b[x].x1 + (b[x].x2 - b[x].x1) / 2;
				b[y].y2 = b[x].y1 + (b[x].y2 - b[x].y1) / 2;
				// Up-Right
				y ++;
				b[y].x1 = b[x].x1;
				b[y].y1 = b[y-1].y2 + 1;
				b[y].x2 = b[y-1].x2;
				b[y].y2 = b[x].y2;
				// Down-Left
				y ++;
				b[y].x1 = b[y-1].x2 + 1;
				b[y].y1 = b[x].y1;
				b[y].x2 = b[x].x2;
				b[y].y2 = b[y-2].y2;
				// Down-Right
				y ++;
				b[y].x1 = b[y-1].x1;
				b[y].y1 = b[y-2].y1;
				b[y].x2 = b[x].x2;
				b[y].y2 = b[x].y2;
				p[k ++] = 1;
			}
			else {p[k ++] = 0; p[k ++] = num;}
			x ++;
		}
		x = -1;
		if (k % 4 == 1) {x = p[0]; y = 1;}
		else if (k % 4 == 2) {x = p[0] * 2 + p[1]; y = 2;}
			else if (k % 4 == 3) {x = p[0] * 4 + p[1] * 2 + p[2]; y = 3;}
				else y = 0;
		if (x != -1) printf("%d" , x);
		while (y < k)
		{
			x = p[y] * 8 + p[y + 1] * 4 + p[y+2] * 2 + p[y+3];
			if (x < 10) printf("%d" , x);
			else printf("%c" , 'A' + x - 10);
			y += 4;
		}
		printf("\n");
	}
	return 0;
}
