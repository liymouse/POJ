#include <stdio.h>
int a[103][103];
int n , tot;
void dfs(int x , int y, int k)
{
int i;
int p[4][2] = {{-1 , 0} , {0 , -1} , {0 , 1} , {1 , 0}};

	tot ++;
	a[x][y] = -1;
	for (i = 0; i < 4; i ++)
	{
		int xx = x + p[i][0];
		int yy = y + p[i][1];
		if (0 <= xx && xx < n && 0 <= yy && yy < n && a[xx][yy] == k)
			dfs(xx , yy , k);
	}
}

int main()
{
int i , j , x[103] , y[103] , k , wrong;

	while (scanf("%d" , &n) == 1)
	{
		if (n == 0) break;
		if (n == 1) {printf("good\n"); continue;}
		for (i = 0; i < n; i ++) for (j = 0; j < n; j ++) a[i][j] = n-1;
		for (i = 0; i < n-1; i ++)
		{
			for (j = 0; j < n; j ++)
			{
				scanf("%d %d" , &x[i] , &y[i]);
				x[i] --; y[i] --;
				a[x[i]][y[i]] = i;
			}
		}
		for (i = 0; i < n; i ++) for (j = 0; j < n; j ++) if (a[i][j] == n-1) {x[n-1] = i; y[n-1] = j;}
		wrong = 0;
		for (i = 0; i < n; i ++)
		{
			tot = 0;
			dfs(x[i] , y[i] , i);
			if (tot < n) {wrong = 1; break;}
		}
		if (wrong) printf("wrong\n"); else printf("good\n");
	}
	return 0;
}