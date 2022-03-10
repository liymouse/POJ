#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n , w;
    while (scanf("%d %d" , &n , &w) == 2)
    {
        if (n == 0) break;
        int hist[11] = {0};
        int maxhight = 0;
        int maxv = 0;
        for (int i = 0; i < n; i ++)
        {
            int x;
            scanf("%d" , &x);
            maxv = max(maxv , x);
            hist[x / w] ++;
        }
        int num = maxv / w + 1;
        for (int i = 0; i < num; i ++) maxhight = max(maxhight , hist[i]);
        double res = 0.01;
        double dink = 1.0 / (num-1) , ink = 1.0;
        for (int i = 0; i < num; i ++)
        {
            res += ink * hist[i] / maxhight;
            ink -= dink;
        }
        printf("%lf\n" , res);
    }
    return 0;
}
