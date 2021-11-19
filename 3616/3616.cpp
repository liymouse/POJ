#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int begin, end, eff;
}Node;
Node a[1005];
int cmp(Node &x, Node &y)
{
    if (x.begin == y.begin) return x.end < y.end;
    return x.begin < y.begin;
}
int main()
{
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);
    int f[1005] = { 0 };
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a[i].begin, &a[i].end, &a[i].eff);
    }
    sort(a, a + m, cmp);
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        f[i] = a[i].eff;
        int maxv = 0;
        for (int j = 0; j < i; j++)
            if (a[j].end + r <= a[i].begin && f[j] > maxv)
                maxv = f[j];
        f[i] += maxv;
        if (f[i] > res) res = f[i];
    }
    printf("%d\n", res);
    return 0;
}