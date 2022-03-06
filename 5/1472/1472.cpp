#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 11
void dfs(int *res)
{
    char s[50];
    while (scanf("%s", s))
    {
        if (!strcmp(s, "LOOP"))
        {
            scanf("%s", s);
            int a[11] = { 0 };
            dfs(a);
            if (s[0] == 'n')
            {
                for (int i = 1; i < N; i++)
                    res[i] += a[i - 1];
            }
            else
            {
                int x = atoi(s);
                for (int i = 0; i < N; i++)
                    res[i] += x * a[i];
            }
        }
        else if (!strcmp(s, "OP"))
        {
            scanf("%s", s);
            if (s[0] == 'n') res[1] ++;
            else res[0] += atoi(s);
        }
        else if (!strcmp(s, "END")) break;
    }
}
int main()
{
    int cas;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        int a[11] = { 0 };
        dfs(a);
        printf("Program #%d\n", ca);
        printf("Runtime =");
        int first = 1;
        for (int i = N-1; i > 0; i --)
            if (a[i] > 0)
            {
                if (first) { printf(" "); first = 0; }
                else printf("+");
                if (a[i] > 1) printf("%d*", a[i]);
                printf("n");
                if (i > 1) printf("^%d", i);
            }
        if (first) printf(" %d", a[0]);
        else if (a[0] > 0) printf("+%d", a[0]);
        printf("\n\n");
    }
    return 0;
}
