#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))

int main()
{
    int n, m, k;
    while (scanf("%d,%d,%d", &n, &m, &k) == 3)
    {
        int baby[100] = { 0 };
        int parent[100] = { 0 };
        int born[100] = { 0, 1 };
        int growup[100] = { 0 };
        for (int i = 1; i <= k; i++)
        {
            if (growup[i])
            {
                for (int j = 0; j <= n - 7; j++) parent[i + j] += growup[i];
                born[i] += growup[i]; //7th month born 1 pair
                born[i + 1] += growup[i]; //8th month born 1 pair
                for (int j = 2; j <= min(n-7, m+1); j ++) born[i + j] += 2 * growup[i]; //9th ~ (8+m)th month born 2pairs in each month
            }
            if (born[i])
            {
                if (baby[i] + parent[i] <= 100)
                {
                    growup[i + 6] = born[i];
                    for (int j = 0; j < 6; j++) baby[i+j] += born[i];
                }
            }
        }
        printf("%d,%d,%d: %d\n", n, m, k, parent[k] + baby[k]);
    }
}