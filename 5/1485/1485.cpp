#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int dp[201][31] = { 0 }; //dp[i][j] 1~i set j points, min sum distance
int d[201] = { 0 }; //dist of each point
int sumd[201][201] = { 0 }; //sumd[i][j] = set a depot between [i,j], the sum dist for each point to the depot
int path[201][31] = { 0 }; //path

int main()
{
    int k, n, ca = 1;
    while (scanf("%d %d", &n, &k) == 2)
    {
        if (n == 0 && k == 0) break;
        for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
        memset(sumd, 0, sizeof(sumd));
        memset(dp, 0, sizeof(dp));
        memset(path, 0, sizeof(path));
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                int mid = i + (j - i) / 2;
                //int mid = (i + j) / 2;
                for (int t = i; t < mid; t++) sumd[i][j] += d[mid] - d[t];
                for (int t = mid + 1; t <= j; t++) sumd[i][j] += d[t] - d[mid];
            }
        for (int i = 1; i <= n; i++) dp[i][1] = sumd[1][i];
        for (int i = 2; i <= n; i++)
            for (int j = 2; j <= k; j++)
            {
                if (j > i) break;
                dp[i][j] = 1<<30;
                for (int t = j-1; t < i; t++)
                    if (dp[t][j - 1] + sumd[t + 1][i] < dp[i][j])
                    {
                        dp[i][j] = dp[t][j - 1] + sumd[t + 1][i];
                        path[i][j] = t;
                    }
                if (dp[i][j] == (1 << 30))
                {
                    dp[i][j] = 0;
                    path[i][j] = i - 1;
                }
            }
        int x[31], y[31];
        int end = n;
        for (int i = k; i > 0; i--)
        {
            x[i] = path[end][i] + 1;
            y[i] = end;
            end = path[end][i];
        }
        printf("Chain %d\n", ca++);
        for (int i = 1; i <= k; i++)
            if (x[i] < y[i]) printf("Depot %d at restaurant %d serves restaurants %d to %d\n", i, (x[i] + y[i]) / 2, x[i], y[i]);
            else printf("Depot %d at restaurant %d serves restaurant %d\n", i, x[i], x[i]);
        printf("Total distance sum = %d\n\n", dp[n][k]);
    }
    return 0;
}
