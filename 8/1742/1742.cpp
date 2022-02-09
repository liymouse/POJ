#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
int use[100001];
char can[100001];
int main()
{
    int n, m;
    int a[100], c[100];
    while(scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &c[i]);
        memset(can, 0, sizeof(can));
        can[0] = 1;
        int res = 0;
        int maxv = 0;
        for (int i = 0; i < n; i++)
        {
            memset(use, 0, sizeof(use));
            maxv = min(maxv + a[i] * c[i], m);
            for (int j = a[i]; j <= maxv; j ++)
                if (can[j] == 0 && can[j - a[i]] && use[j - a[i]] < c[i])
                {
                    can[j] = 1;
                    use[j] = use[j - a[i]] + 1;
                    res++;
                }
        }
        printf("%d\n", res);
    }
    return 0;
}