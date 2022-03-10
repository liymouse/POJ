#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 100000000
int main()
{
    int n , s , t;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        int a[210] , f[210][210] = {0};
        scanf("%d %d" , &s , &t);
        for (int i = 0; i < n; i ++) scanf("%d" , &a[i]);
        t --;
        for (int i = 0; i < n; i ++)
        {
            if (i < s) f[i][0] = a[i];
            else f[i][0] = -INF;
            for (int j = 1; j < t; j ++)
            {
                int maxv = -INF;
                for (int k = 1; k <= min(i , s); k ++)
                    maxv = max(maxv , f[i-k][j-1] + a[i]);
                f[i][j] = maxv;
            }
        }
        int res = -INF;
        for (int i = max(0 , n-s); i < n; i ++)
            for (int j = 0; j < t; j ++) res = max(res , f[i][j]);
        if (s > n) res = max(0 , res);
        printf("%d\n" , res);
    }
    return 0;
}
