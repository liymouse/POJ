#include <stdio.h>

struct array
{
    int num , x , y;
}b[10000] , y;
int a[102][102] , f[102][102];
int m , n;

void qsort(int s , int t)
{
int i , j , x;
    
    i = s; j = t; x = b[(i+j)/2].num;
    do
    {
        while (b[i].num < x) i ++;
        while (b[j].num > x) j --;
        if (i <= j)
        {
			y = b[i]; b[i] = b[j]; b[j] = y;
			i ++; j --;
		}
	}
	while (i <= j);
	if (s < j) qsort(s , j);
    if (i < t) qsort(i , t);
}
    
int main()
{
int i , j , k , max;

	scanf("%d %d" , &m , &n);
	k = 0;
	for (i = 1; i <= m; i ++)
		for (j = 1; j <= n; j ++)
		{
			scanf("%d" , &a[i][j]);
			b[k].num = a[i][j];
            b[k].x = i; b[k].y = j;
            k ++;
		}
	for (i = 0; i <= m+1; i ++) {a[i][0] = 0; a[i][n+1] = 0;}
	for (i = 0; i <= n+1; i ++) {a[0][i] = 0; a[m+1][i] = 0;}
    for (i = 0; i <= m; i ++) for (j = 0; j <= n; j ++) f[i][j] = 0;
    qsort(0 , k-1);
    for (i = 0; i < k; i ++)
    {
        max = 0;
        if ((a[b[i].x-1][b[i].y] < b[i].num) && (f[b[i].x-1][b[i].y] > max))
            max = f[b[i].x-1][b[i].y];
        if ((a[b[i].x+1][b[i].y] < b[i].num) && (f[b[i].x+1][b[i].y] > max))
            max = f[b[i].x+1][b[i].y];
        if ((a[b[i].x][b[i].y-1] < b[i].num) && (f[b[i].x][b[i].y-1] > max))
            max = f[b[i].x][b[i].y-1];
        if ((a[b[i].x][b[i].y+1] < b[i].num) && (f[b[i].x][b[i].y+1] > max))
            max = f[b[i].x][b[i].y+1];
        if (max + 1 > f[b[i].x][b[i].y]) f[b[i].x][b[i].y] = max + 1;
    }
    max = 0;
    for (i = 1; i <= m; i ++)
        for (j = 1; j <= n; j ++)
            if (f[i][j] > max) max = f[i][j];
    printf("%d\n" , max);
	return 0;
}    
