#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct kk{int x , y;}node[578];

bool cmp(kk &x , kk &y)
{
	if (x.x == y.x) return x.y < y.y;
	else return x.x < y.x;
}

int main()
{
int a[25][25] , b[578] , i , j;
int x , y , n , tot;

	n = 0;
	while (scanf("%d %d" , &x , &y) == 2)
	{
		if ((x == 0) && (y == 0))
		{
			sort(node , node + n , cmp);
			memset(b , 0 , sizeof(b));
			tot = 1;
			while (1)
			{
				j = -1;
				for (i = 0; i < n; i ++) 
					if (b[i] == 0) {b[i] = tot; j = i; break;}
				if (j == -1) break;
				i = j + 1;
				while (i < n)
				{
					if ((b[i] == 0) && (node[j].x <= node[i].x) && (node[j].y <= node[i].y))
					{b[i] = tot; j = i;}
					i ++;
				}
				tot ++;
			}
			printf("%d\n" , tot-1);
			n = 0;
		}
		if ((x == -1) && (y == -1)) break;
		node[n].x = x; node[n].y = y;
		n ++;
	}
	return 0;
}
