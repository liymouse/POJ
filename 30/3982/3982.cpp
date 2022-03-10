#include <stdio.h>

int main()
{
    int t[3];
    while (scanf("%d %d %d" , &t[0] , &t[1] , &t[2]) == 3)
    {
        int x = 0 , y = 1 , z = 2 , w = 3;
        int len = 0 , a[4][100] = {0};
        for (int i = 0; i < 3; i ++)
        {
            int L = 0;
            while (t[i]) {a[i][L ++] = t[i] % 10; t[i] /= 10;}
            len = (L > len) ? L : len;
        }
        for (int ti = 3; ti <= 99; ti ++)
        {
            for (int i = 0; i < len; i ++)
                a[w][i] = a[x][i] + a[y][i] + a[z][i];
            for (int i = 0; i < len; i ++)
                if (a[w][i] > 9)
                {
                    int tmp = a[w][i] / 10;
                    a[w][i+1] += tmp;
                    a[w][i] -= tmp * 10;
                }
            if (a[w][len] > 0) len ++;
            x = y; y = z; z = w; w ++;
            if (w == 4) w = 0;
        }
        for (int i = len-1; i >= 0; i --) printf("%d" , a[z][i]);
        printf("\n");
    }

    return 0;
}
