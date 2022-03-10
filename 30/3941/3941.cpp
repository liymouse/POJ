#include <stdio.h>
#include <math.h>
#include <string.h>

typedef long long i64d;

int main()
{
    int n , m , k;
    while (scanf("%d %d %d" , &n , &m , &k) == 3)
    {
        if (n == 0 && m == 0 && k == 0) break;
        i64d num[2][10010];
        int t = 0 , len = m;
        for (int i = 0; i < m; i ++) num[t][i] = 1;
        for (int i = 1; i < n; i ++)
        {
            memset(num[!t] , 0 , sizeof(num[0]));
            for (int j = 1; j <= m; j ++)
                for (int h = 0; h < len; h ++)
                    num[!t][h + j] += num[t][h];
            len += m;
            t = !t;
        }
        double tot = pow((double)m , (double)n);
        double res = 0;
        for (int i = 0; i < len; i ++)
            if (i+1 <= k) res += num[t][i] / tot;
            else res += (i+1-k) * num[t][i] / tot;
        printf("%.7lf\n" , res);
    }
    return 0;
}
