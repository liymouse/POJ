#include <stdio.h>
#include <string.h>

char a[600][256];
char b[600][256];
char f[600][600];
int na, nb;

//change ? -> !??
//change ! -> !!*
//new mark ? = 0 or 1,  ! = 1,  * = 1 or more
void split(char dst[][256], int &n, char *s)
{
    int sL = strlen(s);
    int p = 0;
    n = 1;
    int L = 0;
    while (p < sL)
    {
        dst[n][L++] = s[p++];
        if (s[p] == '.')
        {
            if (L == 1 && dst[n][L - 1] == '!')
            {
                n++; dst[n][0] = '!';
                n++; dst[n][0] = '*';
            }
            else if (L == 1 && dst[n][L - 1] == '?')
            {
                dst[n][L - 1] = '!';
                n++; dst[n][0] = '?';
                n++; dst[n][0] = '?';
            }
            n++; L = 0;
            p++;
        }
    }
    if (L == 1 && dst[n][L - 1] == '!')
    {
        n++; dst[n][0] = '!';
        n++; dst[n][0] = '*';
    }
    else if (L == 1 && dst[n][L - 1] == '?')
    {
        dst[n][L - 1] = '!';
        n++; dst[n][0] = '?';
        n++; dst[n][0] = '?';
    }
    n++;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        char s[300];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(f, 0, sizeof(f));
        scanf("%s", s);
        split(a, na, s);
        scanf("%s", s);
        split(b, nb, s);
        f[0][0] = 1;
        for (int i = 1; i < na; i ++)
            for (int j = 1; j < nb; j++)
            {
                if (a[i][0] != '*' && a[i][0] != '?' && a[i][0] != '!' && b[j][0] != '*' && b[j][0] != '?' && b[j][0] != '!')
                {
                    f[i][j] = (strcmp(a[i], b[j]) == 0) ? f[i - 1][j - 1] : 0;
                }
                else
                {
                    if (a[i][0] == '*') f[i][j] = f[i][j] | f[i][j - 1] | f[i - 1][j - 1];
                    if (a[i][0] == '?') f[i][j] = f[i][j] | f[i - 1][j - 1] | f[i - 1][j];
                    if (a[i][0] == '!') f[i][j] = f[i][j] | f[i - 1][j - 1];
                    if (b[j][0] == '*') f[i][j] = f[i][j] | f[i - 1][j] | f[i - 1][j - 1];
                    if (b[j][0] == '?') f[i][j] = f[i][j] | f[i - 1][j - 1] | f[i][j - 1];
                    if (b[j][0] == '!') f[i][j] = f[i][j] | f[i - 1][j - 1];
                }
            }
        if (f[na-1][nb-1]) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}
