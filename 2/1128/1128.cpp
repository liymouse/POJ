#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int a[30][30];
int du[30];
int has[26];
int n;
char res[30];

void dfs(int x)
{
    if (x == n)
    { 
        res[n] = 0; printf("%s\n", res); 
        return;
    }
    for (int i = 0; i < 26; i ++)
        if (has[i] && du[i] == 0)
        {
            res[x] = 'A' + i;
            for (int j = 0; j < 26; j++)
                if (has[j] && a[i][j]) du[j] --;
            has[i] = 0;
            dfs(x + 1);
            has[i] = 1;
            for (int j = 0; j < 26; j++)
                if (has[j] && a[i][j]) du[j] ++;
        }
}
int main()
{
    int w, h;
    while (scanf("%d %d", &h, &w) == 2)
    {
        char s[30][33];
        for (int i = 0; i < h; i++) scanf("%s", s[i]);
        memset(a, 0, sizeof(a));
        memset(du, 0, sizeof(du));
        memset(has, 0, sizeof(has));
        int si[26], sj[26], ei[26], ej[26];
        for (int i = 0; i < 26; i++)
        {
            si[i] = sj[i] = 100;
            ei[i] = ej[i] = -1;
        }
        for (int i = 0; i < h; i ++)
            for (int j = 0; j < w; j++)
            {
                if (s[i][j] != '.')
                {
                    int id = s[i][j] - 'A';
                    si[id] = min(si[id], i);
                    sj[id] = min(sj[id], j);
                    ei[id] = max(ei[id], i);
                    ej[id] = max(ej[id], j);
                    has[id] = 1;
                }
            }
        for (int c = 0; c < 26; c ++)
            if (has[c])
            {
                for (int i = si[c]; i <= ei[c]; i++)
                {
                    if (s[i][sj[c]] - 'A' != c) a[c][s[i][sj[c]] - 'A'] = 1;
                    if (s[i][ej[c]] - 'A' != c) a[c][s[i][ej[c]] - 'A'] = 1;
                }
                for (int j = sj[c] + 1; j < ej[c]; j++)
                {
                    if (s[si[c]][j] - 'A' != c) a[c][s[si[c]][j] - 'A'] = 1;
                    if (s[ei[c]][j] - 'A' != c) a[c][s[ei[c]][j] - 'A'] = 1;
                }
            }
        n = 0;
        for (int c = 0; c < 26; c ++)
            if (has[c])
            {
                for (int k = 0; k < 26; k++)
                    if (a[k][c]) du[c] ++;
                n++;
            }
        dfs(0);
    }
    return 0;
}