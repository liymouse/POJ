#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define NUM 1000

typedef struct
{
    int a[100];
    int L;
}Num;

void initNum(Num &a, char *s)
{
    int L = strlen(s);
    a.L = 0;
    memset(a.a, 0, sizeof(a.a));
    int t = 1;
    for (int i = L - 1; i >= 0; i--)
    {
        if (t == NUM) { t = 1; a.L++; }
        a.a[a.L] += (s[i] - '0') * t;
        t *= 10;
    }
    a.L++;
}

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
    return c - 'a' + 1;
}
char changeback(int x)
{
    return x + 'a' - 1;
}
//a = a + b
void add(Num &a, int b)
{
    a.a[0] += b;
    fix(a);
}
//a = a - b
void sub(Num &a, int b)
{
    a.a[0] -= b;
    for (int i = 0; i < a.L; i ++)
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

void convert26to10(Num &a, char *s, int base)
{
    memset(a.a, 0, sizeof(a.a));
    a.L = 1; a.a[0] = 0;
    int L = strlen(s);
    for (int i = 0; i < L; i++)
    {
        mul(a, base);
        add(a, change(s[i]));
    }
}
void convert10to26(char *s, int base, Num &a)
{
    int L = 0;
    //if (a.L == 1 && a.a[0] == 0) { s[0] = 'a'; return; }
    while (!(a.L == 1 && a.a[0] == 0)) //a != 0
    {
        sub(a, 1);
        s[L] = changeback(mod(a, base)+1);

        div(a, base);
        L++;
    }
}

int main()
{
    char s[100];
    while (scanf("%s", s) == 1)
    {
        if (s[0] == '*') break;
        if ('0' <= s[0] && s[0] <= '9') //10 to 26
        {
            Num a, b;
            initNum(a, s);
            b = a;
            memset(s, 0, sizeof(s));
            convert10to26(s, 26, b);
            int L = strlen(s);
            for (int i = L - 1; i >= 0; i--) printf("%c", s[i]);
            for (int i = L; i < 22; i++) printf(" ");
            printf("%d", a.a[a.L - 1]);
            for (int i = a.L - 2; i >= 0; i--) printf(",%03d", a.a[i]);
            printf("\n");
        }
        else //26 to 10
        {
            Num a;
            convert26to10(a, s, 26);
            printf("%-20s  ", s);
            printf("%d", a.a[a.L - 1]);
            for (int i = a.L - 2; i >= 0; i--) printf(",%03d", a.a[i]);
            printf("\n");
        }
    }
    return 0;
}