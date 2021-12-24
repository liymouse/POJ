#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    int a[310];
    int n;
}Num;
void set(Num &a, int b)
{
    memset(a.a, 0, sizeof(a.a));
    if (b == 0) { a.n = 1; a.a[0] = 0; return; }
    a.n = 0;
    while (b)
    {
        a.a[a.n++] = b % 10;
        b /= 10;
    }
}
void mult(Num &a, int b)
{
    for (int i = 0; i < a.n; i++)
        a.a[i] *= b;
    for (int i = 0; i < a.n; i++)
        if (a.a[i] > 9) { a.a[i + 1] += a.a[i] / 10; a.a[i] %= 10; }
    while (a.a[a.n] > 0)
    {
        if (a.a[a.n] > 9) { a.a[a.n + 1] += a.a[a.n] / 10; a.a[a.n] %= 10; }
        a.n++;
    }
}
void dec(Num &a)
{
    a.a[0] --;
    int i = 0;
    while (a.a[i] < 0)
    {
        a.a[i] += 10;
        a.a[i + 1] --;
        i++;
    }
    while (a.n > 0 && a.a[a.n - 1] == 0) a.n--;
}
//a must >= b
void sub(Num &a, Num &b)
{
    for (int i = 0; i < b.n; i++)
        a.a[i] -= b.a[i];
    for (int i = 0; i < a.n; i ++)
        if (a.a[i] < 0)
        {
            a.a[i] += 10;
            a.a[i + 1] --;
        }
    if (a.a[a.n - 1] == 0) a.n--;
}
void add(Num &a, Num &b)
{
    if (b.n > a.n) a.n = b.n;
    for (int i = 0; i < a.n; i++)
        a.a[i] += b.a[i];
    for (int i = 0; i < a.n; i++)
        if (a.a[i] > 9) { a.a[i + 1] += a.a[i] / 10; a.a[i] %= 10; }
    while (a.a[a.n] > 0)
    {
        if (a.a[a.n] > 9) { a.a[a.n + 1] += a.a[a.n] / 10; a.a[a.n] %= 10; }
        a.n++;
    }
}
void multAB(Num &a, Num &b)
{
    Num res;
    set(res, 0);
    for (int i = 0; i < b.n; i++)
    {
        Num c = a;
        mult(c, b.a[i]);
        for (int j = c.n - 1 + i; j >= i; j--) c.a[j] = c.a[j - i];
        for (int j = i - 1; j >= 0; j--) c.a[j] = 0;
        c.n += i;
        add(res, c);
    }
    a = res;
}
int main()
{
    int n;
    Num p2[10];
    set(p2[0], 2);
    for (int i = 1; i < 10; i++)
    {
        p2[i] = p2[i - 1];
        multAB(p2[i], p2[i - 1]);
    }
    scanf("%d", &n);
    Num res;
    set(res, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x)
        {
            //calc 2^i - 1
            Num t;
            set(t, 1);
            x = i;
            int p = 0;
            while (x)
            {
                if (x & 1) multAB(t, p2[p]);
                p++;
                x >>= 1;
            }
            dec(t);
            sub(t, res);
            res = t;
        }
    }
    for (int i = res.n - 1; i >= 0; i--) printf("%d", res.a[i]);
    printf("\n");
    return 0;
}