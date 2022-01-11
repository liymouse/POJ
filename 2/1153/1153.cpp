#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long lld;
#define P 10000000

int a[100000];

int main()
{
    //freopen("safe.ina", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);

    int maxv = -1;
    int k = -1;
    for (int i = 0; i < n; i++)
    {
        int diff = (i == 0) ? a[i] + P - a[n - 1] : a[i] - a[i - 1];
        if (diff > maxv) { maxv = diff; k = i; }
    }
    lld res = 0;
    if (maxv >= P / 2)
    {
        int mid = (k + n / 2) % n;
        for (int i = 0; i < n; i++) res += min(abs(a[i] - a[mid]), P - abs(a[i] - a[mid]));
    }
    else
    {
        int mid = 0;
        for (int i = 0; i < n; i++) res += min(abs(a[i] - a[mid]), P - abs(a[i] - a[mid]));
        int t0 = (mid + 1) % n;
        while (t0 != mid)
        {
            int dist = t0 > mid ? a[t0] - a[mid] : P - a[mid] + a[t0];
            if (dist >= P / 2) break;
            t0 = (t0 + 1) % n;
        }
        int cur = 0;
        lld sum = res;
        //printf("%d %lld\n", cur, res);
        while (cur < n)
        {
            int nxt = cur + 1;
            while (nxt < n && a[nxt] == a[cur]) nxt++;
            if (nxt >= n) break;
            int t1 = t0;
            while (t1 != nxt)
            {
                int cur_dist = t1 > cur ? P - a[t1] + a[cur] : a[cur] - a[t1];
                int dist = t1 > nxt ? a[t1] - a[nxt] : P - a[nxt] + a[t1];
                if (dist >= P / 2) break;
                sum = sum - cur_dist + dist;
                t1 = (t1 + 1) % n;
            }
            lld L = a[nxt] - a[cur];
            sum += L * ((nxt + n - t1) % n);
            sum -= L * ((t0 + n - nxt) % n);
            if (sum < res) res = sum;
            cur = nxt; t0 = t1;
            //printf("%d %lld\n", cur, sum);
        }
    }
    printf("%lld\n", res);
    return 0;
}