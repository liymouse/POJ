#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef unsigned long long ulld;
typedef struct
{
    ulld a[55];
}Po;
int n;

//ret = x * y
Po mul(Po &x, Po &y)
{
    Po res = { 0 };
    for (int i = 0; i <= n; i ++)
        if (x.a[i])
        {
            for (int j = 0; j <= n; j ++)
                if (y.a[j])
                {
                    res.a[i + j] += x.a[i] * y.a[j];
                }
        }
    return res;
}
int main()
{
    int m, ca = 1;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0) break;
        int num[55] = { 0 };
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            num[x] ++;
        }
        vector<Po> a;
        for (int i = 1; i <= n; i++)
            if (num[i] > 0)
            {
                Po x;
                memset(x.a, 0, sizeof(x.a));
                for (int j = 0; j <= num[i]; j++) x.a[j] = 1;
                a.push_back(x);
            }
        Po res = a[0];
        for (int i = 1; i < a.size(); i++)
            res = mul(res, a[i]);
        printf("Case %d:\n", ca++);
        for (int i = 0; i < m; i++)
        {
            int x;
            scanf("%d", &x);
            printf("%llu\n", res.a[x]);
        }
    }
    return 0;
}