#include <stdio.h>
#include <string.h>

int a[101][101];
int memo[2][101][101];
int m , n;
int p[4][2] = {{-1,0} , {1,0} , {0,-1} , {0,1}};
int maxv[100];
int minv[100];
int dir[100];
int k;

int main()
{
    int ca;
    scanf("%d" , &ca);
    while (ca --)
    {
        scanf("%d %d" , &m , &n);
        for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++)
        {
            scanf("%d" , &a[i][j]);
            memo[0][i][j] = 1 - a[i][j];
        }
        k = 0;
        while (1)
        {
            int x , y;
            char s[10];
            scanf("%d %d" , &x , &y);
            if (x == 0 && y == 0) break;
            scanf("%s" , s);
            minv[k] = x; maxv[k] = y;
            if (s[0] == 'U') dir[k] = 1;
            else if (s[0] == 'D') dir[k] = 0;
            else if (s[0] == 'L') dir[k] = 3;
            else dir[k] = 2;
            k ++;
        }
        int now = 0 , next = 1;
        for (int t = k-1; t >= 0; t --)
        {
            for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++) memo[next][i][j] = 0;
            for (int i = 0; i < m; i ++)
                for (int j = 0; j < n; j ++)
                    if (memo[now][i][j])
                    {
                        int x = i + minv[t] * p[dir[t]][0];
                        int y = j + minv[t] * p[dir[t]][1];
                        int ok = 1;
                        for (int h = i; h != x; h += p[dir[t]][0]) if (a[h][j]) {ok = 0; break;}
                        for (int h = j; h != y; h += p[dir[t]][1]) if (a[i][h]) {ok = 0; break;}
                        if (ok)
                        {
                            int step = 0;
                            while (x >= 0 && x < m && y >= 0 && y < n && a[x][y] == 0 && minv[t] + step <= maxv[t])
                            {
                                memo[next][x][y] = 1;
                                x += p[dir[t]][0];
                                y += p[dir[t]][1];
                                step ++;
                            }
                        }
                    }
            now = 1 - now;
            next = 1 - next;
        }
        int res = 0;
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < n; j ++)
                res += memo[now][i][j];
        printf("%d\n" , res);
    }
    return 0;
}