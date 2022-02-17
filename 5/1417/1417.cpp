#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
typedef struct
{
    int num[2];
    int id[2];
}Elm;
int f[601];
int op[601];
int dp[601][601];
int tot[601];

int getF(int x)
{
    if (f[x] == x) return x;
    f[x] = getF(f[x]);
    return f[x];
}
int merge(int x, int y)
{
    x = getF(x);
    y = getF(y);
    if (x == y || y == 0) return x;
    if (x == 0) return y;
    f[x] = y;
    tot[y] += tot[x];
    return y;
}
int main()
{
    //freopen("g1.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    int m, p1, p2;
    while (scanf("%d %d %d", &m, &p1, &p2) == 3)
    {
        if (m == 0 && p1 == 0 && p2 == 0) break;
        int n = p1 + p2;
        memset(op, 0, sizeof(op));
        for (int i = 1; i <= n; i++) {
            f[i] = i; tot[i] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            char s[4];
            scanf("%d %d %s", &x, &y, s);
            x = getF(x); y = getF(y);
            if (s[0] == 'y')
            {
                int yes = merge(x, y);
                int no = merge(op[x], op[y]);
                op[yes] = no;
                op[no] = yes;
            }
            else
            {
                op[x] = getF(op[x]);
                op[y] = getF(op[y]);
                if (op[x] == 0) op[x] = y;
                if (op[y] == 0) op[y] = x;
                int xx = merge(x, op[y]);
                int yy = merge(op[x], y);
                op[xx] = yy;
                op[yy] = xx;
            }
        }
        vector<Elm> a;
        int check[601] = { 0 };
        for (int i = 1; i <= n; i ++)
            if (check[getF(i)] == 0)
            {
                Elm t;
                int x = getF(i);
                check[x] = check[op[x]] = 1;
                t.id[0] = x; t.id[1] = op[x];
                t.num[0] = tot[x]; t.num[1] = tot[op[x]];
                a.push_back(t);
            }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j <= p1; j ++)
                if (dp[i][j])
                {
                    if (j + a[i].num[0] <= p1) dp[i+1][j + a[i].num[0]] += dp[i][j];
                    if (j + a[i].num[1] <= p1) dp[i+1][j + a[i].num[1]] += dp[i][j];
                }
        }
        if (dp[a.size()][p1] == 1)
        {
            vector<int> res;
            int k = p1;
            for (int i = a.size()-1; i >= 0; i--)
            {
                int id = 0;
                if (k - a[i].num[0] >= 0 && dp[i][k - a[i].num[0]])
                {
                    id = a[i].id[0]; k -= a[i].num[0];
                }
                else if (k - a[i].num[1] >= 0 && dp[i][k - a[i].num[1]])
                {
                    id = a[i].id[1]; k -= a[i].num[1];
                }
                if (id > 0)
                for (int j = 1; j <= n; j++)
                    if (getF(j) == id) res.push_back(j);
            }
            sort(res.begin(), res.end());
            for (int i = 0; i < res.size(); i++) printf("%d\n", res[i]);
            printf("end\n");
        }
        else printf("no\n");
    }
    return 0;
}
