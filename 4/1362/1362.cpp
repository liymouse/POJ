#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int base[27];
int a[100], t;

void change(int x)
{
    if (x == 0) return;
    int k = 26;
    while (k >= 0 && base[k] > x) k--;
    if (base[k] * 2 == x) { a[t] = k; a[t + 1] = k; t += 2; return; }
    a[t] = k; t++;
    change(x - base[k]);
}
int main()
{
    base[0] = 1;
    for (int i = 1; i < 27; i++) base[i] = base[i - 1] * 2 + 1;
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        printf("%d [", n);
        t = 0;
        change(n);
        for (int i = t - 1; i > 0; i--) printf("%d,", a[i]);
        if (t > 0) printf("%d", a[0]);
        printf("]\n");
    }
    return 0;
}