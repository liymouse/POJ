#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long lld;
#define P 10000000

int a[100000];
int num[100000] = { 0 };

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int k = 1;
    num[0] = 1;
    for (int i = 1; i < n; i ++)
        if (a[i] == a[i - 1])
        {
            num[k - 1] ++;
        }
        else
        {
            if (k != i) a[k] = a[i];
            num[k] = 1;
            k++;
        }
    int N = k;
    int maxv = -1;
    k = -1;
    for (int i = 0; i < N; i++)
    {
        int diff = (i == 0) ? a[i] + P - a[N - 1] : a[i] - a[i - 1];
        if (diff > maxv) { maxv = diff; k = i; }
    }
    int sum = num[k];
    int mid = k;
    while (sum < n/2)
    {
        mid = (mid + 1) % N;
        sum += num[mid];
    }
    sum = 0;
    lld res = 0;
    int i = k;
    while (i != mid)
    {
        sum += num[i];
        int j = (i + 1) % N;
        lld diff = a[j] - a[i];
        if (diff < 0) diff += P;
        res += (lld)sum * diff;
        i = (i + 1) % N;
    }
    i = (k - 1 + N) % N;
    sum = 0;
    while (i != mid)
    {
        sum += num[i];
        int j = (i - 1 + N) % N;
        lld diff = a[i] - a[j];
        if (diff < 0) diff += P;
        res += (lld)sum * diff;
        i = (i - 1 + N) % N;
    }
    printf("%lld\n", res);
    return 0;
}