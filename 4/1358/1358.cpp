#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m, n, H, W;
char a[30][55][55];

int findArea(int k, char c)
{
    int heights[55] = { 0 };
    int stack[55];
    int top = 0;
    int can = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[k][i][j] == '0' || a[k][i][j] == c) heights[j + 1] ++;
            else heights[j + 1] = 0;
        top = 0; stack[top] = 0;
        for (int j = 1; j <= n + 1; j++)
        {
            while (heights[j] < heights[stack[top]])
            {
                int h = heights[stack[top]];
                top--; //pop
                if (h >= H && j - stack[top] - 1 >= W) return 1;
            }
            //push
            top++;
            stack[top] = j;
        }
    }
    return 0;
}

#define MAXN 100
#define inf (1<<30)
int ford(int c[][MAXN], int f[][MAXN],  int n, int s, int t)
{
    int i, j, m, x;
    int L[MAXN] = { 0 }, p[MAXN] = { 0 };
    L[s] = 1;
    while (1)
    {
        i = 1;
        while ((i <= n) && !((L[i] != 0) && (p[i] == 0))) i++;
        if (i > n) return 1;
        for (j = 1; j <= n; j++)
            if ((L[j] == 0) && ((c[i][j] > 0) || (c[j][i] > 0)))
            {
                if (f[i][j] < c[i][j]) L[j] = i;
                if (f[j][i] > 0) L[j] = -i;
            }
        p[i] = 1;
        if (L[t] != 0) break;
    }
    m = t;
    int minv = inf;
    while (m != s)
    {
        j = m; m = (int)abs(L[j]);
        if (L[j] < 0) x = f[j][m];
        if (L[j] > 0) x = c[m][j] - f[m][j];
        if (x < minv) minv = x;
    }

    m = t;
    while (m != s)
    {
        j = m; m = (int)abs(L[j]);
        if (L[j] < 0) f[j][m] = f[j][m] - minv;
        if (L[j] > 0) f[m][j] = f[m][j] + minv;
    }
    return 0;
}

int maxflow(int c[][MAXN], int n, int s, int t)
{
    int success = 0;
    int f[MAXN][MAXN] = { 0 };

    while (!success)
    {
        success = ford(c, f, n, s, t);
        if (success == 1)
        {
            int maxf = 0;
            for (int i = 1; i <= n; i++)
                maxf += f[i][t];
            return maxf;
        }
    }
    return 0;
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int k;
        scanf("%d %d %d %d %d", &k, &m, &n, &H, &W);
        for (int i = 0; i < k; i++)
            for (int j = 0; j < m; j++) scanf("%s", a[i][j]);
        int g[100][100] = { 0 };
        int flow[100][100] = { 0 };
        for (int i = 0; i < 26; i++)
        {
            g[1][i+2] = 1;
            for (int j = 0; j < k; j++)
                if (findArea(j, 'A' + i)) g[i + 2][29 + j] = 1;
        }
        g[1][28] = k;
        for (int j = 0; j < k; j++)
        {
            if (findArea(j, '0')) g[28][29 + j] = 1;
            g[29 + j][29 + k] = 1;
        }
        int res = maxflow(g, 29 + k, 1, 29 + k);
        printf("%d\n", res);
    }
    return 0;
}
