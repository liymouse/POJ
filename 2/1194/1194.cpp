#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef long long lld;

int f[1000002] = { 0 };
int n;
char s[1000002];
char w[100][103];
int wL[100];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", w[i]);
        wL[i] = strlen(w[i]);
    }
    scanf("%s", s+1);
    int L = strlen(s+1);
    for (int i = 1; i <= L; i++)
    {
        f[i] = f[i - 1];
        for (int j = 0; j < n; j ++)
            if (s[i] == w[j][wL[j] - 1])
            {
                int x = i-1, y = wL[j] - 2;
                int h = 1;
                while (x > 0 && y >= 0 && h <= 1000)
                {
                    if (s[x] == w[j][y]) y--;
                    x--; h++;
                }
                if (y < 0 && f[x] + wL[j] > f[i])
                {
                    f[i] = f[x] + wL[j];
                }
            }
    }
    printf("%d\n", f[L]);
    return 0;
}