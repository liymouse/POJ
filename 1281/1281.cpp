#include <stdio.h>

int main()
{
    int m;
    while (scanf("%d", &m) == 1)
    {
        int num[10001] = { 0 };
        int rl[10000];
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &rl[i]);
        int minv = m + 1;
        int maxv = -1;
        char s[10];
        int count = 0;
        int p = 1;
        int t = 0;
        while (scanf("%s", s) == 1)
        {
            if (s[0] == 'e') { printf("\n"); break; }
            if (s[0] == 'a')
            {
                int x;
                scanf("%d", &x);
                num[x] ++;
                if (x > maxv) maxv = x;
                if (x < minv) minv = x;
            }
            else if (s[0] == 'p')
            {
                scanf("%d", &p);
            }
            else
            {
                count++;
                int k = -1;
                if (p == 1) //min
                {
                    if (minv != m + 1)
                    {
                        k = minv;
                        num[minv] --;
                        while (minv <= m && num[minv] == 0) minv++;
                    }
                }
                else
                {
                    if (maxv != -1)
                    {
                        k = maxv;
                        num[maxv] --;
                        while (maxv >= 0 && num[maxv] == 0) maxv--;
                    }
                }
                if (count == rl[t]) {printf("%d\n", k); t++;}
            }
        }
    }
    return 0;
}