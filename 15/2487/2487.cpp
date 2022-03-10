#include <stdio.h>

void qu(int a[] , int s , int t)
{
int i , j , x , y;
    
    i = s; j = t; x = a[(i+j)/2];
    while (i <= j)
    {
        while (a[i] > x) i ++;
        while (a[j] < x) j --;
        if (i <= j)
        {
            y = a[i]; a[i] = a[j]; a[j] = y;
            i ++; j --;
        }
    }
    if (s < j) qu(a , s , j);
    if (i < t) qu(a , i , t);
}

int main()
{
int t , h , n;
int a[1000] , tot;
long need;
int i;

    scanf("%d" , &t);
    for (h = 0; h < t; h ++)
    {
        scanf("%ld %d" , &need , &n);
        for (i = 0; i < n; i ++) scanf("%d" , &a[i]);
        qu(a , 0 , n - 1);
        tot = 0;
        for (i = 0; i < n; i ++)
        {
            if (need >= a[i])
            {
                need -= a[i]; tot ++;
            }
            else
            {
                need = 0; tot ++;
            }
            if (need == 0) break;
        }
        printf("Scenario #%d:\n" , h + 1);
        if (need == 0) printf("%d\n" , tot);
        else printf("impossible\n");
        printf("\n");
    }
    return 0;
}
