#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[4] = { 2, 6, 8, 4 };
int getShift(int n)
{
    if (n < 2) return 0;
    // *1 = +0, *2 = +3, *3 = +1, *4 = +2, *5 = special
    // *6 = +0, *7 = +3, *8 = +1, *9 = +2
    int shift = ((n / 10 + (n % 10 >= 2)) + (n / 10 + (n % 10 >= 7))) * 3 % 4;
    shift = (shift + (n / 10 + (n % 10 >= 3)) + (n / 10 + (n % 10 >= 8))) % 4;
    shift = (shift + ((n / 10 + (n % 10 >= 4)) + (n / 10 + (n % 10 >= 9))) * 2) % 4;
    return shift;
}
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n <= 1 || m == 0) {
            printf("1\n"); continue;
        }
        int t = a[(1 + getShift(n) + 4 - getShift(n-m)) % 4];
        int num5 = n / 10 + (n % 10 >= 5) - ((n-m) / 10 + ((n-m) % 10 >= 5));
        while (num5)
        {
            t *= num5;
            if (t % 10 == 0) t /= 10;
            if (t % 10 == 5) break;
        }
        printf("%d\n", t);
    }
    return 0;
}
