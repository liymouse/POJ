#include <stdio.h>
#include <string.h>
typedef long long lld;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
lld getMax(int x, int y);
lld getMin(int x, int y);
int n;
char f[60];
int num[60];
lld v_max[60][60];
lld v_min[60][60];
int flag_max[60][60];
int flag_min[60][60];

lld getMin(int x, int y)
{
    if (flag_min[x][y]) return v_min[x][y];
    if (x == y) { v_min[x][y] = num[x]; }
    else if (x == y - 1)
    {
        if (f[x] == 't') v_min[x][y] = num[x] + num[y];
        else v_min[x][y] = num[x] * num[y];
    }
    else
    {
        if (f[x] == 't')
            v_min[x][y] = num[x] + getMin(x + 1, y);
        else
        {
            if (num[x] >= 0) v_min[x][y] = num[x] * getMin(x + 1, y);
            else v_min[x][y] = num[x] * getMax(x + 1, y);
        }
        for (int i = x + 1; i < y; i++)
        {
            if (f[i] == 't')
            {
                lld t = getMin(x, i) + getMin(i + 1, y);
                v_min[x][y] = min(v_min[x][y], t);
            }
            else
            {
                lld a0 = getMin(x, i);
                lld a1 = getMax(x, i);
                lld b0 = getMin(i + 1, y);
                lld b1 = getMax(i + 1, y);
                v_min[x][y] = min(v_min[x][y], a0*b0);
                v_min[x][y] = min(v_min[x][y], a0*b1);
                v_min[x][y] = min(v_min[x][y], a1*b0);
                v_min[x][y] = min(v_min[x][y], a1*b1);
            }
        }
    }
    flag_min[x][y] = 1;
    return v_min[x][y];
}
lld getMax(int x, int y)
{
    if (flag_max[x][y]) return v_max[x][y];
    if (x == y) { v_max[x][y] = num[x]; }
    else if (x == y - 1)
    {
        if (f[x] == 't') v_max[x][y] = num[x] + num[y];
        else v_max[x][y] = num[x] * num[y];
    }
    else
    {
        if (f[x] == 't')
            v_max[x][y] = num[x] + getMax(x + 1, y);
        else
        {
            if (num[x] >= 0) v_max[x][y] = num[x] * getMax(x + 1, y);
            else v_max[x][y] = num[x] * getMin(x + 1, y);
        }
        for (int i = x + 1; i < y; i++)
        {
            if (f[i] == 't')
            {
                lld t = getMax(x, i) + getMax(i + 1, y);
                v_max[x][y] = max(v_max[x][y], t);
            }
            else
            {
                lld a0 = getMin(x, i);
                lld a1 = getMax(x, i);
                lld b0 = getMin(i + 1, y);
                lld b1 = getMax(i + 1, y);
                v_max[x][y] = max(v_max[x][y], a0*b0);
                v_max[x][y] = max(v_max[x][y], a0*b1);
                v_max[x][y] = max(v_max[x][y], a1*b0);
                v_max[x][y] = max(v_max[x][y], a1*b1);
            }
        }
    }
    flag_max[x][y] = 1;
    return v_max[x][y];
}

int main()
{
    int num_org[60];
    char f_org[60];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char s[3];
        scanf("%s %d", s, &num_org[i]);
        f_org[i] = s[0];
    }
    lld res[60];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            num[j] = num_org[(i + j) % n];
        for (int j = 0; j < n - 1; j++)
            f[j] = f_org[(i + 1 + j) % n];
        memset(flag_max, 0, sizeof(flag_max));
        memset(flag_min, 0, sizeof(flag_min));
        res[i] = getMax(0, n - 1);
    }
    lld maxv = res[0];
    for (int i = 1; i < n; i++) maxv = max(maxv, res[i]);
    printf("%lld\n", maxv);
    int first = 1;
    for (int i = 0; i < n; i ++)
        if (res[i] == maxv)
        {
            if (first) { printf("%d", i + 1); first = 0; }
            else printf(" %d", i + 1);
        }
    printf("\n");
    return 0;
}