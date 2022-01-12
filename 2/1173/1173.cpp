#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int f[34][34] = { 0 };
char s[50];
int n, k, m;

int getId(int x, int num, int L)
{
    if (num == 1) return 0;
    if (num == 2)
    {
        int num1 = 0;
        for (int i = x; i < n; i++)
            if (s[i] == '1') num1++;
            else break;
        int first = max(L - m, 1);
        return num1 - first;
    }
    else
    {
        int tot = 0;
        int num1 = 0, num0 = 0;
        while (x < n)
        {
            if (s[x] == '1') num1++;
            else break;
            x++;
        }
        while (x < n)
        {
            if (s[x] == '0') num0++;
            else break;
            x++;
        }
        for (int i = 1; i <= m; i ++)
            for (int j = m; j >= 1; j--)
            {
                if (i == num1 && j == num0) goto L_break;
                if (L - i - j >= 0) tot += f[num - 2][L - i - j];
            }
    L_break:
        tot += getId(x, num - 2, L - num1 - num0);
        return tot;
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= k; i++) f[i][i] = 1;
    for (int i = 1; i <= m; i++) f[1][i] = 1;
    for (int i = 2; i <= k; i ++)
        for (int j = i; j <= min(m*i, n); j++)
        {
            f[i][j] = 0;
            for (int k = 1; k <= m; k++)
                if (i - 1 <= j - k && j - k <= (i - 1)*m) f[i][j] += f[i - 1][j - k];
        }
    printf("%d\n", f[k][n]);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%s", s);
        printf("%d\n", getId(0, k, n));
    }
    return 0;
}