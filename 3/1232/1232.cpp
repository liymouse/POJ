#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n, g;
        int res = 0, last;
        char a[10001][20];
        scanf("%d %d", &n, &g);
        int id[10001];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", a[i]);
            id[i] = i;
        }
        last = n;
        int stack = 0;
        while (last > 1)
        {
            int num[20] = { 0 };
            for (int i = 1; i < last; i++)
                for (int j = 0; j < g; j++)
                    if (a[0][j] == a[id[i]][j]) num[j] ++;
            int minv = num[0];
            int k = 0;
            for (int i = 1; i < g; i++)
                if (num[i] < minv)
                {
                    minv = num[i];
                    k = i;
                }
            if (a[0][k] == '0') stack++;
            for (int i = 1; i < last; i++)
                if (a[0][k] != a[id[i]][k])
                {
                    int tmp = id[i];
                    id[i] = id[last - 1];
                    id[last - 1] = tmp;
                    last--;
                    i--;
                }
            res++;
        }
        printf("%d\n", res + (stack>2));
    }
    return 0;
}