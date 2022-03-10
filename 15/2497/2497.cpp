#include <stdio.h>

int main()
{
int t , h , n , x , total;
int i , j , k;
int tot1 , tot2 , tot3 , max , min , tot;
int s1 , s2 , s3;
int a[24] , time[24];

    scanf("%d" , &t);
    for (h = 1; h <= t; h ++)
    {
        scanf("%d %d" , &total , &n);
        tot1 = 0; tot2 = 0; tot3 = 0;
        s1 = 0; s2 = 0; s3 = 0;
        for (i = 0; i < n; i ++)
            scanf("%d" , &a[i]);
        x = total;
        for (i = 0; i < n; i ++) time[i] = 0;
        time[0] = a[0];
        for (i = 1; i < n; i ++) time[i] = time[i-1] + a[i];
        for (i = 0; i < n; i ++)
            if (x >= a[i]) {x -= a[i]; tot1 ++; s1 += time[i];}
            else break;
        for (i = 0; i < n; i ++)
            for (j = 1; j < n - i; j ++)
                if (a[j-1] > a[j]) {k = a[j-1]; a[j-1] = a[j]; a[j] = k;}
        x = total;
        for (i = 0; i < n; i ++) time[i] = 0;
        time[0] = a[0];
        for (i = 1; i < n; i ++) time[i] = time[i-1] + a[i];
        for (i = 0; i < n; i ++)
            if (x >= a[i]) {x -= a[i]; tot2 ++; s2 += time[i];}
            else break;
        for (i = 0; i < n; i ++)
            for (j = 1; j < n - i; j ++)
                if (a[j-1] < a[j]) {k = a[j-1]; a[j-1] = a[j]; a[j] = k;}
        x = total;
        for (i = 0; i < n; i ++) time[i] = 0;
        time[0] = a[0];
        for (i = 1; i < n; i ++) time[i] = time[i-1] + a[i];
        for (i = 0; i < n; i ++)
            if (x >= a[i]) {x -= a[i]; tot3 ++; s3 += time[i];}
        printf("Scenario #%d:\n" , h);
        if (tot1 > tot2) max = tot1; else max = tot2;
        if (max < tot3) max = tot3;
        tot = 0;
        if (tot1 == max) tot ++;
        if (tot2 == max) tot ++;
        if (tot3 == max) tot ++;
        if (tot == 1)
        {
            if (tot1 == max) printf("Bill wins with %d solved problems and a score of %d.\n" , max , s1);
            else if (tot2 == max) printf("Steve wins with %d solved problems and a score of %d.\n" , max , s2);
            else printf("Linus wins with %d solved problems and a score of %d.\n" , max , s3);
        }
        else
        {
            min = 32767;
            if ((tot1 == max) && (s1 < min)) min = s1;
            if ((tot2 == max) && (s2 < min)) min = s2;
            if ((tot3 == max) && (s3 < min)) min = s3;
            tot = 0;
            if ((tot1 == max) && (s1 == min)) tot ++;
            if ((tot2 == max) && (s2 == min)) tot ++;
            if ((tot3 == max) && (s3 == min)) tot ++;
            if (tot == 1)
            {
                if ((tot1 == max) && (s1 == min)) printf("Bill wins with %d solved problems and a score of %d.\n" , max , s1);
                else if ((tot2 == max) && (s2 == min)) printf("Steve wins with %d solved problems and a score of %d.\n" , max , s2);
                else printf("Linus wins with %d solved problems and a score of %d.\n" , max , s3);
            }
            else printf("Steve wins with %d solved problems and a score of %d.\n" , tot2 , s2);
        }
        printf("\n");
    }
    return 0;
}
