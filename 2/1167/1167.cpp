#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int t[60] = { 0 };
int n, res = 17;

void find(int num)
{
    if (num >= res) return;
    if (n == 0 && num < res) {
        res = num; return;
    }
    int i = 0;
    while (t[i] == 0) i++;
    for (int j = i+1; j < 60; j ++)
        if (t[j])
        {
            int sub = j - i;
            int can = 1;
            for (int k = i; k < 60; k += sub) if (t[k] == 0) { can = 0; break; }
            if (can)
            {
                for (int k = i; k < 60; k += sub) { t[k] --; n --; }
                find(num + 1);
                for (int k = i; k < 60; k += sub) { t[k] ++; n ++; }
            }
        }
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        memset(t, 0, sizeof(t));
        res = 17;
        int x;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x); t[x] ++;
        }
        find(0);
        printf("%d\n", res);
    }
    return 0;
}