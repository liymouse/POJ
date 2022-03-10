#include <stdio.h>
#include <map>
using namespace std;

typedef long long i64d;

#define MOD 1000000007

int check[50000] = {0};
int prime[5000] , num = 0;

int main()
{
    map<int , int> f;
    f[1] = 1;
    for (int i = 2; i * i <= 45000; i ++)
        if (check[i] == 0) for (int j = i + i; j <= 45000; j += i)
            check[j] = 1;
    for (int i = 2; i <= 45000; i ++)
        if (check[i] == 0) {prime[num ++] = i; f[i] = i-1;}
    int n;
    while (scanf("%d" , &n) == 1)
    {
        i64d res = 1;
        for (int i = 0; i < n; i ++)
        {
            int a;
            scanf("%d" , &a);
            if (f.find(a) != f.end()) res = (res * f[a]) % MOD;
            else
            {
                int b = a;
                int ola = a;
                for (int i = 0; i < num; i ++)
                    if (b % prime[i] == 0)
                    {
                        ola = ola / prime[i] * (prime[i]-1);
                        while (b % prime[i] == 0) b /= prime[i];
                    }
                if (b != 1)
                {
                    ola = ola / b * (b-1);
                }
                f[a] = ola;
                res = (res * ola) % MOD;
            }
        }
        printf("%lld\n" , res);
    }
    return 0;
}
