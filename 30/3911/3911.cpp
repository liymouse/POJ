#include <stdio.h>

int main()
{
    int n , c;
    while (scanf("%d %d" , &n , &c) == 2)
    {
        if (n >= c || n == 0) {printf("0\n"); continue;}
        int t = c / (2 * n);
        if ((t+1)*(c-(t+1)*n) > t*(c-t*n)) t ++;
        printf("%d\n" , t);
    }
    return 0;
}
