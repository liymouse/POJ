#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define NUM 10000

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
int change(char c)
{
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z') return c - 'A' + 10;
    return c - 'a' + 36;
}
char changeback(int x)
{
    if (x < 10) return '0' + x;
    if (x < 36) return x - 10 + 'A';
    return x - 36 + 'a';
}
//a = a + b
void add(Num &a, int b)
{
    a.a[0] += b;
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

void convertBto10(Num &a, char *s, int base)
{
    memset(a.a, 0, sizeof(a.a));
    a.L = 1; a.a[0] = 0;
    int L = strlen(s);
    for (int i = 0; i < L; i ++)
    {
        mul(a, base);
        add(a, change(s[i]));
    }
}
void convert10toB(char *s, int base, Num &a)
{
    int L = 0;
    if (a.L == 1 && a.a[0] == 0) { s[0] = '0'; return; }
    while (!(a.L == 1 && a.a[0] == 0)) //a != 0
    {
        s[L] = changeback(mod(a, base));
        div(a, base);
        L++;
    }
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int x, y;
        char str[1000] = { 0 };
        scanf("%d %d %s", &x, &y, str);
        printf("%d %s\n", x, str);
        Num a;
        convertBto10(a, str, x);
        memset(str, 0, sizeof(str));
        convert10toB(str, y, a);
        int L = strlen(str);
        printf("%d ", y);
        for (int i = L - 1; i >= 0; i--) printf("%c", str[i]);
        printf("\n\n");
    }
    return 0;
}