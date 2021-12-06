#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct
{
    int sx, sy, ex, ey;
}Rect;

int getFather(int *f, int x)
{
    if (x == f[x]) return x;
    f[x] = getFather(f, f[x]);
    return f[x];
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int k, p;
        Rect a[26];
        int hori[26], vert[26];
        scanf("%d %d", &k, &p);
        for (int i = 0; i < k; i++)
        {
            a[i].sx = a[i].sy = 2000000;
            a[i].ex = a[i].ey = -1;
            hori[i] = i;
            vert[i] = i;
            int x, y;
            for (int j = 0; j < p; j++)
            {
                scanf("%d %d", &x, &y);
                a[i].sx = min(a[i].sx, x);
                a[i].sy = min(a[i].sy, y);
                a[i].ex = max(a[i].ex, x);
                a[i].ey = max(a[i].ey, y);
            }
        }
        for (int i = 0; i < k; i++)
            for (int j = i+1; j < k; j ++)
            {
                if (!(a[i].ex < a[j].sx || a[i].sx > a[j].ex))
                {
                    hori[getFather(hori, i)] = getFather(hori, j);
                }
                if (!(a[i].ey < a[j].sy || a[i].sy > a[j].ey))
                {
                    vert[getFather(vert, i)] = getFather(vert, j);
                }
            }
        int ok = 1;
        for (int i = 0; i < k && ok; i ++)
            for (int j = i + 1; j < k; j ++)
                if (getFather(hori, i) == getFather(hori, j) && getFather(vert, i) == getFather(vert, j))
                {
                    ok = 0; break;
                }
        if (ok) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}