#include <stdio.h>

int main()
{
    int ca;
    scanf("%d" , &ca);
    while (ca --)
    {
        int m , n , x;
        int a[101] = {0};
        scanf("%d %d" , &m , &n);
        for (int i = 0; i < m; i ++)
        {
            scanf("%d" , &x);
            a[x] = 1;
        }
        for (int i = 0; i < n; i ++)
        {
            scanf("%d" , &x);
            if (a[x] < 2) a[x] += 2;
        }
        int L = 0, b = 0;
        int maxL = 0 , maxb;
        for (int i = 100; i >= 0; i --)
            if (a[i] > 0)
            {
                if (a[i] == 3)
                {
                    if (L == 0) b = i;
                    L ++;
                }
                else
                {
                    if (L > maxL) {maxL = L; maxb = b;}
                    L = 0;
                }
            }
        if (L > maxL) {maxL = L; maxb = b;}
        if (maxL == 0) printf("NONE\n");
        else
        {
            int sc[101] , k = 0;
            for (int i = maxb; i >= 0; i --)
                if (a[i] > 0)
                {
                    if (a[i] == 3) sc[k++] = i;
                    else break;
                }
            for (int i = 0; i < maxL-1; i ++) printf("%d " , sc[i]);
            printf("%d\n" , sc[maxL-1]);
            for (int i = 0; i < maxL; i ++)
                for (int j = 1; j < maxL-i; j ++)
                {
                    if ((sc[j-1]%10 > sc[j]%10) ||
                        (sc[j-1]%10 == sc[j]%10 && sc[j-1] > sc[j]))
                    {
                        int tmp = sc[j-1]; sc[j-1] = sc[j]; sc[j] = tmp;
                    }
                }
            for (int i = 0; i < maxL-1; i ++) printf("%d " , sc[i]);
            printf("%d\n" , sc[maxL-1]);
        }
    }
    return 0;
}