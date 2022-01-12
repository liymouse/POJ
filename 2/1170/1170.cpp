#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
typedef struct
{
    int num[5];
    int p;
}Plan;
int f[6][6][6][6][6] = { 0 };
int p[5] = { 0 };
int num[5] = { 0 };
int n, np;
Plan off[100];

int find(int a0, int a1, int a2, int a3, int a4)
{
    if (a0 + a1 + a2 + a3 + a4 == 0) return 0;
    if (f[a0][a1][a2][a3][a4] != 0) return f[a0][a1][a2][a3][a4];
    int res = 1 << 30;
    for (int i = 0; i < np; i++)
        if (off[i].num[0] <= a0 && off[i].num[1] <= a1 && off[i].num[2] <= a2 &&
            off[i].num[3] <= a3 && off[i].num[4] <= a4)
        {
            res = min(res, off[i].p + find(a0 - off[i].num[0], a1 - off[i].num[1], a2 - off[i].num[2], a3 - off[i].num[3], a4 - off[i].num[4]));
        }
    if (a0 > 0) res = min(res, p[0] + find(a0 - 1, a1, a2, a3, a4));
    if (a1 > 0) res = min(res, p[1] + find(a0, a1 - 1, a2, a3, a4));
    if (a2 > 0) res = min(res, p[2] + find(a0, a1, a2 - 1, a3, a4));
    if (a3 > 0) res = min(res, p[3] + find(a0, a1, a2, a3 - 1, a4));
    if (a4 > 0) res = min(res, p[4] + find(a0, a1, a2, a3, a4 - 1));
    f[a0][a1][a2][a3][a4] = res;
    return res;
}

int main()
{
    int key[1000] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int c;
        scanf("%d %d %d", &c, &num[i], &p[i]);
        key[c] = i;
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i++)
    {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++)
        {
            int k, c;
            scanf("%d %d", &k, &c);
            off[i].num[key[k]] = c;
        }
        scanf("%d", &off[i].p);
    }
    int res = find(num[0],num[1],num[2],num[3],num[4]);
    printf("%d\n", res);
    return 0;
}