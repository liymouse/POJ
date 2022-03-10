#include <stdio.h>
#include <string.h>
#include <math.h>

int prim(int a[][20] , int n)
{
    int mark[20] = {0} , dist[20];

    for (int i = 0; i < n; i ++) dist[i] = 9999;
	dist[1] = 0;
    for (int i = 0; i < n; i ++)
	{
		int mv = 9999 , k = -1;
        for (int j = 0; j < n; j ++)
            if (mark[j] == 0 && dist[j] < mv) {mv = dist[j]; k = j;}
        if (k == -1) break;
        mark[k] = 1;
        for (int j = 0; j < n; j ++)
            if (mark[j] == 0 && a[k][j] < dist[j]) dist[j] = a[k][j];
	}
	int tot = 0;
    for (int i = 0; i < n; i ++) tot += dist[i];
    return tot;
}

int main()
{
    int n , m;
    int node[20];
    int b[20][20];

    while (scanf("%d %d" , &n , &m) == 2)
    {
        if (n == 0 && m == 0) break;
        double res = 1e10;
        int resnode[20];
        for (int i = 0; i < n; i ++) scanf("%d" , &node[i]);
        for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) scanf("%d" , &b[i][j]);
        for (int i = 0; i < 1 << n; i ++)
        {
            int a[20] , k = 0;
            for (int j = 0; j < n; j ++)
                if ((1 << j) & i) a[k ++] = j;
            if (k == m)
            {
                int v[20][20];
                int nodev = 0;
                for (int x = 0; x < m; x ++) nodev += node[a[x]];
                for (int x = 0; x < m; x ++)
                    for (int y = 0; y < m; y ++)
                        v[x][y] = b[a[x]][a[y]];
                int edgev = prim(v , m);
                if ((double)edgev < res * nodev)
                {
                    res = (double)edgev / nodev;
                    for (int x = 0; x < m; x ++) resnode[x] = a[x];
                }
                else if ((double)edgev == res * nodev)
                {
                    int change = 0;
                    for (int x = 0; x < m; x ++)
                        if (a[x] < resnode[x]) {change = 1; break;}
                    if (change)
                        for (int x = 0; x < m; x ++) resnode[x] = a[x];
                }
            }
        }
        printf("%d" , resnode[0]+1);
        for (int i = 1; i < m; i ++) printf(" %d" , resnode[i]+1);
        printf("\n");
    }
}
