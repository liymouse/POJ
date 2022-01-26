#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define EPS (1e-7)

int bad;
double cal(double x, double y, int t)
{
    if (t == 0) return x + y;
    else if (t == 1) return x - y;
    else if (t == 2) return x * y;
    else if (t == 3 && fabs(y) > EPS) return x / y;
    bad = 1;
    return 1e100;
}
int main()
{
    int a[5];
    while (scanf("%d", &a[0]) == 1)
    {
        if (a[0] == -1) break;
        scanf("%d %d %d %d", &a[1], &a[2], &a[3], &a[4]);
        double b[4];
        for (int i = 0; i < 4; i++) b[i] = a[i];
        sort(b, b + 4);
        int ok = 0;
        do
        {
            double res;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    for (int k = 0; k < 4; k++)
                    {
                        // i -> j -> k
                        bad = 0;
                        res = cal(cal(cal(b[0], b[1], i), b[2], j), b[3], k);
                        if (bad == 0 && fabs(res - a[4]) < EPS) { ok = 1; goto L_exit; }
                        // i -> k -> j
                        bad = 0;
                        res = cal(cal(b[0], b[1], i), cal(b[2], b[3], k), j);
                        if (bad == 0 && fabs(res - a[4]) < EPS) { ok = 1; goto L_exit; }
                        // j -> i -> k
                        bad = 0;
                        res = cal(cal(b[0], cal(b[1], b[2], j), i), b[3], k);
                        if (bad == 0 && fabs(res - a[4]) < EPS) { ok = 1; goto L_exit; }
                        // j -> k -> i
                        bad = 0;
                        res = cal(b[0], cal(cal(b[1], b[2], j), b[3], k), i);
                        if (bad == 0 && fabs(res - a[4]) < EPS) { ok = 1; goto L_exit; }
                        // k -> i -> j (same as i -> k -> j)
                        //bad = 0;
                        //res = cal(cal(b[0], b[1], i), cal(b[2], b[3], k), j);
                        //if (bad == 0 && fabs(res - a[4]) < EPS) { ok = 1; goto L_exit; }
                        // k -> j -> i
                        bad = 0;
                        res = cal(b[0], cal(b[1], cal(b[2], b[3], k), j), i);
                        if (bad == 0 && fabs(res - a[4]) < EPS) { ok = 1; goto L_exit; }
                    }
        } while (next_permutation(b, b + 4));
    L_exit:
        for (int i = 0; i < 5; i++) printf("%d ", a[i]);
        if (ok) printf("OK!\n"); else printf("NO!\n");
    }
    return 0;
}