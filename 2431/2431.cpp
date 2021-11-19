#include <stdio.h>
#include <queue>
using namespace std;

int cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}
int main()
{
    int n;
    pair<int, int> a[10002];
    int dis, oil;

    scanf("%d", &n);
    for (int i = 0; i < n; i ++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        a[i].first = x;
        a[i].second = y;
    }
    a[n].first = 0;
    a[n].second = 0;
    n++;
    sort(a, a + n, cmp);
    scanf("%d %d", &dis, &oil);
    int res = 0;
    n++;
    priority_queue<int> qu;
    for (int i = 0; i < n; i++)
    {
        while (dis > a[i].first)
        {
            if (oil < dis - a[i].first)
            {
                if (qu.empty())
                {
                    printf("-1\n");
                    return 0;
                }
                dis -= oil;
                oil = qu.top();
                qu.pop();
                res++;
            }
            else
            {
                oil -= dis - a[i].first;
                dis = a[i].first;
            }
        }
        qu.push(a[i].second);
    }
    printf("%d\n", res);
    return 0;
}