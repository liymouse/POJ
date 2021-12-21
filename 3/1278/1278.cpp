#include <stdio.h>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
typedef struct
{
    int d, pay;
}Plan;

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        int L[100];
        vector<Plan> a[100];
        for (int i = 0; i < n; i++) scanf("%d", &L[i]);
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int x, d, pay;
            scanf("%d %d %d", &x, &d, &pay);
            Plan p;
            p.d = d; p.pay = pay;
            a[x - 1].push_back(p);
        }
        int f[101];
        memset(f, 0xff, sizeof(f));
        f[0] = 0;
        for (int k = 0; k < n; k++)
        {
            for (int d = 100; d >= 0; d --)
                if (f[d] >= 0)
                {
                    for (int p = 0; p < a[k].size(); p++)
                        if (d + L[k] <= a[k][p].d)
                            f[d + L[k]] = max(f[d + L[k]], f[d] + a[k][p].pay);
                }
        }
        int res = 0;
        for (int i = 0; i <= 100; i++) res = max(res, f[i]);
        printf("%d\n\n", res);
    }
    return 0;
}
