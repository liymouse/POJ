#include <stdio.h>
#include <string.h>
typedef long long lld;
#define min(a,b) ((a)<(b)?(a):(b))
#define M 9973
typedef struct {
    int minv;
    int sx, ex;
}Node;
Node tree[131072];
int a[50005];

int buildTree(int i, int sx, int ex)
{
    tree[i].sx = sx;
    tree[i].ex = ex;
    if (sx == ex) {
        tree[i].minv = a[sx];
    }
    else
    {
        int mx = (sx + ex) >> 1;
        int l = buildTree(i * 2 + 1, sx, mx);
        int r = buildTree(i * 2 + 2, mx + 1, ex);
        tree[i].minv = min(l, r);
    }
    return tree[i].minv;
}
int getTree(int i, int sx, int ex)
{
    if (sx == tree[i].sx && ex == tree[i].ex)
    {
        if (tree[i].minv == -1)
        {
            int mx = (sx + ex) >> 1;
            tree[i].minv = min(getTree(i * 2 + 1, sx, mx), getTree(i * 2 + 2, mx + 1, ex));
        }
        return tree[i].minv;
    }
    if (ex <= tree[i*2+1].ex) return getTree(i * 2 + 1, sx, ex);
    else if (sx >= tree[i*2+2].sx) return getTree(i * 2 + 2, sx, ex);
    else return min(getTree(i * 2 + 1, sx, tree[i*2+1].ex), getTree(i * 2 + 2, tree[i*2+2].sx, ex));
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n, a1, a2, a3, m, s1, s2, s3, e1, e2, e3;
        scanf("%d %d %d %d %d %d %d %d %d %d %d", &n, &a1, &a2, &a3, &m, &s1, &s2, &s3, &e1, &e2, &e3);
        for (int i = 0; i < n; i++) a[i] = ((lld)a1*i *i + a2*i + a3) % M;
        buildTree(0, 0, n - 1);
        int maxr = -1;
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            int s = ((lld)s1*i*i + s2*i + s3) % (n / 2);
            int e = s + ((lld)e1*i*i + e2*i + e3) % (n / 2);
            int t = getTree(0, s, e);
            if (t > maxr)
            {
                maxr = t; res = i;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
