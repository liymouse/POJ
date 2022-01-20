#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[90];
int f[90]; // f[i][k] = 0~i, last word is f[i][k]~i
int n;

int cmp(int x1, int y1, int x2, int y2)
{
    while (x1 < y1 && s[x1] == '0') x1++;
    while (x2 < y2 && s[x2] == '0') x2++;
    if (y1 - x1 < y2 - x2) return -1;
    else if (y1 - x1 > y2 - x2) return 1;
    for (int i = 0; i <= y1 - x1; i++)
        if (s[x1 + i] > s[x2 + i]) return 1;
        else if (s[x1 + i] < s[x2 + i]) return -1;
    return 0;
}

int main()
{
    while (scanf("%s", s) == 1)
    {
        if (strcmp(s, "0") == 0) break;
        n = strlen(s);
        memset(f, 0, sizeof(f));
        for (int i = 1; i < n; i ++)
        {
            f[i] = f[i-1];
            for (int j = 0; j < i; j++)
            {
                if (cmp(f[j], j, j+1, i) < 0 && cmp(j + 1, i, f[i], i) < 0)
                {
                    f[i] = j + 1;
                }
            }
        }
        int t[90];
        memset(t, 0xff, sizeof(t));
        int k = n - 1;
        while (k >= 0)
        {
            if (cmp(k, n - 1, f[n - 1], n - 1) > 0) break;
            else if (cmp(k, n - 1, f[n - 1], n - 1) == 0) t[k] = n - 1;
            k--;
        }

        for (int i = k; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (t[j] != -1 && cmp(i, j - 1, j, t[j]) < 0)
                {
                    if (t[i] == -1 || cmp(i, j - 1, i, t[i]) > 0) t[i] = j - 1;
                }
            }
        }
        int sp[90] = { 0 };
        k = 0;
        while (t[k] < n - 1)
        {
            sp[t[k]] = 1;
            k = t[k] + 1;
        }
        for (int i = 0; i < n; i++)
        {
            printf("%c", s[i]);
            if (sp[i]) printf(",");
        }
        printf("\n");
    }
}
