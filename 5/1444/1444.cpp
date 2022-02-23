#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define min(a,b) ((a)<(b)?(a):(b))
int res;

void swap(int &a, int &b) { int t = a; a = b; b = t; }
void find(int i, int j, int x0, int y0, int x, int y, int z, int L, int W, int H)
{
    if (z == 0) res = min((x0 - x) * (x0 - x) + (y0 - y) * (y0 - y), res);
    else
    {
        if (i >= 0 && i < 2)
            find(i + 1, j, x0, y0 - W, x, z, W - y, L, H, W);
        if (i <= 0 && i > -2)
            find(i - 1, j, x0, y0 + H, x, H - z, y, L, H, W);
        if (j >= 0 && j < 2)
            find(i, j + 1, x0 - L, y0, z, y, L - x, H, W, L);
        if (j <= 0 && j > -2)
            find(i, j - 1, x0 + H, y0, H - z, y, x, H, W, L);
    }
}

int main()
{
    int L, W, H, x1, y1, z1, x2, y2, z2;
    scanf("%d %d %d %d %d %d %d %d %d", &L, &W, &H, &x1, &y1, &z1, &x2, &y2, &z2);
    if (z1 != 0 && z1 != H)
    {
        if (y1 != 0 && y1 != W) { swap(x1, z1); swap(x2, z2); swap(L, H); }
        else { swap(y1, z1); swap(y2, z2); swap(W, H); }
    }
    if (z1 == H) { z1 = 0; z2 = H - z2; }
    res = 1 << 30;
    find(0, 0, x1, y1, x2, y2, z2, L, W, H);
    printf("%d\n", res);
    return 0;
}
