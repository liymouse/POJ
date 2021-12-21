#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX (1<<30)

int main()
{
    int n, m;
    int a[101][101] = { 0 }, dist[101] = { 0 }, mark[101] = { 0 }, v[101], d[101];
    set<int> level_set;

    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = -1;
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d %d %d", &v[i], &d[i], &k);
        for (int j = 0; j < k; j++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            a[i][x] = y;
        }
        level_set.insert(d[i]);
    }
    vector<int> level;
    for (set<int>::iterator it = level_set.begin(); it != level_set.end(); it++)
    {
        level.push_back(*it);
    }
    int res = MAX;
    for (int t = 0; t < level.size(); t ++)
        if (d[1] - level[t] <= m && level[t] <= d[1])
        {
            for (int i = 1; i <= n; i++) dist[i] = MAX;
            memset(mark, 0, sizeof(mark));
            dist[1] = 0;
            for (int i = 2; i <= n; i++)
                if (a[1][i] > 0 && level[t] <= d[i] && d[i] <= level[t] + m) dist[i] = a[1][i];
            mark[1] = 1;
            for (int i = 2; i <= n; i++)
            {
                int mindist = MAX, k = -1;
                for (int j = 2; j <= n; j++)
                    if (mark[j] == 0 && dist[j] < mindist) { mindist = dist[j]; k = j; }
                if (k == -1) break;
                mark[k] = 1;
                for (int j = 2; j <= n; j++)
                    if (mark[j] == 0 && a[k][j] >= 0 && dist[k] + a[k][j] < dist[j] && level[t] <= d[j] && d[j] <= level[t] + m)
                    {
                        dist[j] = dist[k] + a[k][j];
                    }
            }
            for (int i = 1; i <= n; i++)
                if (dist[i] + v[i] < res) res = dist[i] + v[i];
        }
        else if (level[t] > d[1]) break;
    printf("%d\n", res);
    return 0;
}