#include <stdio.h>
#include <string.h>

//change 45 degree coordinate
//i = 0~n-1 (row)
//j = 0~m-1 (col)
//nxm -> (n+m)x(n+m)
//(i,j) -> (i+j, n-1-i+j), (i+j, n-i+j)
//up = (k, k+n) k = 0~m-1
//down = (k+n, k) k = 0~m-1
//left = (k, n-1-k) k = 0~n-1
//right = (m+k, m+n-1-k) k = 0~n-1
int flag[160][160]; //-1 outside, 0 not visit, other visit 
int a[160][160]; //wall up = 1, right = 2£¬ down = 4, left = 8
#define UP 1
#define RIGHT 2
#define DOWN 4
#define LEFT 8
int m, n, N;
int num;
int p[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
void dfs(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= N) return;
    if (flag[x][y] != 0) return;
    flag[x][y] = 1;
    num++;
    for (int i = 0; i < 4; i++)
        if ((a[x][y] & (1 << i)) == 0) dfs(x + p[i][0], y + p[i][1]);
}

int main()
{
    int ca = 1;
    while (scanf("%d %d", &m, &n) == 2)
    {
        if (m == 0) break;
        N = m + n;
        memset(a, 0, sizeof(a));
        memset(flag, 0xff, sizeof(flag));
        for (int i = 0; i < n; i++)
        {
            char s[100];
            scanf("%s", s);
            for (int j = 0; j < m; j++)
            {
                int x = i + j;
                int y = n - 1 - i + j;
                flag[x][y] = flag[x][y + 1] = flag[x + 1][y] = flag[x + 1][y + 1] = 0;
                if (s[j] == '/')
                {
                    a[x][y] |= DOWN;
                    a[x][y + 1] |= DOWN;
                    a[x + 1][y] |= UP;
                    a[x + 1][y + 1] |= UP;
                }
                else
                {
                    a[x][y] |= RIGHT;
                    a[x][y + 1] |= LEFT;
                    a[x + 1][y] |= RIGHT;
                    a[x + 1][y + 1] |= LEFT;
                }
            }
        }
        //1st visit block connect to outside
        for (int k = 0; k < n; k++)
        {
            if (flag[k][n - 1 - k] == 0) dfs(k, n - 1 - k);
            if (flag[m + k][m + n - 1 - k] == 0) dfs(m + k, m + n - 1 - k);
        }
        for (int k = 0; k < m; k++)
        {
            if (flag[k][k + n] == 0) dfs(k, k + n);
            if (flag[k + n][k] == 0) dfs(k + n, k);
        }
        int resN = 0, resV = 0;
        for (int i = 0; i < N; i ++)
            for (int j = 0; j < N; j ++)
                if (flag[i][j] == 0)
                {
                    num = 0;
                    dfs(i, j);
                    resN++;
                    if (num > resV) resV = num;
                }
        printf("Maze #%d:\n", ca++);
        if (resN == 0) printf("There are no cycles.\n");
        else printf("%d Cycles; the longest has length %d.\n", resN, resV);
        printf("\n");
    }
    return 0;
}