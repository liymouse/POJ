#include <stdio.h>
#include <math.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int r[22] = { 0 };
int h[22] = { 0 };
int res;
int n, m;

void find(int i, int v, int s)
{
    if (i == 0)
    {
        if (res == 0 || s < res)
        {
            res = s;
            //printf("res = %d\n", res);
            //for (int j = 1; j <= m; j++) printf(" %d", r[j]); printf("\n");
            //for (int j = 1; j <= m; j++) printf(" %d", h[j]); printf("\n");
        }
        return;
    }
    if (res > 0)
    {
        if (2 * v / (r[i + 1]-1) + s >= res) return;
    }

    int high = v - (i - 1)*(i - 1)*i*i/4 + 1;
    int low = v / i;
    for (int R = r[i+1]-1; R >= i; R --)
    {
        if (i > 1)
        {
            for (int H = min(h[i + 1]-1, high / (R*R)); H >= max(i, low / (R*R)); H--)
            {
                r[i] = R; h[i] = H;
                if (i == m)
                    find(i - 1, v - R*R*H, s + R*R + 2 * R*H);
                else
                    find(i - 1, v - R*R*H, s + 2 * R*H);
                r[i] = 0; h[i] = 0;
            }
        }
        else
        {
            if (v % (R*R) == 0)
            {
                int H = v / (R*R);
                if (0 < H && H < h[i + 1])
                {
                    r[i] = R; h[i] = H;
                    if (i == m)
                        find(i - 1, 0, s + R*R + 2 * R*H);
                    else
                        find(i - 1, 0, s + 2 * R*H);
                    r[i] = 0; h[i] = 0;
                }
            }
        }
    }
}

int main()
{
    res = 0;
    scanf("%d %d", &n, &m);
    int maxv = n - (m - 1)*(m - 1)*m*m/4;
    r[m + 1] = (int)sqrt((double)maxv / m) + 1;
    h[m + 1] = maxv / (m*m) + 1;
    find(m, n, 0);

    printf("%d\n", res);
    return 0;
}