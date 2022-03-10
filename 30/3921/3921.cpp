#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;

#define INF 9999
struct MAP
{
    int c,f,w;
}map[120][120];
int s , t;//s = start point , t = end point
int v[120];
int pre[120]; // pre point in one road
int n , k;

int spfa()
{
    int flag[120] = {0};
    int cost[120];
    queue<int> q;
    memset(v,0,sizeof(v));
    memset(pre,0,sizeof(pre));
    for(int i = 1; i <= n; i ++) cost[i] = INF;
    v[s] = INF;
    pre[s] = s;
    cost[s] = 0;
    flag[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int i = q.front();
        for(int j = 1; j <= n; j ++)
        {
            if(map[i][j].f < map[i][j].c && cost[i] + map[i][j].w < cost[j] &&
                cost[i] + map[i][j].w <= k)
            {
                cost[j] = cost[i] + map[i][j].w;
                v[j] = min(v[i] , map[i][j].c - map[i][j].f);
                pre[j] = i;
                if(flag[j] == 0)
                {
                    flag[j] = 1;
                    q.push(j);
                }
            }
            else if(map[j][i].f && cost[i] - map[j][i].w < cost[j] &&
                cost[i] - map[j][i].w <= k)
            {
                cost[j] = cost[i] - map[j][i].w;
                v[j] = min(v[i] , map[j][i].f);
                pre[j] = -i;
                if(flag[j] == 0)
                {
                    flag[j] = 1;
                    q.push(j);
                }
            }
        }
        q.pop();
        flag[i] = 0;
    }
    return (v[t] > 0);
}

int mcmf()
{
    int maxflow = 0;
    while(spfa()) //while find a way
    {
        int j = t;
        maxflow += v[t];
        while(j != s)
        {
            int i = abs(pre[j]);
            if(pre[j] > 0)
            {
                map[i][j].f += v[t];
            }
            else
            {
                map[j][i].f -= v[t];
            }
            j = i;
        }
    }
    return maxflow;
}

int main()
{
    int m;
    //freopen("input.txt" , "r" , stdin);
    while (scanf("%d %d %d" , &n , &m , &k) == 3)
    {
        if (n == 0 && m == 0 && k == 0) break;
        memset(map , 0 , sizeof(map));
        for (int i = 2; i < n; i ++)
        {
            map[i*2-2][i*2-1].c = 1;
            map[i*2-2][i*2-1].w = 0;
        }
        for (int i = 0; i < m; i ++)
        {
            int x , y;
            scanf("%d %d" , &x , &y);
            map[2*x-1][2*y-2].c = INF;
            map[2*x-1][2*y-2].w = 1;
        }
        n = 2*n-2;
        s = 1; t = n;
        int res = mcmf();
        printf("%d\n" , res);
    }
    return 0;
}
