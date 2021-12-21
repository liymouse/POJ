#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

char s[90];
int f[90]; // f[i][k] = 0~i, last word is f[i][k]~i
int first[90]; // 1st word is 0~first[i][k]
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
        memset(f, 0xff, sizeof(f));
        
        for (int i = 0; i < n; i++)
        {
            f[i] = 0;
        }
        for (int i = 1; i < n; i ++)
        {
            if (f[i-1] != -1)
            {
                f[i] = f[i-1];
            }
            for (int j = 0; j < i; j++)
            {
                if (f[j] != -1 && cmp(f[j], j, j+1, i) < 0)
                {
                    if (j + 1 > f[i]) f[i] = j + 1;
                }
            }
        }
        int sp[90] = { 0 };
        int x = n - 1;
        while (f[x]>0)
        {
            sp[f[x] - 1] = 1;
            x = f[x] - 1;
        }
        //if 1st num = 0, cancel it
        int cancel = 1;
        x = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '0') {
                cancel = 0; break;
            }
            if (sp[i]) {
                x = i; break;
            }
        }
        if (cancel && x != -1) sp[x] = 0;
        for (int i = 0; i < n; i++)
        {
            printf("%c", s[i]);
            if (sp[i]) printf(",");
        }
        printf("\n");
    }
}
#else
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

char s[90];
int f[90][90]; // f[i][k] = 0~i divied to k, last word is f[i][k]~i
int first[90][90]; // 1st word is 0~first[i][k]
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
        for (int i = 0; i < n; i++)
            for (int k = 1; k <= i + 1; k++) {
                f[i][k] = -1;
            }
        memset(first, 0, sizeof(first));

        for (int i = 0; i < n; i++)
        {
            f[i][1] = 0;
            first[i][1] = i;
        }
        for (int i = 1; i < n; i++)
            for (int k = 2; k <= i + 1; k++)
            {
                if (f[i - 1][k] != -1)
                {
                    f[i][k] = f[i - 1][k];
                    first[i][k] = first[i - 1][k];
                }
                for (int j = 0; j < i; j++)
                {
                    if (f[j][k - 1] != -1 && cmp(j + 1, i, f[j][k - 1], j) > 0)
                    {
                        int c = cmp(j + 1, i, f[i][k], i);
                        if (c < 0 || (c == 0 && cmp(0, first[j][k - 1], 0, first[i][k]) > 0))
                        {
                            f[i][k] = j + 1;
                            first[i][k] = first[j][k - 1];
                        }
                    }
                }
            }
        int minv = 0;
        int maxp = 0;
        int k = 1;
        for (int i = 1; i <= n; i++)
            if (f[n - 1][i] != 0 && (cmp(f[n - 1][i], n - 1, minv, n - 1) < 0 || (cmp(f[n - 1][i], n - 1, minv, n - 1) == 0 && cmp(0, first[n - 1][i], 0, maxp) > 0)))
            {
                minv = f[n - 1][i];
                maxp = first[n - 1][i];
                k = i;
            }
        int sp[90] = { 0 };
        int x = n - 1;
        while (k > 1)
        {
            sp[f[x][k] - 1] = 1;
            x = f[x][k] - 1;
            k--;
        }
        for (int i = 0; i < n; i++)
        {
            printf("%c", s[i]);
            if (sp[i]) printf(",");
        }
        printf("\n");
    }
}
#endif