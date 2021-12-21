#include <stdio.h>
#include <string.h>

int main()
{
    int a[26][26] = { 0 };
    char s[1000];
    while (scanf("%s", s) == 1)
    {
        if (strcmp(s, "deadend") == 0)
        {
            int res = 0;
            int odd[2], n = 0;
            for (int i = 0; i < 26; i++)
            {
                int num = 0;
                for (int j = 0; j < 26; j++)
                    if (i != j && a[i][j] > 0)
                    {
                        num++;
                        res += a[i][j];
                    }
                if (num % 2 == 1) odd[n++] = i;
            }
            if (n == 0)
            {
                printf("%d\n", res / 2);
            }
            else
            {
                int mark[26] = { 0 };
                int dist[26];
                int s = odd[0];
                for (int i = 0; i < 26; i++) if (a[s][i] > 0) dist[i] = a[s][i]; else dist[i] = 1 << 30;
                mark[s] = 1;
                for (int i = 1; i < 26; i++)
                {
                    int minv = 1 << 30;
                    int k = -1;
                    for (int j = 0; j < 26; j ++)
                        if (mark[j] == 0 && dist[j] < minv) { minv = dist[j]; k = j; }
                    if (k == -1) break;
                    mark[k] = 1;
                    for (int j = 0; j < 26; j ++)
                        if (mark[j] == 0 && a[k][j] > 0 && dist[k] + a[k][j] < dist[j])
                        {
                            dist[j] = dist[k] + a[k][j];
                        }
                }
                printf("%d\n", res / 2 + dist[odd[1]]);
            }
            memset(a, 0, sizeof(a));
        }
        int L = strlen(s);
        a[s[0] - 'a'][s[L - 1] - 'a'] = L;
        a[s[L - 1] - 'a'][s[0] - 'a'] = L;
    }
    return 0;
}