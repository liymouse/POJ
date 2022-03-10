#include <stdio.h>
#include <string.h>

int father[1001];
int a[1001][1001];
int b[1001][1001];
int co[1001] , p[1001] , have[1001];

int getfather(int x)
{
int f;

	if (father[x] == x) return x;
	else
	{
		f = getfather(father[x]);
		father[x] = f;
		return f;
	}
}

int main()
{
int x , y , bo , n , i , j , k , maxn;
int num , h , done;
	
	memset(a , 0 , sizeof(a));
	memset(b , 0 , sizeof(b));
	memset(co , 0 , sizeof(co));
	bo = 0; n = 0; maxn = 0; h = 0; done = 0;
	while (scanf("%d" , &x) == 1)
	{
		if (x == 0)
		{
			if (bo == 0) break;
			n = 0; h ++;
			printf("Network #%d\n" , h);
			for (i = 1; i <= maxn; i ++) if (co[i]) p[n ++] = i;
			for (i = 0; i < n; i ++)
			{
				for (j = 1; j <= maxn; j ++) {a[p[i]][j] = 0; a[j][p[i]] = 0;}
				for (j = 0; j < n; j ++) father[p[j]] = p[j];
				for (j = 1; j <= maxn; j ++)
					for (k = j + 1; k <= maxn; k ++)
						if (a[j][k] == 1) father[getfather(j)] = getfather(k);
				memset(have , 0 , sizeof(have));
				for (j = 0; j < n; j ++)
					have[getfather(p[j])] = 1;
				num = 0;
				for (j = 1; j <= 1000; j ++) num += have[j];
				num --;
				if (num > 1) {printf("  SPF node %d leaves %d subnets\n" , p[i] , num); done = 1;}
				for (j = 1; j <= maxn; j ++) {a[p[i]][j] = b[p[i]][j]; a[j][p[i]] = b[j][p[i]];}
			}
			if (done == 0) printf("  No SPF nodes\n");
			printf("\n");
			memset(a , 0 , sizeof(a));
			memset(b , 0 , sizeof(b));
			memset(co , 0 , sizeof(co));
			bo = 0; n = 0; maxn = 0; done = 0;
		}
		else
		{
			bo = 1;
			scanf("%d" , &y);
			a[x][y] = 1; a[y][x] = 1;
			b[x][y] = 1; b[y][x] = 1;
			co[x] = 1; co[y] = 1;
			if (x > maxn) maxn = x; if (y > maxn) maxn = y;
		}
	}
	return 0;
}