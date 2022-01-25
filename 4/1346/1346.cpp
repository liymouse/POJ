#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))

int match(int a[], int b[], int n)
{
    int f[25][25] = { 0 };
    for (int i = 1; i <= n-1; i ++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = max(f[i][j], f[i - 1][j]);
            f[i][j] = max(f[i][j], f[i][j - 1]);
            if (a[i - 1] == b[j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    return f[n-1][n];
}
int main()
{
    int ca;
    while (scanf("%d", &ca) == 1)
    {
        if (ca == 0) break;
        int n;
        int begin[25], end[25];
        scanf("%d", &n);
        char s[4];
        scanf("%s", s);
        int begin_type = s[0] == 'R' ? 0 : 1;
        begin[0] = atoi(s + 1);
        for (int i = 1; i < n; i++) scanf("%d", &begin[i]);
        scanf("%s", s);
        int end_type = s[0] == 'R' ? 0 : 1;
        end[0] = atoi(s + 1);
        for (int i = 1; i < n; i++) scanf("%d", &end[i]);
        //check same
        int same = begin_type == end_type;
        for (int i = 0; i < n; i++) if (begin[i] != end[i]) {
            same = 0; break;
        }
        if (same) { printf("%d 0\n", ca); continue; }

        int a[25];
        int res = 0;
        for (int k = begin_type; k < n; k += 2)
        {
            //k out
            for (int s = 0; s < n; s ++)
                if (s != k)
                {
                    int t = s;
                    for (int i = 0; i < n - 1; i++)
                    {
                        a[i] = begin[t];
                        t = (t + 1) % n;
                        if (t == k) t = (t + 1) % n;
                    }
                    res = max(res, match(a, end, n));
                }
        }
        printf("%d %d\n", ca, n - res);
    }
    return 0;
}