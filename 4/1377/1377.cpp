#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define abs(a) ((a)>0?(a):-(a))

int gcd(int x, int y)
{
    while (y)
    {
        int r = x % y;
        x = y; y = r;
    }
    return x;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int p, q;
        scanf("%d %d", &p, &q);
        int minv = -1;
        int res = 0;
        int pa = p/q, pb = 1;
        for (int b = 1; b <= q; b++)
        {
            //down
            int a = pa * b / pb;
            while (gcd(a, b) != 1) a++;
            int v = abs(a * q - b * p);
            int num = 0;
            int x, y;
            if (minv == -1 || v < minv)
            {
                minv = v;
                num = 1;
                x = a; y = b;
            }
            else if (num >= 1 && v == minv) num++;
            for (int aa = a - 1; aa >= 0; aa--)
            {
                if (gcd(aa, b) != 1) continue;
                int v0 = abs(aa * q - b * p);
                if (v0 > v) break;
                if (minv == -1 || v0 < minv)
                {
                    minv = v0;
                    num = 1;
                    x = aa; y = b;
                }
                else if (num >= 1 && v0 == minv) num++;
            }
            for (int aa = a + 1; ; aa++)
            {
                if (gcd(aa, b) != 1) continue;
                int v0 = abs(aa * q - b * p);
                if (v0 > v) break;
                if (minv == -1 || v0 < minv)
                {
                    minv = v0;
                    num = 1;
                    x = aa; y = b;
                }
                else if (num >= 1 && v0 == minv) num++;
            }
            if (num == 1)
            {
                res++;
                pa = x; pb = y;
                //printf("%d %d\n", x, y);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
