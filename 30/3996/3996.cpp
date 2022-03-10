#include <stdio.h>
#include <algorithm>
using namespace std;
#define PI 3.141

typedef struct
{
    double x , y , dist1 , dist2;
}Point;

int cmp(Point a , Point b)
{
    return a.dist1 > b.dist1;
}

int main()
{
    int n , ca = 1;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        double x1 , y1 , x2 , y2 , t;
        Point a[1010];
        scanf("%lf %lf %lf %lf %lf" , &x1 , &y1 , &x2 , &y2 , &t);
        t /= PI;
        for (int i = 0; i < n; i ++)
        {
            scanf("%lf %lf" , &a[i].x , &a[i].y);
            a[i].dist1 = (a[i].x - x1) * (a[i].x - x1) + (a[i].y - y1) * (a[i].y - y1);
            a[i].dist2 = (a[i].x - x2) * (a[i].x - x2) + (a[i].y - y2) * (a[i].y - y2);
        }
        a[n].dist1 = 0;
        sort(a , a + n + 1, cmp);
        int maxget = 0;
        for (int i = 0; i <= n; i ++)
            if (a[i].dist1 <= t)
            {
                int get = n-i;
                double r2 = t - a[i].dist1;
                for (int j = 0; j < i; j ++)
                    if (a[j].dist2 <= r2) get ++;
                maxget = max(maxget , get);
            }
        printf("%d. %d\n" , ca++ , n - maxget); 
    }
    return 0;
}