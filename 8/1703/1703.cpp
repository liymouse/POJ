#include <stdio.h>

int f[200002];

int get_father(int x)
{
    if (f[x] == x) return x;
    int d = get_father(f[x]);
    f[x] = d;
    return d;
}
int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int cur = 100000;
        for (int i = 0; i < 200002; i++) f[i] = i;
        for (int i = 0; i < m; i++)
        {
            char s[3];
            int x, y;
            scanf("%s %d %d", s, &x, &y);
            x--; y--;
            int fx = get_father(x);
            int fy = get_father(y);
            if (s[0] == 'D')
            {
                if (fx < 100000 && fy < 100000)
                {
                    f[fx] = cur;
                    f[fy] = cur + 1;
                    cur += 2;
                }
                else if (fx < 100000)
                {
                    f[fx] = (fy & 1) == 0 ? fy + 1 : fy - 1;
                }
                else if (fy < 100000)
                {
                    f[fy] = (fx & 1) == 0 ? fx + 1 : fx - 1;
                }
                else if (fx/2 != fy/2 && fx < fy)
                {
                    f[fy] = (fx & 1) == 0 ? fx + 1 : fx - 1;
                    if ((fy & 1) == 0) f[fy + 1] = fx;
                    else f[fy - 1] = fx;
                }
                else if (fx/2 != fy/2 && fx > fy)
                {
                    f[fx] = (fy & 1) == 0 ? fy + 1 : fy - 1;
                    if ((fx & 1) == 0) f[fx + 1] = fy;
                    else f[fx - 1] = fy;
                }
            }
            else
            {
                if (fx < 100000 || fy < 100000 || fx / 2 != fy / 2)
                    printf("Not sure yet.\n");
                else if (fx == fy)
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            }
        }
    }
    return 0;
}