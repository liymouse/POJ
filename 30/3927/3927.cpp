#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
    int x , y;
}Wed;

int cmp(Wed a , Wed b)
{
    if (a.x + a.y == b.x + b.y) return a.x < b.x;
    return a.x+a.y < b.x+b.y;
}
int main()
{
    int n;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        Wed a[100010];
        for (int i = 0; i < n; i ++) scanf("%d %d" , &a[i].x , &a[i].y);
        sort(a , a + n , cmp);
        int now = 0;
        int ok = 1;
        for (int i = 0; i < n; i ++)
        {
            if (now < a[i].x) now = a[i].x;
            int time = (a[i].y - a[i].x) / 2 + 1;
            if (now + time <= a[i].y)
            {
                now += time;
            }
            else
            {
                ok = 0; break;
            }
        }
        if (ok) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}
