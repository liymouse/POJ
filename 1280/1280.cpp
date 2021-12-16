#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
int k, L;
double pa, pb;

void getP(double win[2], int first)
{
    double f[101][101][2] = { 0 };
    if (first == 0) f[0][0][0] = 1.0;
    else f[0][0][1] = 1.0;
    for (int i = 0; i <= L; i++)
        for (int j = 0; j <= L; j++)
        {
            if (i > 0) f[i][j][0] = f[i - 1][j][0] * pa + f[i - 1][j][1] * (1 - pb);
            if (j > 0) f[i][j][1] = f[i][j - 1][0] * (1 - pa) + f[i][j - 1][1] * pb;
        }
    win[0] = win[1] = 0;
    for (int i = 0; i < L; i++)
    {
        win[0] += f[L][i][0];
        win[1] += f[i][L][1];
    }
    //printf("%lf %lf\n", win[0], win[1]);
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int x, y;
        scanf("%d %d %d %d", &x, &y, &k, &L);
        pa = x / 100.0;
        pb = y / 100.0;
        double p[4]; //p[0] = A serves A win, p[1] = A serves B win, p[2] = Bserves Awin, p[3] = Bserves Bwin
        getP(p, 0);
        getP(p + 2, 1);
        //total i match, A wins j match, next match k serves
        double f[101][101][2] = { 0 };
        f[0][0][0] = 0.5;
        f[0][0][1] = 0.5;
        for (int i = 0; i <= k; i++)
            for (int j = 0; j < k; j++)
            {
                if (i > 0)
                {
                    f[i][j][0] += f[i - 1][j][1] * p[2];
                    f[i][j][1] += f[i - 1][j][0] * p[0];
                }
                if (j > 0 && i != k)
                {
                    f[i][j][0] += f[i][j - 1][1] * p[3];
                    f[i][j][1] += f[i][j - 1][0] * p[1];
                }
            }
        double res = 0;
        for (int i = 0; i < k; i++)
        {
            res += f[k][i][0] + f[k][i][1];
        }
        printf("%.1lf\n", res * 100);
    }
    return 0;
}
