#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

char led[10][8] = { "YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", 
"YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY" };
int main()
{
    int n;
    char s[10][10];
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        if (n == 1) { printf("MATCH\n"); continue; }
        int ok = 1;
        for (int c = 9; c >= n-1; c--)
        {
            int bad[7] = { 0 };
            ok = 1;
            //match 0th
            for (int i = 0; i < 7; i++)
                if (led[c][i] == 'N' && s[0][i] == 'Y') { ok = 0; break; }
                else if (led[c][i] == 'Y' && s[0][i] == 'N') bad[i] = 1;
            int t = c;
            for (int j = 1; ok && j < n; j++)
            {
                t--;
                for (int i = 0; i < 7; i++)
                    if (bad[i] && s[j][i] == 'Y') { ok = 0; break; }
                    else if (led[t][i] == 'N' && s[j][i] == 'Y') { ok = 0; break; }
                    else if (led[t][i] == 'Y' && s[j][i] == 'N') bad[i] = 1;
            }
            if (ok == 1) break;
        }
        if (ok) printf("MATCH\n"); else printf("MISMATCH\n");
    }
    return 0;
}