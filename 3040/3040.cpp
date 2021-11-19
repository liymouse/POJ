#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> a[30]; //first = d, sceond=num
int use[30] = { 0 };
int n, c;

int choose()
{
    int t = 0;
    memset(use, 0, sizeof(use));
    for (int i = n - 1; i >= 0; i--)
        if (a[i].second > 0)
        {
            while (a[i].second > 0 && t + a[i].first <= c)
            {
                a[i].second--;
                t += a[i].first;
                use[i] ++;
            }
        }
    if (t == c) return 1;
    for (int i = 0; i < n; i ++)
        if (a[i].second > 0)
        {
            t += a[i].first;
            a[i].second--;
            use[i] ++;
            break;
        }
    if (t >= c) return 1;
    return 0;
}
int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].first, &a[i].second);
    sort(a, a + n);
    int res = 0;
    for (int i = n-1; i >= 0; i --)
        if (a[i].first >= c)
        {
            res += a[i].second;
            a[i].second = 0;
        }
    while (choose())
    {
        res++;
        int t = 1 << 30;
        for (int i = 0; i < n; i++)
            if (use[i] > 0 && a[i].second / use[i] < t)
                t = a[i].second / use[i];
        res += t;
        for (int i = 0; i < n; i++)
            if (use[i] > 0)
                a[i].second -= t * use[i];
    }
    printf("%d\n", res);
    return 0;
}