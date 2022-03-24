#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long lld;
int f[100];
int getF(int x)
{
    if (f[x] == x) return x;
    f[x] = getF(f[x]);
    return f[x];
}
lld exgcd(lld a, lld b, lld &x, lld &y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    lld r = exgcd(b, a%b, x, y);
    lld t = x;
    x = y;
    y = t - (a / b) * y;
    return r;
}
int canChange(int x1, int y1, int x2, int y2, int n)
{
    lld a, b;
    lld r = exgcd(x1, -x2, a, b);
    lld k = y2 - y1;
    if (k % r != 0) return 0;
    a = a * k / r;
    b = b * k / r;
    lld k1 = a >= 0 ? 0 : (-a + x2 - 1) / x2;
    lld k2 = a >= 0 ? 0 : (-a + x2 - 1) / x2;
    a += max(k1, k2) * x2;
    b += max(k1, k2) * x1;
    if ((lld)y1 + a*x1 < n && (lld)y2 + b * x2 < n) return 1;
    return 0;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca --)
    {
        int floor, e, a, b;
        int x[100], y[100];
        scanf("%d %d %d %d", &floor, &e, &a, &b);
        for (int i = 0; i < e; i++) scanf("%d %d", &x[i], &y[i]);
        if (a == b) { printf("It is possible to move the furniture.\n"); continue; }

        vector<int> A, B;
        for (int i = 0; i < e; i ++)
        {
            if (a >= y[i] && (a - y[i]) % x[i] == 0) A.push_back(i);
            if (b >= y[i] && (b - y[i]) % x[i] == 0) B.push_back(i);
            f[i] = i;
        }
        if (A.size() == 0 || B.size() == 0) { printf("The furniture cannot be moved.\n"); continue; }
        for (int i = 0; i < e; i ++)
            for (int j = i + 1; j < e; j ++)
                if (getF(i) != getF(j) && canChange(x[i], y[i], x[j], y[j], floor))
                {
                    int p = getF(i);
                    int q = getF(j);
                    f[p] = q;
                }
        int canMove = 0;
        for (int i = 0; i < A.size() && canMove == 0; i ++)
            for (int j = 0; j < B.size() && canMove == 0; j ++)
                if (getF(A[i]) == getF(B[i])) { canMove = 1; break; }
        if (canMove) printf("It is possible to move the furniture.\n");
        else printf("The furniture cannot be moved.\n");
    }
    return 0;
}
