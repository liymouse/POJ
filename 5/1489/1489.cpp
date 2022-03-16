#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef long long lld;

char fu[6] = "|n98r";
void getNum(int &x, char *s)
{
    x = 0;
    for (int i = 0; s[i] != 0; i++)
        if (s[i] == '|') x += 1;
        else if (s[i] == 'n') x += 10;
        else if (s[i] == '9') x += 100;
        else if (s[i] == '8') x += 1000;
        else if (s[i] == 'r') x += 10000;
}
void getStr(char *s, int &L, lld x)
{
    int t = 0;
    L = 0;
    while (x && t < 5)
    {
        if (L > 0 && x % 10 > 0) s[L++] = ' ';
        for (int i = 0; i < x % 10; i++) s[L++] = fu[t];
        t++; x /= 10;
    }
    s[L] = 0;
}

int main()
{
    char a[100], b[100];
    int A, B;
    while (gets_s(a))
    {
        getNum(A, a);
        if (A == 0) continue;
        gets_s(b);
        getNum(B, b);
        int x = 1, La, Lb;
        int res = A * B;
        while (x <= B)
        {
            getStr(a, La, x);
            getStr(b, Lb, A);
            if (B & x) { a[La] = ' '; a[La + 1] = '*'; a[La + 2] = 0; }
            printf("%-34s%s\n", a, b);
            x *= 2;
            A *= 2;
        }
        getStr(a, La, res);
        printf("The solution is: %s\n", a);
    }
    return 0;
}
