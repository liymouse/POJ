#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define EPS (1e-7)

double cal(double x, double y, int t)
{
    if (t == 0) return x + y;
    else if (t == 1) return x - y;
    else if (t == 2) return x * y;
    else if (t == 3 && y != 0) return x / y;
    return 1e100;
}
int main()
{
    int a[5];
    while (scanf("%d", &a[0]) == 1)
    {
        if (a[0] == -1) break;
        scanf("%d %d %d %d", &a[1], &a[2], &a[3], &a[4]);
        int b[4];
        for (int i = 0; i < 4; i++) b[i] = a[i];
        sort(b, b + 4);
        int ok = 0;
        do
        {
            if (b[0] == 8 && b[1] == 3 && b[2] == 3 && b[3] == 8)
            {
                int a = 0;
                a++;
            }
            double res[4];
            for (int i = 0; i < 4; i++)
            {
                res[0] = cal(b[0], b[1], i);
                for (int j = 0; j < 4; j++)
                {
                    res[1] = cal(res[0], b[2], j);
                    res[2] = cal(b[2], res[0], j);
                    for (int k = 0; k < 4; k++)
                    {
                        res[3] = cal(res[1], b[3], k);
                        if (abs(res[3] -a[4]) < EPS) { ok = 1; goto L_exit; }
                        res[3] = cal(b[3], res[1], k);
                        if (abs(res[3] - a[4]) < EPS) { ok = 1; goto L_exit; }
                        res[3] = cal(res[2], b[3], k);
                        if (abs(res[3] - a[4]) < EPS) { ok = 1; goto L_exit; }
                        res[3] = cal(b[3], res[2], k);
                        if (abs(res[3] - a[4]) < EPS) { ok = 1; goto L_exit; }
                    }
                }

                for (int j = 0; j < 4; j++)
                {
                    res[1] = cal(b[2], b[3], j);
                    for (int k = 0; k < 4; k++)
                    {
                        res[3] = cal(res[0], res[1], k);
                        if (abs(res[3] - a[4]) < EPS) { ok = 1; goto L_exit; }
                        res[3] = cal(res[1], res[0], k);
                        if (abs(res[3] - a[4]) < EPS) { ok = 1; goto L_exit; }
                    }
                }
            }
        } while (next_permutation(b, b + 4));
    L_exit:
        for (int i = 0; i < 5; i++) printf("%d ", a[i]);
        if (ok) printf("OK!\n"); else printf("NO!\n");
    }
    return 0;
}