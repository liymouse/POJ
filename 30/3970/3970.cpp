#include <stdio.h>

typedef long long i64d;

int gcd(int a , int b)
{
    if (b == 0) return a;
    return gcd(b , a % b);
}

int main()
{
    int n;
    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) break;
        int a[30];
        for (int i = 0; i < n; i ++) scanf("%d" , &a[i]);
        int more = (a[0] >= 1000000) ? 1 : 0;
        for (int i = 1; i < n; i ++)
        {
            int x = gcd(a[i-1] , a[i]);
            if ((i64d)a[i-1] / x * a[i] >= 1000000) {more = 1; break;}
            a[i] *= a[i-1] / x;
        }
        if (more) printf("Too much money to pay!\n");
        else printf("The CEO must bring %d pounds.\n" , a[n-1]);
    }
    return 0;
}
