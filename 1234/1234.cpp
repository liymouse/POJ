#include <stdio.h>

int main()
{
    int a[33], n;
    //freopen("1234.in", "r", stdin);
    //freopen("1234.out", "w", stdout);
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        int to;
        scanf("%d", &to);
        to--;
        for (int i = 0; i < n; i++)
        {
            char s[3];
            scanf("%s", s);
            a[i] = s[0] == 'L' ? -1 : 1;
        }
        int mark[33] = { 0 };
        int t = 1;
        int cur = 0;
        int last = n;
        while (t <= 100000)
        {
            if (mark[to] == 0) {
                mark[to] = 1; last--;
            }
            if (last == 0) break;
            int tmp = to;
            to = (cur + a[to] + n) % n;
            if (tmp == to) to = (to + a[to] + n) % n;
            a[tmp] = -a[tmp];
            cur = tmp;
            t++;
        }
        printf("Classmate %d got the ball last after %d tosses.\n", to + 1, t);
    }

    return 0;
}