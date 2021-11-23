#include <stdio.h>

int main()
{
    int n;
    int order[10];
    char s[200];
    int ca = 1;

    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        char x[20];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", x);
            order[i] = x[1] - '1';
        }
        scanf("%s", s);
        int m;
        scanf("%d", &m);
        printf("S-Tree #%d:\n", ca++);
        for (int i = 0; i < m; i++)
        {
            scanf("%s", x);
            int t = 0;
            for (int j = 0; j < n; j++)
            {
                t = t * 2 + x[order[j]] - '0';
            }
            printf("%c", s[t]);
        }
        printf("\n\n");
    }
    return 0;
}