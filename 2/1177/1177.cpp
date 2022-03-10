//PKU1177
//这里是矩形切割方法
#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))

typedef struct	//存放矩阵的结构体
{
	int sign, x, y, X, Y; //sign层数奇数为1，偶数为-1 / 左下角 / 右上角
}pict;

#define MAX_PICT 10000

void intersect (pict p1, pict p2, pict *p3)	//计算p1,p2的重叠部分
{
	p3->x = max(p1.x , p2.x);  p3->y = max(p1.y , p2.y);
	p3->X = min(p1.X , p2.X);  p3->Y = min(p1.Y , p2.Y);
	p3->sign = -p1.sign * p2.sign;
}

int main ()
{
int ans = 0;
int n , tot; //n输入的矩形个数，tot总数
pict p[MAX_PICT];
int i , j , k;

	scanf ("%d" , &n);
	tot = 0;
	for (i = 0; i < n ; i++)
	{
		k = tot ++;
		scanf("%d %d %d %d", &p[k].x , &p[k].y , &p[k].X , &p[k].Y);
		p[k].sign = 1;
		for (j = 0;  j < k; j++)
		{
			intersect(p[j] , p[k] , &p[tot]);
			if ((p[tot].X > p[tot].x && p[tot].Y >= p[tot].y) ||
				(p[tot].X == p[tot].x && p[tot].Y > p[tot].y))
				if (p[tot].x == p[k].x && p[tot].X == p[k].X &&
					p[tot].y == p[k].y && p[tot].Y == p[k].Y)
				{
					tot = k;
					break;
				}
				else tot++;
		}
	}
	for (i = 0; i < tot; i++)
		ans += p[i].sign * 2 * (p[i].X - p[i].x + p[i].Y - p[i].y);
	printf("%d\n" , ans);
	return 0;
}

