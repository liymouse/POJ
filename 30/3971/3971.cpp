#include <stdio.h>
#include <string.h>

char s[1000010] = {0};
int dp[1000010][2] = {0};

int main()
{
    int ca;
    scanf("%d" , &ca);
    while (ca --)
    {
        int n, l, d;
        memset(dp , 0 , sizeof(dp));
        memset(s , 0 , sizeof(s));
        scanf("%d %d %d" , &n , &l , &d);
        scanf("%s" , s);
        for (int i = 0; i < (l+1)/2; i ++)
        {
            char tmp = s[i] - '0';
            s[i] = s[l-i-1] - '0';
            s[l-i-1] = tmp;
        }
        dp[0][s[0]] = 1;
        for (int i = 0; i < n; i++)
        {
            dp[i + 1][s[i + 1]] = (dp[i + 1][s[i + 1]] + dp[i][0] + dp[i][1]) % d;
            if (dp[i][1])
            {
                int j = i + 1;
                while (s[j] != 0) j ++;
                dp[j][1] += dp[i][1];
            }
        }
        printf("%d\n" , (dp[n-1][0] + dp[n-1][1]) % d);
    }
    return 0;
}
