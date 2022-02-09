#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

int a[2005][2005];

int Prim(int n)
{
    int mark[2005] = { 0 }, dist[2005];
    int i, j, k, min, tot;

    memset(dist, 0xff, sizeof(dist));
    dist[0] = 0;
    for (i = 0; i < n; i++)
    {
        min = 1<<30; k = -1;
        for (j = 0; j < n; j++)
            if (mark[j] == 0 && dist[j] != -1 && dist[j] < min) { min = dist[j]; k = j; }
        if (k == -1) break;
        mark[k] = 1;
        for (j = 0; j < n; j++)
            if (mark[j] == 0 && a[k][j] > 0 && (a[k][j] < dist[j] || dist[j] == -1))
            {
                dist[j] = a[k][j];
            }
    }
    tot = 0;
    for (i = 0; i < n; i++) tot += dist[i];
    return tot;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        char s[2005][10];
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        int res = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
            {
                a[i][j] = 0;
                for (int k = 0; k < 7; k++) if (s[i][k] != s[j][k]) a[i][j] ++;
                a[j][i] = a[i][j];
            }
        printf("The highest possible quality is 1/%d.\n", Prim(n));
    }
    return 0;
}