#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int L[2] = { 0 }, num[2] = { 0 };
    int cur, pre, n = 1, tmpL = 0, d = -1;
    while (scanf("%d", &pre) == 1)
    {
        if (pre == 0) break;
        while (scanf("%d", &cur) == 1)
        {
            if (cur == 0) break;
            n++;
            if (d == 0)
            {
                if (cur >= pre) L[0]++;
                else
                {
                    num[1] ++; d = 1; L[1] ++;
                }
            }
            else if (d == 1)
            {
                if (cur <= pre) L[1] ++;
                else
                {
                    num[0] ++; d = 0; L[0] ++;
                }
            }
            else
            {
                if (cur == pre) tmpL++;
                else
                {
                    d = cur < pre;
                    num[d] ++;
                    L[d] = tmpL + 1;
                }
            }
            pre = cur;
        }
        printf("Nr values = %d:  %.6lf %.6lf\n", n, num[0] ? (double)L[0] / num[0] : 0.0, num[1] ? (double)L[1] / num[1] : 0.0);
        n = 1; d = -1;
        L[0] = L[1] = num[0] = num[1] = tmpL = 0;
    }
    return 0;
}
