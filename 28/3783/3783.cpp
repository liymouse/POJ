#include "stdio.h"
#include "string.h"
const int INF = 200000000;
int f[1010][53];

int find(int r, int k)
{
	if (r <= 0)
		return 0;
	if (k == 1)
	{
		f[r][k] = r;
		return r;
	}
	if (r == 1)
	{
		f[r][k] = 1;
		return 1;
	}
	if (f[r][k] != 0)
	{
		return f[r][k];
	}
	int mid;
	int left, right, t;
	f[r][k] = INF;
	for (mid = 1; mid <= r; ++mid)
	{
		left = find(mid - 1, k - 1);
		right = find(r - mid , k);
		t = left > right ? left : right;  
		if (t < f[r][k])
			f[r][k] = t;
	}
	f[r][k] ++;
	return f[r][k];
}

int main()
{
	int cas;
	scanf("%d" , &cas);
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= 1000; i ++) f[i][1] = i;
	for (int i = 1; i <= 50; i ++) f[1][i] = 1;
	for (int b = 2; b <= 50; b ++)
		for (int i = 2; i <= 1000; i ++)
		{
			f[i][b] = INF;
			for (int mid = 1; mid <= i; mid ++)
			{
				int left = f[mid-1][b-1];
				int right = f[i-mid][b];
				int t = left > right ? left : right;
				if (t < f[i][b])
					f[i][b] = t;
			}
			f[i][b] ++;
		}
		
	while (cas --)
	{
		int t , n , b;
		scanf("%d %d %d" , &t , &b , &n);
		//printf("%d %d\n" , t , find(n , b));
		printf("%d %d\n" , t , f[n][b]);
	}
	return 0;
}
