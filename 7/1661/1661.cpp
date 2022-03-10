#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct
{
	int x1 , x2 , h , next1 , next2;
}board;
board a[1500];

int cmp(board &x , board &y)
{
	return x.h > y.h;
}

int main()
{
int time[1500][2];
int t , fx , fy , max , temp;
int n , i , j , k , t1 , t2 , res;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d %d %d" , &n , &fx , &fy , &max);
		for (i = 0; i < n; i ++) scanf("%d %d %d" , &a[i].x1 , &a[i].x2 , &a[i].h);
		for (i = 0; i < n; i ++) {a[i].next1 = -1; a[i].next2 = -1;}
		for (i = 0; i < n; i ++) {time[i][0] = -1; time[i][1] = -1;}
		sort(a , a + n , cmp);
		for (i = 0; i < n; i ++)
			for (j = i + 1; j < n; j ++)
				if (a[i].h - a[j].h <= max)
				{
					if ((a[j].x1 <= a[i].x1) && (a[i].x1 <= a[j].x2) && (a[i].next1 == -1))
						a[i].next1 = j;
					if ((a[j].x1 <= a[i].x2) && (a[i].x2 <= a[j].x2) && (a[i].next2 == -1))
						a[i].next2 = j;
				}
		k = -1;
		for (i = 0; i < n; i ++)
			if ((a[i].h <= fy) && (a[i].x1 <= fx) && (fx <= a[i].x2))
			{
				time[i][0] = fy - a[i].h + fx - a[i].x1;
				time[i][1] = fy - a[i].h + a[i].x2 - fx;
				k = i;
				break;
			}
		if (k == -1) res = fy;
		else
		{
			for (i = k + 1; i < n; i ++)
				for (j = k; j < i; j ++)
				{
					if ((time[j][0] > -1) && (a[j].next1 == i))
					{
						temp = time[j][0] + a[j].h - a[i].h + a[j].x1 - a[i].x1;
						if ((temp < time[i][0]) || (time[i][0] == -1)) time[i][0] = temp;
						temp = time[j][0] + a[j].h - a[i].h + a[i].x2 - a[j].x1;
						if ((temp < time[i][1]) || (time[i][1] == -1)) time[i][1] = temp;
					}
					if ((time[j][1] > -1) && (a[j].next2 == i))
					{
						temp = time[j][1] + a[j].h - a[i].h + a[j].x2 - a[i].x1;
						if ((temp < time[i][0]) || (time[i][0] == -1)) time[i][0] = temp;
						temp = time[j][1] + a[j].h - a[i].h + a[i].x2 - a[j].x2;
						if ((temp < time[i][1]) || (time[i][1] == -1)) time[i][1] = temp;
					}
				}
			res = 100000000;
			for (i = 0; i < n; i ++)
			{
				if ((a[i].h <= max) && (a[i].next1 == -1) && (time[i][0] > -1))
				{
					temp = time[i][0] + a[i].h;
					if (temp < res) res = temp;
				}
				if ((a[i].h <= max) && (a[i].next2 == -1) && (time[i][1] > -1))
				{
					temp = time[i][1] + a[i].h;
					if (temp < res) res = temp;
				}
			}
		}
		printf("%d\n" , res);
	}
	return 0;
}
