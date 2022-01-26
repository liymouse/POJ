#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NUM 1000

typedef struct
{
    int a[100];
    int L;
}Num;

void fix(Num &a)
{
    for (int i = 0; i < a.L; i++)
        if (a.a[i] >= NUM)
        {
            a.a[i + 1] += a.a[i] / NUM;
            a.a[i] %= NUM;
        }
    if (a.a[a.L] > 0) a.L++;
    while (a.L > 1 && a.a[a.L - 1] == 0) a.L--;
}
//a = a + b
void add(Num &a, int b)
{
    a.a[0] += b;
    fix(a);
}
//a = a + b
void add2(Num &a, Num &b)
{
    if (b.L > a.L) a.L = b.L;
    for (int i = 0; i < a.L; i++)
        a.a[i] += b.a[i];
    fix(a);
}
//a = a - b
void sub(Num &a, int b)
{
    a.a[0] -= b;
    for (int i = 0; i < a.L; i++)
        if (a.a[i] < 0) { a.a[i] += 10; a.a[i + 1] --; }
        else break;
    fix(a);
}
//a = a * b
void mul(Num &a, int b)
{
    for (int i = 0; i < a.L; i++) a.a[i] *= b;
    fix(a);
}
//return = a % b
int mod(Num &a, int b)
{
    int k = 1;
    int r = 0;
    for (int i = 0; i < a.L; i++)
    {
        r = r + (a.a[i] * k) % b;
        k = (k * NUM) % b;
    }
    return r % b;
}
//a = a / b
void div(Num &a, int b)
{
    int r = 0;
    for (int i = a.L - 1; i >= 0; i--)
    {
        int k = r * NUM + a.a[i];
        a.a[i] = k / b;
        r = k % b;
    }
    fix(a);
}
void print(Num &a)
{
    printf("%d", a.a[a.L - 1]);
    for (int i = a.L - 2; i >= 0; i--) printf("%03d", a.a[i]);
}

int main()
{
    int n;
    char c, s[10];
    Num p[51] = { 0 };
    p[0].L = 1; p[0].a[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        p[i] = p[i - 1];
        mul(p[i], i);
    }
    int first = 1;
    while (scanf("%c", &c) == 1)
    {
        if (c == '-') { printf("\n"); break; }
        scanf("%d", &n);
        scanf("%c", &c);
        int a[55];
        for (int i = 0; i < n; i++) scanf("%c%d", &c, &a[i]);
        gets_s(s);
        Num res = { 0 };
        res.L = 1; res.a[0] = 1;
        for (int i = 0; i < n; i++)
        {
            int num = 0;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[i]) num++;
            if (num > 0)
            {
                Num b = p[n - i - 1];
                mul(b, num);
                add2(res, b);
            }
        }
        if (first == 0) printf(",");
        else first = 0;
        print(res);
    }
    return 0;
}