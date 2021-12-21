#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct
{
    int a, b;
    int k;
}Line;

int getf(int *f, int x)
{
    if (f[x] == x) return x;
    f[x] = getf(f, f[x]);
    return f[x];
}

Line hori[200], vert[200];
int hn, vn;
int res;

void find(int sx, int sy, int ex, int ey)
{
    for (int i = 0; i < hn; i ++)
        if (sy < hori[i].k && hori[i].k < ey && hori[i].a <= sx && hori[i].b >= ex)
        {
            find(sx, sy, ex, hori[i].k);
            find(sx, hori[i].k, ex, ey);
            return;
        }
    for (int i = 0; i < vn; i++)
        if (sx < vert[i].k && vert[i].k < ex && vert[i].a <= sy && vert[i].b >= ey)
        {
            find(sx, sy, vert[i].k, ey);
            find(vert[i].k, sy, ex, ey);
            return;
        }
    res = max(res, (ex - sx)*(ey - sy));
}
int main()
{
    int ca;
    //freopen("1255.in", "r", stdin);
    //freopen("1255.out", "w", stdout);
    scanf("%d", &ca);
    while (ca--)
    {
        int w, h;
        scanf("%d %d", &w, &h);
        int t;
        scanf("%d", &t);
        hn = vn = 0;
        Line tmp_hori[200];
        Line tmp_vert[200];
        int f_hori[200];
        int f_vert[200];
        for (int i = 0; i < 2 * t; i++) f_hori[i] = f_vert[i] = i;
        int tmp_hn = 0, tmp_vn = 0;
        for (int i = 0; i < t; i++)
        {
            int sx, sy, ex, ey;
            scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
            if (sy > 0)
            {
                for (int j = 0; j < tmp_hn; j++)
                    if (tmp_hori[j].k == sy && tmp_hori[j].a <= ex && sx <= tmp_hori[j].b)
                    {
                        f_hori[getf(f_hori, tmp_hn)] = tmp_hn;
                    }
                tmp_hori[tmp_hn].a = sx;
                tmp_hori[tmp_hn].b = ex;
                tmp_hori[tmp_hn].k = sy;
                tmp_hn++;
            }
            if (ey < h)
            {
                for (int j = 0; j < tmp_hn; j++)
                    if (tmp_hori[j].k == ey && tmp_hori[j].a <= ex && sx <= tmp_hori[j].b)
                    {
                        f_hori[getf(f_hori, j)] = tmp_hn;
                    }
                tmp_hori[tmp_hn].a = sx;
                tmp_hori[tmp_hn].b = ex;
                tmp_hori[tmp_hn].k = ey;
                tmp_hn++;
            }
            if (sx > 0)
            {
                for (int j = 0; j < tmp_vn; j++)
                    if (tmp_vert[j].k == sx && tmp_vert[j].a <= ey && sy <= tmp_vert[j].b)
                    {
                        f_vert[getf(f_vert, j)] = tmp_vn;
                    }
                tmp_vert[tmp_vn].a = sy;
                tmp_vert[tmp_vn].b = ey;
                tmp_vert[tmp_vn].k = sx;
                tmp_vn++;
            }
            if (ex < w)
            {
                for (int j = 0; j < tmp_vn; j++)
                    if (tmp_vert[j].k == ex && tmp_vert[j].a <= ey && sy <= tmp_vert[j].b)
                    {
                        f_vert[getf(f_vert, j)] = tmp_vn;
                    }
                tmp_vert[tmp_vn].a = sy;
                tmp_vert[tmp_vn].b = ey;
                tmp_vert[tmp_vn].k = ex;
                tmp_vn++;
            }
        }
        int mark[200] = { 0 };
        for (int i = 0; i < tmp_hn; i ++)
            if (mark[i] == 0)
            {
                mark[i] = 1;
                int a = tmp_hori[i].a;
                int b = tmp_hori[i].b;
                int id = getf(f_hori, i);
                for (int j = i+1; j < tmp_hn; j ++)
                    if (mark[j] == 0 && getf(f_hori, j) == id)
                    {
                        mark[j] = 1;
                        a = min(a, tmp_hori[j].a);
                        b = max(b, tmp_hori[j].b);
                    }
                hori[hn].a = a;
                hori[hn].b = b;
                hori[hn].k = tmp_hori[i].k;
                hn++;
            }
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i < tmp_vn; i++)
            if (mark[i] == 0)
            {
                mark[i] = 1;
                int a = tmp_vert[i].a;
                int b = tmp_vert[i].b;
                int id = getf(f_vert, i);
                for (int j = i + 1; j < tmp_vn; j++)
                    if (mark[j] == 0 && getf(f_vert, j) == id)
                    {
                        mark[j] = 1;
                        a = min(a, tmp_vert[j].a);
                        b = max(b, tmp_vert[j].b);
                    }
                vert[vn].a = a;
                vert[vn].b = b;
                vert[vn].k = tmp_vert[i].k;
                vn++;
            }
        res = 0;
        find(0, 0, w, h);
        printf("%d\n", res);
    }
}
