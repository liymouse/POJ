#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int m, L;
    while (scanf("%d %d", &m, &L) == 2)
    {
        if (m == 0 && L == 0) break;
        int n;
        int c[2001];
        scanf("%d", &n);
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &c[i]);
            sum += c[i];
        }
        int f[1001] = { 1 };
        int p[1001] = { 0 };
        for (int i = 1; i <= n; i++)
        {
            for (int k = m; k >= c[i]; k --)
                if (f[k - c[i]])
                {
                    f[k] = 1;
                    if (p[k] == 0) p[k] = i;
                }
        }
        int k = m;
        for (int i = m; i >= 0; i --)
            if (f[i]) { k = i; break; }
        if (sum - k <= L)
        {
            vector<int> a;
            while (k)
            {
                a.push_back(p[k]);
                k = k - c[p[k]];
            }
            printf("%d", a.size());
            for (int i = a.size() - 1; i >= 0; i--) printf(" %d", a[i]);
            printf("\n");
        }
        else printf("Impossible to distribute\n");
    }
    return 0;
}