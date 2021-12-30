#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int dist[30] = { 0 };

int cmp(int x, int y)
{
    return dist[x] < dist[y];
}

int main()
{
    int a[30][30];
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[j][i]);
    int s;
    scanf("%d", &s);
    int mark[30] = { 0 }, path[30] = { 0 };
    mark[s] = 1; path[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = a[s][i];
        if (dist[i] > 0) path[i] = s;
    }
    for (int i = 1; i <= n; i++)
    {
        int minv = 1<<30;
        int k = -1;
        for (int j = 1; j <= n; j ++)
            if (mark[j] == 0 && dist[j] >= 0 && dist[j] < minv)
            {
                k = j; minv = dist[j];
            }
        if (k == -1) break;
        mark[k] = 1;
        for (int j = 1; j <= n; j ++)
            if (mark[j] == 0 && a[k][j] >= 0 && ((dist[j] == -1) || (dist[k] + a[k][j] < dist[j])))
            {
                dist[j] = dist[k] + a[k][j];
                path[j] = k;
            }
    }
    int st[30] = { 0 };
    int st_num = 0;
    while (scanf("%d", &st[st_num]) == 1) st_num++;
    sort(st, st + st_num, cmp);
    printf("Org\tDest\tTime\tPath\n");
    for (int i = 0; i < st_num; i ++)
    {
        int road[30] = { 0 };
        int k = st[i];
        int num = 0;
        while (k > 0)
        {
            road[num++] = k;
            k = path[k];
        }
        printf("%d\t%d\t%d", st[i], s, dist[st[i]]);
        for (int j = 0; j < num; j++) printf("\t%d", road[j]);
        printf("\n");
    }
    return 0;
}