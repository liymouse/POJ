#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define chop(a,b,c) ((a)<(b)?(b):((a)>(c)?(c):(a)))

int main()
{
    int d;
    int f[16];
    int a[2][22][22] = { 0 };
    int p = 0;
    scanf("%d", &d);
    for (int i = 0; i < 16; i++) scanf("%d", &f[i]);
    for (int i = 1; i <= 20; i++) 
        for (int j = 1; j <= 20; j ++) 
            scanf("%d", &a[p][i][j]);
    while (d--)
    {
        for (int i = 1; i <= 20; i ++)
            for (int j = 1; j <= 20; j++)
            {
                a[1 - p][i][j] = a[p][i][j] + f[a[p][i][j] + a[p][i - 1][j] + a[p][i][j - 1] + a[p][i + 1][j] + a[p][i][j + 1]];
                a[1 - p][i][j] = chop(a[1 - p][i][j], 0, 3);
            }
        p = 1 - p;
    }
    for (int i = 1; i <= 20; i++)
    {
        for (int j = 1; j <= 20; j++)
            if (a[p][i][j] == 0) printf(".");
            else if (a[p][i][j] == 1) printf("!");
            else if (a[p][i][j] == 2) printf("X");
            else printf("#");
        printf("\n");
    }
    return 0;
}