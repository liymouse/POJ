#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long i64d;

typedef struct{
    i64d sum;
    int num;
}node;
node state1[140000];

int cmp(node a , node b)
{
    if (a.sum == b.sum) return a.num < b.num;
    return a.sum < b.sum;
}

i64d abs64(i64d x)
{
    return (x > 0) ? x : -x;
}

int main()
{
    int n;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        i64d a[40];
        for (int i = 0; i < n; i ++) scanf("%lld" , &a[i]);
        int len = n / 2;
        int tot1 = 0;
        i64d minsum = abs64(a[0]);
        int minnum = 1;
        for (int i = 0; i < 1 << len; i ++)
        {
            i64d sum = 0;
            int num = 0;
            for (int j = 0; j < len; j ++)
                if ((1 << j) & i)
                {
                    sum += a[j];
                    num ++;
                }
            state1[tot1].num = num;
            state1[tot1 ++].sum = sum;
        }
        sort(state1 , state1 + tot1 , cmp);
        int len2 = n - len;
        for (int i = 0; i < 1 << len2; i ++)
        {
            i64d sum = 0;
            int num = 0;
            for (int j = 0; j < len2; j ++)
                if ((1 << j) & i)
                {
                    sum += a[j + len];
                    num ++;
                }
            int low = 0 , high = tot1 , mid;
            while (low < high)
            {
                mid = (low + high) / 2;
                if (-sum > state1[mid].sum) low = mid + 1;
                else if (-sum < state1[mid].sum) high = mid - 1;
                else break;
            }
            for (int j = mid-3; j <= mid+3; j ++)
                if (j >= 0 && j < tot1)
                {
                    i64d finalsum = sum + state1[j].sum;
                    int finalnum = num + state1[j].num;
                    if (finalnum > 0)
                    {
                        if (abs64(finalsum) < minsum || (abs64(finalsum) == minsum && finalnum < minnum))
                        {
                            minsum = abs64(finalsum);
                            minnum = finalnum;
                        }
                    }
                }
        }
        printf("%lld %d\n" , minsum , minnum);
    }
    
    return 0;
}
