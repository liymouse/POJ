#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[4] = { 2, 6, 8, 4 };
int getLast(int n, int m)
{
    if (n < 2 || m == n) return 1;
    // *1 = +0, *2 = +3, *3 = +1, *4 = +2
    // *6 = +0, *7 = +3, *8 = +1, *9 = +2
    // *5 = remove 2 or break 4, 6, 8
    int shift[10] = { 0, 0, 3, 1, 2, 0, 0, 3, 1, 2 };
    int num[11] = { 0 };
    for (int i = 1; i <= 10; i++)
        num[i] = (n + 10 - i) / 10 - (m + 10 - i) / 10;
    num[5] += num[10];
    for (int i = 2; i <= 9; i += 2)
    {
        int k = (num[i] < num[5]) ? num[i] : num[5];
        num[i / 2] += k;
        num[i] -= k;
        num[5] -= k;
    }
    if (num[2] + num[4] + num[6] + num[8] > 0)
    {
        int t = 1;
        for (int i = 1; i <= 9; i++) t = (t + num[i] * shift[i]) % 4;
        return a[t];
    }
    else
    {
        int t = 1;
        for (int i = 0; i < num[3]; i++) t = (t * 3) % 10;
        for (int i = 0; i < num[5]; i++) t = (t * 5) % 10;
        for (int i = 0; i < num[7]; i++) t = (t * 7) % 10;
        for (int i = 0; i < num[9]; i++) t = (t * 9) % 10;
        return t;
    }
}
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2)
    {
        m = n - m;
        int res = getLast(n,m);
        while (n >= 5)
        {
            n /= 5; m /= 5;
            res = res * getLast(n, m);
            while (res % 10 == 0) res /= 10;
            res %= 10;
        }
        printf("%d\n", res);
    }
    return 0;
}
