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
char check[501][501] = { 0 }; //0=not start, 1=start, 2=finish

int main()
{
    int n, m;
    int ca = 1;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) break;
        int mark[501] = { 0 };
        memset(check, 0, sizeof(check));
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; i++)
        {
            int x, y, t;
            scanf("%d %d %d", &x, &y, &t);
            a[x][y] = a[y][x] = t;
        }
        vector<Bian> process;
        for (int i = 2; i <= n; i ++)
            if (a[1][i] > 0)
            {
                Bian x;
                x.a = 1; x.b = i;
                process.push_back(x);
                check[1][i] = check[i][1] = 1;
            }
        mark[1] = 2;
        double res = 0;
        int last[2] = { 1 };
        while (process.size() > 0)
        {
            double mint = 1e100;
            for (int i = 0; i < process.size(); i ++)
                if (a[process[i].a][process[i].b] > 0 && a[process[i].a][process[i].b] < mint)
                { 
                    mint = a[process[i].a][process[i].b];
                }
            if (mint == 0) break;
            res += mint;
            //pass mint time
            vector<int> start;
            last[0] = last[1] = 0;
            for (int i = process.size() - 1; i >= 0; i--)
            {
                int s = process[i].a;
                int t = process[i].b;
                a[s][t] -= mint;
                a[t][s] -= mint;
                if (a[s][t] == 0) //finished this edge
                {
                    if (mark[t] == 0) //if point t is not start
                    {
                        start.push_back(t);
                        mark[t] = 1;
                        last[0] = t;
                    }
                    else if (mark[t] == 2)//t already started
                    {
                        last[0] = s; last[1] = t;
                    }
                    //this edge finished & remove it
                    check[s][t] = check[t][s] = 2;
                    process.erase(process.begin() + i);
                }
            }
            //add new edge from start point
            for (int i = 0; i < start.size(); i++)
            {
                for (int j = 1; j <= n; j ++)
                    if (a[start[i]][j] > 0 && check[start[i]][j] < 2)
                    {
                        //not start
                        if (check[start[i]][j] == 0)
                        {
                            Bian x;
                            x.a = start[i];
                            x.b = j;
                            process.push_back(x);
                            check[start[i]][j] = check[j][start[i]] = 1;
                        }
                        else
                        {
                            a[start[i]][j] /= 2.0;
                            a[j][start[i]] /= 2.0;
                        }
                    }
                mark[start[i]] = 2;
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