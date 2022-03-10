#include <stdio.h>

int main()
{
    int n , t , ca = 1;
    while (scanf("%d %d" , &n , &t) == 2)
    {
        if (n == 0 && t == 0) break;
        int a[250][250] = {0};
        int res = 0;
        for (int i = 1; i <= n; i ++) a[i][i] = 1;
        for (int i = 0; i < t; i ++)
        {
            int x , y;
            scanf("%d %d" , &x , &y);
            if (a[y][x]) res ++;
            else if (a[x][y] == 0)
            {
                a[x][y] = 1;
                for (int j = 1; j <= n; j ++)
                    if (a[j][x])
                    {
                        a[j][y] = 1;
                        for (int k = 1; k <= n; k ++) if (a[y][k]) a[j][k] = 1;
                    }
            }
        }
        printf("%d. %d\n" , ca ++ , res);
    }
    return 0;
}