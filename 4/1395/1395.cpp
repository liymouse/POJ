#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int x, int y)
{
    while (y)
    {
        int r = x % y;
        x = y; y = r;
    }
    return x;
}

#define MAX 10000
char f[MAX+1];

int main()
{
    int cas;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        int n;
        scanf("%d", &n);
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) a[i] /= a[0];
        a[0] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < i; j++)
                if (a[i] % a[j] == 0) a.push_back(a[i] / a[j]);
        n = a.size();
        memset(f, 0, sizeof(f));
        f[1] = 1;
        if (n > 1)
        {
            for (int i = 1; i <= MAX/a[1]; i++)
                if (f[i])
                {
                    for (int j = 1; j < n; j++)
                        if (i * a[j] <= MAX) f[i*a[j]] = 1;
                        else break;
                }
        }
        int m;
        scanf("%d", &m);
        printf("Scenario #%d:\n", ca);
        for (int i = 0; i < m; i++)
        {
            int A, B;
            scanf("%d %d", &A, &B);
            int k = gcd(A, B);
            A /= k; B /= k;
            int ok = 0;
            for (int x = A, y = B; x <= MAX && y <= MAX; x += A, y += B) if (f[x] && f[y]) { ok = 1; break; }
            printf("Gear ratio %d:%d %s be realized.\n", A*k, B*k, (ok?"can":"cannot"));
        }
        printf("\n");
    }
    return 0;
}
