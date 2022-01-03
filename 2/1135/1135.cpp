#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct
{
    int a, b;
}Bian;
double a[501][501] = { 0 };
char check[501][501] = { 0 }; //0=not start, 1=has

int main()
{
    int n, m;
    int ca = 1;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) break;
        int mark[501] = { 0 };
        memset(check, 0, sizeof(check));
        for (int i = 0; i < m; i++)
        {
            int x, y, t;
            scanf("%d %d %d", &x, &y, &t);
            a[x][y] = a[y][x] = t;
        }
        vector<Bian> qu;
        for (int i = 2; i <= n; i ++)
            if (a[1][i])
            {
                Bian x;
                x.a = 1; x.b = i;
                qu.push_back(x);
                check[1][i] = check[i][1] = 1;
            }
        mark[1] = 1;
        double res = 0;
        int last[2] = { 1 };
        while (qu.size() > 0)
        {
            double mint = 1e100;
            for (int i = 0; i < qu.size(); i ++)
                if (a[qu[i].a][qu[i].b] < mint)
                { 
                    mint = a[qu[i].a][qu[i].b];
                }
            res += mint;
            //pass mint
            vector<int> start;
            last[0] = last[1] = 0;
            for (int i = qu.size() - 1; i >= 0; i--)
            {
                a[qu[i].a][qu[i].b] -= mint;
                a[qu[i].b][qu[i].a] -= mint;
                if (a[qu[i].a][qu[i].b] == 0)
                {
                    if (mark[qu[i].b] == 0)
                    {
                        start.push_back(qu[i].b);
                        mark[qu[i].b] = 1;
                        last[0] = qu[i].b;
                    }
                    else
                    {
                        last[0] = qu[i].a; last[1] = qu[i].b;
                    }
                    check[qu[i].a][qu[i].b] = check[qu[i].b][qu[i].a] = 2;
                    qu.erase(qu.begin() + i);
                }
            }
            for (int i = 0; i < start.size(); i++)
            {
                for (int j = 1; j <= n; j ++)
                    if (a[start[i]][j])
                    {
                        //not start
                        if (check[start[i]][j] == 0)
                        {
                            Bian x;
                            x.a = start[i];
                            x.b = j;
                            qu.push_back(x);
                            check[start[i]][j] = check[j][start[i]] = 1;
                        }
                        else if (check[start[i]][j] == 1) //start
                        {
                            a[start[i]][j] /= 2.0;
                            a[j][start[i]] /= 2.0;
                        }
                    }
            }
        }
        printf("System #%d\n", ca++);
        printf("The last domino falls after %.1lf seconds, ", res);
        if (last[1] == 0) printf("at key domino %d.\n", last[0]);
        else printf("between key dominoes %d and %d.\n", min(last[0], last[1]), max(last[0], last[1]));
        printf("\n");
    }
    return 0;
}