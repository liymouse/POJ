#include <stdio.h>
#include <string.h>

char a[30];
char b[30];
int n;

//choose k from m
int c(int m, int k)
{
    long long res = 1;
    if (k == 0 || m == k) return 1;
    if (k > m - k) k = m - k;
    for (int i = 1; i <= k; i++)
        res = res * (m + 1 - i);
    for (int i = 1; i <= k; i++)
        res /= i;
    return (int)res;
}

int cal(int sa, int ea, int sb, int eb)
{
    if (sa == ea) return 1;

    int res = 1;
    int child_num = 0;
    //skip root
    sa++; eb--;
    while (sa <= ea)
    {
        int k = -1;
        for (int i = eb; i >= sb; i --)
            if (b[i] == a[sa]) { k = i; break; }
        res *= cal(sa, sa + k - sb, sb, k);
        child_num++;
        sa = sa + k - sb + 1;
        sb = k + 1;
    }
    res *= c(n, child_num);
    return res;
}
int main()
{
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        scanf("%s %s", a, b);
        int L = strlen(a);
        printf("%d\n", cal(0, L - 1, 0, L - 1));
    }
    return 0;
}