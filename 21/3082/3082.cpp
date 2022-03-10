//判断多边形是否相交 => 判断所有点是否在多边形内 => 旋转角度法判断 => 内360，边180，else外
#include <stdio.h>
#include <math.h>
#include <string.h>
#define Pi 3.1415926

typedef struct
{
	int num;
	int x[22] , y[22];
}kk;

int cha(int x1 , int y1 , int x2 , int y2)
{
	if (x1 * y2 - x2 * y1 > 0) return 1;
	else if (x1 * y2 - x2 * y1 == 0) return 0;
	else return -1;
}

int ptin(int x , int y , kk a)
{
int i , x1 , y1 , x2 , y2 , k;
double th , costh;

	th = 0; k = 0;
	for (i = 0; i < a.num - 1; i ++)
		if ((x == a.x[i]) && (y == a.y[i])) return 1;
		else
		{
			x1 = a.x[i] - x; y1 = a.y[i] - y;
			x2 = a.x[i+1] - x; y2 = a.y[i+1] - y;
			costh = (x1 * x2 + y1 * y2) / (sqrt(x1*x1 + y1*y1) * sqrt(x2*x2 + y2*y2));
			if (cha(x1 , y1 , x2 , y2) == 0) k = 1;
			th += acos(costh) * cha(x1 , y1 , x2 , y2);
		}
	if (th < 0) th = -th;
	if ((th - Pi * 2 < 1e-6) && (th - Pi * 2 > -1e-6)) return 1;
	if ((th - Pi < 1e-6) && (th - Pi > -1e-6) && (k)) return 1;
	else return 0;
}

int main()
{
int t , h;
int n , i , j , k , ok , num;
kk a[11];
int map[11][11];

	scanf("%d" , &t);
	for (h = 1; h <= t; h ++)
	{
		scanf("%d" , &n);
		for (i = 0; i < n; i ++)
		{
			scanf("%d" , &a[i].num);
			for (j = 0; j < a[i].num; j ++) scanf("%d,%d" , &a[i].x[j] , &a[i].y[j]);
			a[i].x[a[i].num] = a[i].x[0];
			a[i].y[a[i].num] = a[i].y[0];
			a[i].num ++;
		}
		memset(map , 0 , sizeof(map));
		for (i = 0; i < n; i ++)
			for (j = i + 1; j < n; j ++)
			{
				ok = 1;
				for (k = 0; k < a[i].num; k ++)
					if (ptin(a[i].x[k] , a[i].y[k] , a[j]))
					{
						map[i][j] = 1; ok = 0; break;
					}
				if (ok)
				{
					for (k = 0; k < a[j].num; k ++)
						if (ptin(a[j].x[k] , a[j].y[k] , a[i]))
						{
							map[i][j] = 1; break;
						}
				}
			}
		num = 0;
		printf("Data Set #%d\n" , h);
		for (i = 0; i < n; i ++)
			for (j = i + 1; j < n; j ++)
				if (map[i][j]) {num ++; printf("%d %d\n" , i+1 , j+1);}
		if (num == 0) printf("no collisions\n");
	}
	return 0;
}