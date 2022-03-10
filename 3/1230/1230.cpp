#include <stdio.h> 
#include <string.h>

int main()
{
struct walls{int s , t;} wall[100];
int del[100];
int n , i , j , k , t , x , minc , maxc , max , p , tot , result;

	scanf("%d" , &t);
	while (t --)
	{
		scanf("%d %d" , &n , &k);
		for (i = 0; i < n; i ++) del[i] = 0;
		result = 0; maxc = 0; minc = 200;
		for (i = 0; i < n; i ++)
		{
			scanf("%d %d %d %d" , &wall[i].s , &x , &wall[i].t , &x);
			if (wall[i].s > wall[i].t) {x = wall[i].s; wall[i].s = wall[i].t; wall[i].t = x;}
			if (wall[i].s < minc) minc = wall[i].s;
			if (wall[i].t > maxc) maxc = wall[i].t;
		}
		for (i = minc; i <= maxc; i ++)
		{
			while (1)
			{
				max = 0; tot = 0;
				for (j = 0; j < n; j ++)
					if ((del[j] == 0) && (wall[j].s <= i) && (i <= wall[j].t))
					{
						tot ++;
						if (wall[j].t > max) {max = wall[j].t; p = j;}
					}
				if (tot > k) {result ++; del[p] = 1;}
				else break;
			}
		}
		printf("%d\n" , result);
	}
	return 0;
}