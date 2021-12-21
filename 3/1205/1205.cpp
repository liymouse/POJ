#include <stdio.h>
typedef struct {
    char d[100];
    int L;
}Num;
#define max(a,b) ((a)>(b)?(a):(b))
//a = b + c
void add(Num &a, Num &b, Num &c)
{
    int L = max(b.L, c.L);
    a.L = L;
    for (int i = 0; i < L; i++)
    {
        a.d[i] += b.d[i] + c.d[i];
        if (a.d[i] >= 10) { a.d[i + 1]++; a.d[i] -= 10; }
    }
    if (a.d[L] > 0) a.L++;
}
//a = b + c + d
void add3(Num &a, Num &b, Num &c, Num &d)
{
    int L = max(b.L, max(c.L, d.L));
    a.L = L;
    for (int i = 0; i < L; i++)
    {
        a.d[i] += b.d[i] + c.d[i] + d.d[i];
        if (a.d[i] >= 10) { a.d[i + 1] += a.d[i] / 10; a.d[i] %= 10; }
    }
    if (a.d[L] > 0) a.L++;
}

int main()
{
    int n;
    Num f[101][3] = { 0 }; //0 = V, 1 = <, 2 = >
    f[0][0].L = 1; f[0][0].d[0] = 1;
    f[0][1].L = 1; f[0][1].d[0] = 0;
    f[0][2].L = 1; f[0][2].d[0] = 1;
    for (int i = 1; i < 100; i++)
    {
        add3(f[i][0], f[i - 1][0], f[i - 1][1], f[i - 1][2]);
        add (f[i][1], f[i - 1][0], f[i - 1][1]);
        add3(f[i][2], f[i - 1][0], f[i - 1][1], f[i - 1][2]);
    }
    while (scanf("%d", &n) == 1)
    {
        Num res = { 0 };
        add(res, f[n - 1][0], f[n - 1][1]);
        for (int i = res.L - 1; i >= 0; i--) printf("%d", res.d[i]);
        printf("\n");
    }
    return 0;
}