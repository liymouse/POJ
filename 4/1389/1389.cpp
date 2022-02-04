#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct
{
    int si, ei; //start index & end index
    int sv, ev; //real start value & real end value
    int weight;
    int v;
}Node;
Node tree[4096] = { 0 };
typedef struct
{
    int x;
    int sy, ey;
    int weight; //1 = add, -1 = remove
}Line;
Line x[2000] = { 0 };
int y[2000] = { 0 }; //y read value

int cmp(Line &a, Line &b) { return a.x < b.x; }

void buildTree(int i, int si, int ei)
{
    tree[i].si = si;
    tree[i].ei = ei;
    tree[i].sv = y[si];
    tree[i].ev = y[ei];
    tree[i].weight = 0;
    if (si == ei-1) return; //[y[si], y[ei]]
    else
    {
        int mi = (si + ei) >> 1;
        buildTree(i * 2 + 1, si, mi);
        buildTree(i * 2 + 2, mi, ei);
    }
}

int addLine(int i, int sy, int ey, int w)
{
    if (tree[i].si == tree[i].ei - 1) //reach leaf
    {
        tree[i].weight += w;
        if (tree[i].weight > 0) tree[i].v = ey - sy;
        else tree[i].v = 0;
    }
    else if (ey <= tree[i * 2 + 1].ev) tree[i].v = addLine(i * 2 + 1, sy, ey, w) + tree[i*2+2].v;
    else if (sy >= tree[i * 2 + 2].sv) tree[i].v = tree[i*2+1].v + addLine(i * 2 + 2, sy, ey, w);
    else
    {
        tree[i].v = addLine(i * 2 + 1, sy, tree[i * 2 + 1].ev, w) +
            addLine(i * 2 + 2, tree[i * 2 + 2].sv, ey, w);
    }
    return tree[i].v;
}
int main()
{
    int x1, y1, x2, y2;
    int n = 0;
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4)
    {
        if (x1 == -1)
        {
            if (n == 0) break;
            sort(y, y + n);
            sort(x, x + n, cmp);
            buildTree(0, 0, n - 1);
            int ylen = addLine(0, x[0].sy, x[0].ey, x[0].weight);
            int area = 0;
            for (int i = 1; i < n; i++)
            {
                area += (x[i].x - x[i - 1].x) * ylen;
                ylen = addLine(0, x[i].sy, x[i].ey, x[i].weight);
            }
            printf("%d\n", area);

            n = 0;
            memset(y, 0, sizeof(y));
            memset(x, 0, sizeof(x));
            memset(tree, 0, sizeof(tree));
        }
        else
        {
            y[n] = y1;
            x[n].x = x1; x[n].sy = y1; x[n].ey = y2; x[n].weight = 1;
            n++;
            y[n] = y2;
            x[n].x = x2; x[n].sy = y1; x[n].ey = y2; x[n].weight = -1;
            n++;
        }
    }
    return 0;
}
