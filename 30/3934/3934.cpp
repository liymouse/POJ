#include <stdio.h>
#include <string.h>

#define MOD 9937

int main()
{
    int f[81][158] = {0};
    int n , m;
    f[1][0] = 1;
    for (int i = 2; i <= 80; i ++)
        for (int j = i-1; j <= 2*i-3; j ++)
        {
            if (j >= 2 && f[i-1][j-2]) f[i][j] = (f[i][j] + f[i-1][j-2] * (i-2)) % MOD;
            f[i][j] = (f[i][j] + f[i-1][j-1] * 2) % MOD;
        }
    while (scanf("%d %d" , &n , &m) == 2)
    {
        if (n == 0) break;
        if (n == 1 && m == 0) printf("1\n");
        else if (m < n-1 || m > 2*n-3) printf("0\n");
        else printf("%d\n" , f[n][m]);
    }
    return 0;
}
