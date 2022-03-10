#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int a[100][100];
int to[100] , n , point[100];
int S;
map<int , int> index;
#define INF 0x7fffffff
typedef long long i64d;

int calDist(int be , int end)
{
    int step = 0;
    if (be >= end) return INF;
    while (be < end)
    {
        int have = 0;
        for (int i = 0; i < n; i ++)
            if (to[i] && be < point[i] && point[i] < end)
            {
                have = 1;
                int st = (point[i] - be) / S - ((point[i]-be) % S == 0);
                step += st;
                be += st * S;
                int j = min(end , be + S);
                while (j > point[i])
                {
                    if (j == end || index.find(j) == index.end()) break;
                    if (to[index[j]] == 0) break;
                    j --;
                }
                if (j == point[i])
                {
                    if (be == point[i] - 1) return INF;
                    be = point[i] - 1;
                    step ++;
                    break;
                }
                else be = j;
                step ++;
            }
        if (have == 0)
        {
            step += (end - be) / S + ((end-be) % S != 0);
            break;
        }
    }
    return step;
}

int main()
{
    int w , p;
    //freopen("in.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    while (scanf("%d" , &w) == 1 , w != 0)
    {
        scanf("%d %d" , &S , &p);
        index.clear();
        for (int i = 0; i < 100; i ++) for (int j = 0; j < 100; j ++) a[i][j] = INF;
        memset(point , 0 , sizeof(point));
        memset(to , 0 , sizeof(to));
        n = 1;
        index[0] = 0;
        for (int i = 0; i < p; i ++)
        {
            int x , y;
            scanf("%d %d" , &x , &y);
            int s , t;
            if (index.find(x) == index.end())
            {
                index[x] = n;
                s = n;
                point[n] = x;
                n ++;
            }
            else s = index[x];
            if (index.find(y) == index.end())
            {
                index[y] = n;
                t = n;
                point[n] = y;
                n ++;
            }
            else t = index[y];
            a[s][t] = 0;
            to[s] = t;
        }
        point[n] = w;
        n ++;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                if (point[i] < point[j] && to[i] == 0)
                {
                    int d = calDist(point[i] , point[j]);
                    if (to[j] != 0)
                    {
                        int d1 = calDist(point[i] , point[to[j]]);
                        a[i][to[j]] = min(d , d1);
                        a[i][j] = INF;
                    }
                    else a[i][j] = min(a[i][j] , d);
                }
        for (int k = 0; k < n; k ++)
            for (int i = 0; i < n; i ++)
                for (int j = 0; j < n; j ++)
                    if (a[i][k] < INF && a[k][j] < INF)
                        a[i][j] = min((i64d)a[i][j] , (i64d)a[i][k] + a[k][j]);
        printf("%d\n" , a[0][n-1]);
    }
    return 0;
}
