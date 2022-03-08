#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int f[1001][11];
int main()
{
    int n, k;
    int ca = 1;
    while (scanf("%d %d", &n, &k) == 2)
    {
        if (n == 0 && k == 0) break;
        vector<int> a[11][11];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j ++)
                if (j != i)
                {
                    int m, x;
                    scanf("%d", &m);
                    for (int k = 0; k < m; k++)
                    {
                        scanf("%d", &x);
                        a[i][j].push_back(x);
                    }
                }
        }
        memset(f, 0xff, sizeof(f));
        f[0][1] = 0;
        for (int t = 1; t <= k; t++)
            for (int i = 1; i <= n; i ++)
                if (f[t-1][i] >= 0)
                {
                    for (int j = 1; j <= n; j ++)
                        if (j != i && a[i][j][(t-1) % a[i][j].size()] > 0)
                        {
                            if (f[t][j] == -1 || f[t - 1][i] + a[i][j][(t - 1) % a[i][j].size()] < f[t][j])
                                f[t][j] = f[t - 1][i] + a[i][j][(t - 1) % a[i][j].size()];
                        }
                }
        printf("Scenario #%d\n", ca++);
        if (f[k][n] >= 0) printf("The best flight costs %d.\n", f[k][n]);
        else printf("No flight possible.\n");
        printf("\n");
    }
    return 0;
}
