#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char p[32768] = { 0 };
int a[3530];

int main()
{
    for (int i = 2; i * i < 32768; i++)
        if (p[i] == 0)
        {
            int k = i + i;
            while (k < 32768) { p[k] = 1; k += i; }
        }
    int num = 0;
    for (int i = 2; i < 32768; i++) if (p[i] == 0) a[num++] = i;
    //printf("%d", num);
    int n;
    while (scanf("%d", &n) == 1)
    {
        int t = n - 1;
        int res = t;
        for (int i = 0; i < num; i++)
            if (t % a[i] == 0)
            {
                res = res * (a[i] - 1) / a[i];
                while (t % a[i] == 0) t /= a[i];
                if (t == 1) break;
            }
        printf("%d\n", res);
    }
    return 0;
}