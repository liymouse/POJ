#include <stdio.h>


int main()
{
    int m, n;
    int a[60][60] = { 0 };
    int wc, p;
    int v[2501];
    int bc[2501];
    int x, y;
    scanf("%d %d %d %d", &m, &n, &wc, &p);
    for (int i = 1; i <= p; i++)
    {
        
        scanf("%d %d %d %d", &x, &y, &v[i], &bc[i]);
        a[x][y] = i;
    }
    int dir, life;
    int d[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    int tot = 0;
    while (scanf("%d %d %d %d", &x, &y, &dir, &life) == 4)
    {
        int sum = 0;
        while (life > 0)
        {
            int xx = x + d[dir][0];
            int yy = y + d[dir][1];
            life--;
            if (xx == 1 || xx == m || yy == 1 || yy == n || a[xx][yy] > 0)
            {
                dir = (dir + 3) % 4;
                if (life > 0)
                {
                    if (a[xx][yy]) { sum += v[a[xx][yy]]; life -= bc[a[xx][yy]]; }
                    else life -= wc;
                }
            }
            else
            {
                x = xx;
                y = yy;
            }
        }
        tot += sum;
        printf("%d\n", sum);
    }
    printf("%d\n", tot);

    return 0;
}