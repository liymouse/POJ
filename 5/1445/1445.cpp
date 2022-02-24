#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NUM 10000000

typedef struct
{
    int a[20];
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
        else if (a.a[i] < 0)
        {
            a.a[i + 1] --;
            a.a[i] += NUM;
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
//a = a - b (only support a > b)
void sub2(Num &a, Num &b)
{
    for (int i = 0; i < a.L && i < b.L; i++)
        a.a[i] -= b.a[i];
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
void set(Num &a, int b)
{
    memset(a.a, 0, sizeof(a.a));
    a.L = 0;
    if (b == 0) { a.L = 1; return; }
    while (b)
    {
        a.a[a.L++] = b % NUM;
        b /= NUM;
    }
}
// -1: a<b  0:a=b  1:a>b
int cmp(Num &a, Num &b)
{
    if (a.L > b.L) return 1;
    else if (a.L < b.L) return -1;
    for (int i = a.L - 1; i >= 0; i--)
        if (a.a[i] > b.a[i]) return 1;
        else if (a.a[i] < b.a[i]) return -1;
    return 0;
}
Num f[201][201] = { 0 };

int main()
{
    int m, n;
    char s[430];
    while (scanf("%d %d", &m, &n) == 2)
    {
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= m; i++) set(f[1][i], 1);
        for (int i = 2; i <= n; i++)
            for (int j = i; j <= m; j++)
            {
                set(f[i][j], 0);
                for (int k = i - 1; k <= j; k++) add2(f[i][j], f[i - 1][k]);
            }
        Num B; set(B, 0);
        for (int i = n; i <= m; i++) add2(B, f[n][i]);
        //print(B); printf("\n");
        scanf("%s", s);
        Num A; set(A, 1);
        for (int i = 2; s[i] != 0; i++)
        {
            if (cmp(A, B) == 0) break;
            if (s[i] == '0') { add2(B, A); div(B, 2); }
            else { add2(A, B); div(A, 2); add(A, 1); }
        }
        //print(A); printf("\n");

        memset(f, 0, sizeof(f));
        for (int i = n; i <= m; i++) set(f[n][i], 1);
        for (int i = n-1; i >= 1; i --)
            for (int j = i; j <= m; j++)
            {
                set(f[i][j], 0);
                int sk = j > (i + 1) ? j : i + 1;
                for (int k = sk; k <= m; k++) add2(f[i][j], f[i + 1][k]);
            }
        //for (int i = 2; i <= m; i++) { print(f[2][i]); printf("\n"); }
        int pre = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = pre; j <= m; j++)
            {
                if (cmp(A, f[i][j]) <= 0)
                { 
                    pre = j;
                    printf("%d", j);
                    if (i < n) printf(" "); else printf("\n");
                    break;
                }
                sub2(A, f[i][j]);
            }
        }
    }
    return 0;
}
