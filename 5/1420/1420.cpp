#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[50];
}Str;
Str **a;

int getV(char s[])
{
    int v = 0;
    if (s[0] == '=')
    {
        for (int i = 1; s[i] != 0; i++)
        {
            int x = 0, y = 0;
            while ('A' <= s[i] && s[i] <= 'Z') { x = x * 26 + s[i] - 'A' + 1; i++; }
            while ('0' <= s[i] && s[i] <= '9') { y = y * 10 + s[i] - '0'; i++; }
            v += getV(a[y-1][x-1].s);
        }
    }
    else
    {
        for (int i = 0; s[i] != 0; i++)
            v = v * 10 + s[i] - '0';
    }
    return v;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        a = (Str**)malloc(n * sizeof(Str*));
        for (int i = 0; i < n; i++)
        {
            a[i] = (Str*)malloc(m * sizeof(Str));
            for (int j = 0; j < m; j++)
            {
                memset(a[i][j].s, 0, sizeof(a[i][j].s));
                scanf("%s", a[i][j].s);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1; j++) printf("%d ", getV(a[i][j].s));
            printf("%d\n", getV(a[i][m - 1].s));
        }
        for (int i = 0; i < n; i++) free(a[i]);
        free(a);
    }
    return 0;
}