#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long i64d;
pair<int, int> a[100005];

int cmp(pair<int, int> &x, pair<int, int> &y)
{
    return (double)x.second / x.first > (double)y.second / y.first;
}
int main()
{
    int n;
    i64d res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].first, &a[i].second);
    sort(a, a + n, cmp);
    i64d t = 0;
    for (int i = 0; i < n; i++)
    {
        res += (i64d)a[i].second * t;
        t += a[i].first;
    }
    printf("%lld\n", res * 2);
    return 0;
}