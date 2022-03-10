#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int cmp(pair<int, int>&x, pair<int, int> &y)
{
    return x.first < y.first;
}
int main()
{
    int n, t;
    pair<int, int> a[25001];
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].first , &a[i].second);
        a[i].second++;
    }
    sort(a, a + n, cmp);
    int cur = 1;
    int maxv = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].first > cur)
        {
            if (a[i].first > maxv) { printf("-1\n"); return 0; }
            else { cur = maxv; res++; }
        }
        if (a[i].second > maxv) {
            maxv = a[i].second;
            if (maxv > t) break;
        }
    }
    if (cur <= t) { cur = maxv; res++; }
    if (cur > t) printf("%d\n", res);
    else printf("-1\n");
    return 0;
}