#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef struct
{
    int vec;
    int cost;
}Edge;
#define MAXN 5003
vector<Edge> G[MAXN];
int dist[MAXN];
int dist2[MAXN];

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    for (int i = 0; i < r; i++)
    {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        Edge a;
        a.vec = y;
        a.cost = c;
        G[x].push_back(a);
        a.vec = x;
        G[y].push_back(a);
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1 << 30;
        dist2[i] = 1 << 30;
    }
    dist[1] = 0;
    que.push(make_pair(1, 0));
    while (!que.empty())
    {
        pair<int, int> p = que.top();
        que.pop();
        int v = p.first, d = p.second;
        if (dist2[v] < d) continue;
        for (int i = 0; i < G[v].size(); i++)
        {
            Edge &e = G[v][i];
            int d2 = d + e.cost;
            if (dist[e.vec] > d2)
            {
                swap(dist[e.vec], d2);
                que.push(make_pair(e.vec, dist[e.vec]));
            }
            if (dist2[e.vec] > d2 && dist[e.vec] < d2)
            {
                dist2[e.vec] = d2;
                que.push(make_pair(e.vec, dist2[e.vec]));
            }
        }
    }
    printf("%d\n", dist2[n]);
    return 0;
}