#if 0 //quad tree (Time Limit Execeed)
#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

typedef struct {
    int sum;
    int sx, sy, ex, ey;
}Node;
Node tree[1398101];

void buildTree(int i, int sx, int sy, int ex, int ey)
{
    tree[i].sum = 0;
    tree[i].sx = sx; tree[i].ex = ex;
    tree[i].sy = sy; tree[i].ey = ey;
    if (sx == ex && sy == ey) return;
    int mx = (sx + ex) >> 1;
    int my = (sy + ey) >> 1;
    buildTree(i * 4 + 1, sx, sy, mx, my);
    buildTree(i * 4 + 2, mx + 1, sy, ex, my);
    buildTree(i * 4 + 3, sx, my + 1, mx, ey);
    buildTree(i * 4 + 4, mx + 1, my + 1, ex, ey);
}
void addTree(int i, int x, int y, int a)
{
    tree[i].sum += a;
    if (tree[i].sx == tree[i].ex && tree[i].sy == tree[i].ey) return;
    for (int j = i*4+1; j <= i*4+4; j++)
        if (tree[j].sx <= x && x <= tree[j].ex && tree[j].sy <= y && y <= tree[j].ey)
        {
            addTree(j, x, y, a);
            return;
        }
}
int getTree(int i, int sx, int sy, int ex, int ey)
{
    if (sx == tree[i].sx && sy == tree[i].sy && ex == tree[i].ex && ey == tree[i].ey) return tree[i].sum;
    int sum = 0;
    for (int j = i*4+1; j <= i*4+4; j++)
    {
        if (!(sx > tree[j].ex || ex < tree[j].sx || sy > tree[j].ey || ey < tree[j].sy))
        {
            sum += getTree(j, max(sx, tree[j].sx), max(sy, tree[j].sy), min(ex, tree[j].ex), min(ey, tree[j].ey));
        }
    }
    return sum;
}
int main()
{
    int type, s;
    while (scanf("%d", &type) == 1)
    {
        if (type == 0)
        {
            scanf("%d", &s);
            buildTree(0, 0, 0, s - 1, s - 1);
        }
        else if (type == 1)
        {
            int x, y, a;
            scanf("%d %d %d", &x, &y, &a);
            addTree(0, x, y, a);
        }
        else if (type == 2)
        {
            int sx, sy, ex, ey;
            scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
            printf("%d\n", getTree(0, sx, sy, ex, ey));
        }
        else break;
    }
    return 0;
}
#else
#include <stdio.h>
#include <string.h>

int a[1025][1025];
int lowbit[1025];

int sum(int x, int y)
{
    int res = 0;
    for (int i = x; i > 0; i -= lowbit[i])
        for (int j = y; j > 0; j -= lowbit[j])
            res += a[i][j];
    return res;
}

int main()
{
    int type, s;
    while (scanf("%d", &type) == 1)
    {
        if (type == 0)
        {
            scanf("%d", &s);
            memset(a, 0, sizeof(a));
            for (int i = 1; i <= s; i++) lowbit[i] = i & (-i);
        }
        else if (type == 1)
        {
            int x, y, v;
            scanf("%d %d %d", &x, &y, &v);
            x++; y++;
            for (int i = x; i <= s; i += lowbit[i])
                for (int j = y; j <= s; j += lowbit[j])
                    a[i][j] += v;
        }
        else if (type == 2)
        {
            int sx, sy, ex, ey;
            scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
            sx++; sy++; ex++; ey++;
            int ans = sum(ex, ey) + sum(sx - 1, sy - 1) - sum(sx - 1, ey) - sum(ex, sy - 1);
            printf("%d\n", ans);
        }
        else break;
    }
    return 0;
}
#endif