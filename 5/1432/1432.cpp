#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char mo[26][5] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
int f[10001];
char word[10001][81];
int L[10001];

int main()
{
    int ca;
    scanf("%d", &ca);
    char s[10001];
    while (ca--)
    {
        scanf("%s", s);
        int n;
        scanf("%d", &n);
        char w[21];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", w);
            memset(word[i], 0, sizeof(word[i]));
            for (int j = 0; w[j] != 0; j++)
            {
                strcat(word[i], mo[w[j] - 'A']);
            }
            L[i] = strlen(word[i]);
        }
        memset(f, 0, sizeof(f));
        f[0] = 1;
        int Ls = strlen(s);
        for (int i = 0; i < Ls; i++)
            if (f[i])
            {
                for (int j = 0; j < n; j ++)
                    if (i + L[j] <= Ls)
                    {
                        int ok = 1;
                        for (int k = 0; k < L[j]; k ++)
                            if (s[i + k] != word[j][k]) { ok = 0; break; }
                        if (ok) f[i + L[j]] += f[i];
                    }
            }
        printf("%d\n", f[Ls]);
    }
    return 0;
}
