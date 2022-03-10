#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define ER 1e-7
double a[110][110];
int n;

void gauss(){
    int i = 0 , j = 0;
    while (j < n)
    {
        int k = i;
        while (k < n && fabs(a[k][j]) < ER) k ++;
        if (k != i)
        {
            for (int col = j; col <= n; col ++) swap(a[i][col] , a[k][col]);
        }
        for (int col = n; col >= j; col --) a[i][col] /= a[i][j];
        for (int row = i + 1; row < n; row ++)
            if (a[row][j] != 0)
            {
                for (int col = n; col >= j; col --) a[row][col] -= a[i][col] * a[row][j];
            }
        j ++; i ++;
    }
    for (int i = n-2; i >= 0; i --)
    {
        for (int j = n-1; j > i; j --)
            if (a[i][j] != 0)
            {
                a[i][n] -= a[i][j] * a[j][n];
                a[i][j] = 0;
            }
    }
}    
int main()
{
    int w , h , d;
    int first = 1;
    while (scanf("%d %d %d" , &w , &h , &d) == 3)
    {
        if (w == 0) break;
        if (first == 0) printf("\n");
        first = 0;
        double b[11][11];
        for (int i = 0; i < h; i ++) for (int j = 0; j < w; j ++) scanf("%lf" , &b[i][j]);
        n = 0;
        memset(a , 0 , sizeof(a));
        for (int i = 0; i < h; i ++)
            for (int j = 0; j < w; j ++)
            {
                int num = 0;
                for (int x = -d; x <= d; x ++)
                    for (int y = abs(x)-d; y <= d-abs(x); y ++)
                    {
                        int s = i + x;
                        int t = j + y;
                        if (s >= 0 && s < h && t >= 0 && t < w)
                        {
                            a[n][s * w + t] = 1;
                            num ++;
                        }
                    }
                a[n][w*h] = num * b[i][j];
                n ++;
            }
        gauss();
        for (int i = 0; i < h; i ++)
        {
            for (int j = 0; j < w; j ++)
                printf("%8.2lf" , a[i*w+j][n]);
            printf("\n");
        }
    }
    return 0;
}