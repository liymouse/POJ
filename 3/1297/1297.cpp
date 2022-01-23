#include <stdio.h>
#include <vector>
using namespace std;
typedef struct
{
    int id;
    double c;
}Product;
int m, n;

int buy[100];
vector<int> id[100];
Product a[100000];
double f[2][100001];

int main()
{
    while (scanf("%d %d", &m, &n) == 2)
    {
        if (m == 0 && n == 0) break;
        for (int i = 0; i < m; i++) scanf("%d", &buy[i]);
        for (int i = 0; i < n; i++) scanf("%d %lf", &a[i].id, &a[i].c);
        for (int i = 0; i < m; i++)
        {
            id[i].clear();
            for (int j = 0; j < n; j++)
                if (buy[i] == a[j].id) id[i].push_back(j);
        }
        for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) f[i][j] = -1;
        int p = 0;
        for (int i = 0; i < id[0].size(); i++) f[p][id[0][i]] = a[id[0][i]].c;
        for (int i = 1; i < m; i++)
        {
            if (i > 1) for (int j = 0; j < id[i - 2].size(); j++) f[1 - p][id[i - 2][j]] = -1;
            for (int j = 0; j < id[i].size(); j++)
            {
                double minv = 1e100;
                for (int k = 0; k < id[i - 1].size(); k++)
                    if (id[i - 1][k] < id[i][j])
                    {
                        if (f[p][id[i - 1][k]] >= 0 && f[p][id[i - 1][k]] < minv)
                            minv = f[p][id[i - 1][k]];
                    }
                    else break;
                    if (minv < 1e99)
                    {
                        f[1 - p][id[i][j]] = minv + a[id[i][j]].c;
                    }
            }
            p = 1 - p;
        }
        double res = 1e100;
        for (int i = 0; i < id[m - 1].size(); i++)
            if (f[p][id[m - 1][i]] >= 0 && f[p][id[m - 1][i]] < res)
                res = f[p][id[m - 1][i]];
        if (res < 1e99) printf("%.2lf\n", res);
        else printf("Impossible\n");
    }
    return 0;
}