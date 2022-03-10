#include <stdio.h>
#include <algorithm>
using namespace std;
#define iabs(a) ((a)>0?(a):-(a))
#define INF (1LL << 62)
typedef long long i64d;

i64d f[4010][4010];

int main()
{
    int n , m;
    int s[4010];
    pair<int , int> a[4010] , b[4010];
    while (scanf("%d" , &n) == 1)
    {
        for (int i = 0; i < n; i ++) {scanf("%d" , &s[i]); a[i].first = s[i]; a[i].second = i;}
        scanf("%d" , &m);
        for (int i = 0; i < m; i ++) {scanf("%d" , &b[i].first); b[i].second = i+1;}
        sort(a , a + n);
        sort(b , b + m);
        f[0][0] = iabs(a[0].first - b[0].first);
        for (int i = 1; i < n; i ++)
            for (int j = max(m-n+i , 0); j < m; j ++)
                if (j <= i)
                {
                    f[i][j] = INF;
                    int k = 0;
                    if (i-1 >= j)
                    {
                        i64d x = iabs(f[i-1][j]);
                        if (x == INF) x = 0;
                        if (x < f[i][j]) f[i][j] = x;
                    }
                    if (j > 0)
                    {
                        i64d x = iabs(f[i-1][j-1]);
                        if (x == INF) x = 0;
                        if (x < f[i][j]) {f[i][j] = x; k = -1;}
                    }
                    f[i][j] += iabs(a[i].first - b[j].first);
                    if (k == -1)
                    {
                        f[i][j] = -f[i][j];
                        if (f[i][j] == 0) f[i][j] = -INF; //use -inf instead for -0
                    }
                }
                else break;
        int t = m-1;
        for (int i = n-1; i >= 0; i --)
        {
            s[a[i].second] = b[t].second;
            if (f[i][t] < 0) t --;
        }
        if (f[n-1][m-1] == -INF) f[n-1][m-1] = 0;
        printf("%lld\n" , iabs(f[n-1][m-1]));
        for (int i = 0; i < n-1; i ++) printf("%d " , s[i]);
        printf("%d\n" , s[n-1]);
    }
    return 0;
}
