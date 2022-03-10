#include <stdio.h>
#include <string.h>

int main()
{
int n , i , j , tot;
struct kk{int minx , maxx , miny , maxy;} a[5000];
int b[5000];
	
	while (scanf("%d" , &n) == 1)
	{
		for (i = 0; i < n; i ++) scanf("%d %d %d %d" , &a[i].minx , &a[i].maxx , &a[i].miny , &a[i].maxy);
		memset(b , 0 , sizeof(b));
		tot = 0;
		for (i = 0; i < n; i ++)
		{
			for (j = i + 1; j < n; j ++)
			{
				if ((b[j] == 0) && (a[j].minx >= a[i].minx) && (a[j].miny >= a[i].miny) &&
					(a[j].maxx <= a[i].maxx) && (a[j].maxy <= a[i].maxy))
				{
					tot ++; b[j] = 1;
				}
				if ((b[i] == 0) && (a[i].minx >= a[j].minx) && (a[i].miny >= a[j].miny) &&
					(a[i].maxx <= a[j].maxx) && (a[i].maxy <= a[j].maxy))
				{
					tot ++; b[i] = 1;
				}
				if (tot == n) break;
			}
			if (tot == n) break;
		}
		printf("%d\n" , tot);
	}
	return 0;
}