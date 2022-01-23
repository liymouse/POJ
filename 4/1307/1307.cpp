#include <stdio.h>
#include <string.h>

int si, sj, ei, ej, n, m;
int p[4][2] = { { 0, -1 },{ -1,0 },{ 0, 1 },{ 1,0 } };
int a[12][12];
int v[12][12];
int L[12][12];
int path[200], pathn;

void dfs(int x, int y, int k)
{
    if (pathn != -1) return;
    v[x][y] = 1;
    path[k] = x*m + y;
    if (x == ei && y == ej)
    {
        pathn = k + 1;
        return;
    }
    for (int i = 0; i < 4; i ++)
        if ((a[x][y] & (1 << i)) == 0)
        {
            int xx = x + p[i][0];
            int yy = y + p[i][1];
            if (v[xx][yy] == 0)
            {
                dfs(xx, yy, k + 1);
                if (pathn != -1) return;
            }
        }
}
int main()
{
    int ca = 1;
    while (scanf("%d %d %d %d %d %d", &n, &m, &si, &sj, &ei, &ej) == 6)
    {
        if (n == 0 && m == 0 && si == 0 && ej == 0 && ei == 0 && ej == 0) break;
        si--; sj--; ei--; ej--;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[i][j]);
                a[i][j] <<= 2;
                if (i == 0) a[i][j] |= 2;
                else if (a[i - 1][j] & 8) a[i][j] |= 2;
                if (j == 0) a[i][j] |= 1;
                else if (a[i][j - 1] & 4) a[i][j] |= 1;
                if (i == n - 1) a[i][j] |= 8;
                if (j == m - 1) a[i][j] |= 4;
            }
        memset(v, 0, sizeof(v));
        pathn = -1;
        dfs(si, sj, 0);
        memset(L, 0, sizeof(L));
        int label = 1;
        for (int i = 0; i < pathn; i++)
        {
            int x = path[i] / m;
            int y = path[i] % m;
            L[x][y] = label ++;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (v[i][j] && L[i][j] == 0) L[i][j] = -1;
        printf("Maze %d\n\n", ca++);
        //1st line
        printf("+");
        for (int j = 0; j < m; j++) printf("---+"); printf("\n");
        for (int i = 0; i < n; i++)
        {
            //1st col
            printf("|");
            for (int j = 0; j < m; j++)
            {
                if (L[i][j] == -1) printf("???");
                else if (L[i][j] == 0) printf("   ");
                else printf("%3d", L[i][j]);
                if (a[i][j] & 4) printf("|"); else printf(" ");
            }
            printf("\n");
            printf("+");
            for (int j = 0; j < m; j++)
                if (a[i][j] & 8) printf("---+"); else printf("   +");
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}