#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

char table[16000000];
int word[256];
int word2[256];
char s[10000000];
int p[25];

int main()
{
    int n, nc;
    while (scanf("%d %d", &n, &nc) == 2)
    {
        scanf("%s", s);
        int L = strlen(s);
        int cur = 0;
        if (n > L) {
            printf("0\n"); continue;
        }
        memset(table, 0, sizeof(table));
        memset(word, 0xff, sizeof(word));
        p[0] = 1;
        for (int i = 1; i <= n; i++) p[i] = p[i - 1] * nc;
        int v = 0;
        for (int i = 0; i < n; i++)
        {
            if (word[s[i]] == -1)
            {
                word[s[i]] = cur;
                word2[s[i]] = cur * p[n - 1];
                cur++;
            }
            v = v * nc + word[s[i]];
        }
        table[v] = 1;
        for (int i = n; i < L; i++)
        {
            if (word[s[i]] == -1)
            {
                word[s[i]] = cur;
                word2[s[i]] = cur * p[n - 1];
                cur++;
            }
            v = v - word2[s[i - n]];
            v = v * nc + word[s[i]];
            table[v] = 1;
        }
        int res = 0;
        for (int i = 0; i < p[n]; i++) if (table[i]) res++;
        printf("%d\n", res);
    }
    return 0;
}