#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

int main()
{
    int n;
    int sx, sy, sz;
    int ex, ey, ez;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        int x, y, z, a;
        scanf("%d %d %d %d", &sx, &sy, &sz, &a);
        ex = sx + a;
        ey = sy + a;
        ez = sz + a;
        for (int i = 1; i < n; i++)
        {
            scanf("%d %d %d %d", &x, &y, &z, &a);
            sx = max(sx, x);
            sy = max(sy, y);
            sz = max(sz, z);
            ex = min(ex, x + a);
            ey = min(ey, y + a);
            ez = min(ez, z + a);
        }
        if (ex > sx && ey > sy && ez > sz)
            printf("%d\n", (ex - sx)*(ey - sy)*(ez - sz));
        else
            printf("0\n");
    }
    return 0;
}