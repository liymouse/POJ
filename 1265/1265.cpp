#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int gcd(int x, int y)
{
    while (y != 0)
    {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

#define cha(x1, y1, x2, y2) (x1 * y2 - x2 * y1)

int main()
{
    int cas;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        int m;
        int I = 0, E = 0;
        int prex = 0, prey = 0;
        int curx, cury;
        double area = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int dx, dy;
            scanf("%d %d", &dx, &dy);
            if (i < m - 1)
            {
                curx = prex + dx;
                cury = prey + dy;
                if (i > 0)
                {
                    area += cha(prex, prey, curx, cury);
                }
                prex = curx; prey = cury;
            }
            E += gcd(abs(dx), abs(dy));
        }
        area /= 2.0;
        I = area + 1 - E / 2.0;
        printf("Scenario #%d:\n%d %d %.1lf\n\n", ca, I, E, area);
    }
    return 0;
}