#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
    int sx, sy, ex, ey;
}Rect;
Rect a[100];

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int w, h, n;
        scanf("%d %d", &w, &h);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d", &a[i].sx, &a[i].sy, &a[i].ex, &a[i].ey);
        }
        int is_cross = 0;
        int is_out = 0;
        for (int i = 0; i < n && is_cross==0; i ++)
            for (int j = i + 1; j < n; j ++)
                if (!(a[i].ex <= a[j].sx || a[i].sx >= a[j].ex || a[i].ey <= a[j].sy || a[i].sy >= a[j].ey))
                { 
                    is_cross = 1; break; 
                }
        if (is_cross == 0)
        {
            for (int i = 0; i < n; i++)
                if (a[i].sx < 0 || a[i].ex > w || a[i].sy < 0 || a[i].ey > h) { is_out = 1; break; }
            if (is_out == 0)
            {
                long long area = 0;
                for (int i = 0; i < n; i++)
                    area = area + (long long)(a[i].ex - a[i].sx) * (a[i].ey - a[i].sy);
                if (area == w * h) printf("OK\n");
                else printf("NONCOVERING\n");
            }
            else printf("NONCONTAINED\n");
        }
        else printf("NONDISJOINT\n");
    }
    return 0;
}