#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int out[55][26] = { 0 };
    int a[55][55] = { 0 };
    int num[55] = { 0 };
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char s[50];
        scanf("%s", s);
        if (s[0] != '.')
        {
            for (int j = 0; j < strlen(s); j++) out[i][s[j] - 'A'] = 1;
        }
        scanf("%s", s);
        if (s[0] != '.')
        {
            for (int j = 0; j < strlen(s); j++) out[i][s[j] - 'A'] = -1;
        }
    }
    int x, y;
    while (scanf("%d %d", &x, &y) == 2)
    {
        if (x == 0 && y == 0) break;
        a[x][num[x]++] = y;
    }
    while (1)
    {
        int change = 0;
        for (int i = 1; i <= n; i ++)
            for (int k = 0; k < 26; k ++)
                if (out[i][k] > 0)
                {
                    for (int j = 0; j < num[i]; j++)
                        if (out[a[i][j]][k] == 0)
                        {
                            change = 1;
                            out[a[i][j]][k] = 1;
                        }
                }
        if (change == 0) break;
    }
    for (int i = 1; i <= n; i++)
    {
        printf(":");
        for (int j = 0; j < 26; j++)
            if (out[i][j] > 0) printf("%c", 'A' + j);
        printf(":\n");
    }
}