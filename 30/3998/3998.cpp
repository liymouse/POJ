#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100010] , m , mint , avg , n , k;

int gcd(int x , int y)
{
    if (x % y == 0) return y;
    return gcd(y , x % y);
}
void find(int x , int start , int tot)
{
    if (tot >= mint) return;
    if (x == k-1)
    {
        tot += abs(a[m-1] - a[start] - n);
        mint = min(mint , tot);
        return;
    }
    int i;
    for (i = start + 1; i < m && a[i]-a[start] < n; i ++);
    find(x + 1 , i-1 , tot + abs(a[i-1]-a[start]-n));
    find(x + 1 , i   , tot + abs(a[i]  -a[start]-n));
}
void cal(int *b)
{
    m = 1; a[1] = k; a[0] = 0;
    for (int i = 1; i < n; i ++)
        if (b[i] == b[i-1]) a[m] += k;
        else a[++m] = k;
    m ++;
    for (int i = 1; i < m; i ++) a[i] += a[i-1];
    find(0 , 0 , 0);
}

int main()
{
    int ca = 1;
    while (scanf("%d %d" , &n , &k) == 2)
    {
        if (n == 0) break;
        int x[100010] , y[100010];
        for (int i = 0; i < n; i ++) scanf("%d %d" , &x[i] , &y[i]);
        mint = 0x7fffffff;
        sort(x , x + n); cal(x);
        sort(y , y + n); cal(y);
        k *= k;
        int t = gcd(mint , k);
        mint /= t; k /= t;
        printf("%d. %d/%d\n" , ca ++, mint , k);
    }
    return 0;
}