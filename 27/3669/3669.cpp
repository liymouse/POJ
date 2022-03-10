#include <stdio.h>
#include <queue>
using namespace std;

int g[305][305];
#define MAX 1000000
typedef struct {
    int x, y, t;
}node;

int main()
{
    int m;
    int d[4][2] = { { -1, 0 }, {0 , 1} , {1 ,0} , {0 ,-1} };
    for (int i = 0; i < 305; i++) for (int j = 0; j < 305; j++) g[i][j] = MAX;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);
        g[x][y] = min(g[x][y], t);
        for (int j = 0; j < 4; j ++)
            if (x + d[j][0] >= 0 && y + d[j][1] >= 0)
            {
                g[x + d[j][0]][y + d[j][1]] = min(g[x + d[j][0]][y + d[j][1]], t);
            }
    }
    int res = -1;
    if (g[0][0] > 0)
    {
        queue<node> qu;
        node a;
        a.x = 0; a.y = 0; a.t = 0;
        g[0][0] = -1;
        qu.push(a);
        
        while (!qu.empty())
        {
            node a = qu.front();
            qu.pop();
            if (g[a.x][a.y] == MAX) { res = a.t; break; }
            for (int i = 0; i < 4; i++)
            {
                if (a.x + d[i][0] >= 0 && a.y + d[i][1] >= 0 &&
                    g[a.x + d[i][0]][a.y + d[i][1]] > a.t+1)
                {
                    node b;
                    b.x = a.x + d[i][0];
                    b.y = a.y + d[i][1];
                    b.t = a.t + 1;
                    if (g[b.x][b.y] != MAX) g[b.x][b.y] = -1;
                    qu.push(b);
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}