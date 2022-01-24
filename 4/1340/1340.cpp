#include <stdio.h>
#include <sstream>
using namespace std;
int n;
int a[100][100], dist[100];

void dijkstra(int s)
{
    int mark[100] = { 0 };
    memset(dist, 0xff, sizeof(dist));
    for (int i = 0; i < n; i++)
        if (a[s][i]) dist[i] = a[s][i];
    mark[s] = 1;
    for (int i = 0; i < n; i++)
    {
        int minv = 1 << 30;
        int k = -1;
        for (int j = 0; j < n; j ++)
            if (mark[j] == 0 && dist[j] != -1 && dist[j] < minv)
            {
                minv = dist[j]; k = j;
            }
        if (k == -1) break;
        mark[k] = 1;
        for (int j = 0; j < n; j ++)
            if (mark[j] == 0 && a[k][j] && (dist[j] == -1 || dist[k] + a[k][j] < dist[j]))
            {
                dist[j] = dist[k] + a[k][j];
            }
    }
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int org[100][100];
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &org[i][j]);
        char s[1024];
        gets_s(s);
        gets_s(s);
        stringstream ss(s);
        int path[100], pn = 0;
        while (ss >> path[pn]) {
            path[pn]--; pn++;
        }
        int oldL[100];
        int res = 0;
        memcpy(a, org, sizeof(a));
        dijkstra(path[pn-1]);
        memcpy(oldL, dist, sizeof(oldL));
        for (int i = 0; i < pn - 1; i++)
        {
            memcpy(a, org, sizeof(a));
            a[path[i]][path[i + 1]] = a[path[i + 1]][path[i]] = 0;
            dijkstra(path[pn - 1]);
            if (dist[path[i]] - oldL[path[i]] > res) res = dist[path[i]] - oldL[path[i]];
        }
        printf("%d\n", res);
    }
}