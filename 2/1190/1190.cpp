#include <stdio.h>

int r[21] = { 0 };
int h[21] = { 0 };
int res;
int n, m;

void find(int i, int v, int s)
{
    if (i == m+1)
    {
        if (v == 0)
        {
            s += r[m] * r[m];
            if (res == 0 || s < res) res = s;
        }
        return;
    }
    int high = v / (m + 1 - i);
    if (res > 0)
    {
        //if (2 * v / (r[i - 1]+1) + s > res) return;
        int tmp_s = s;
        for (int j = i; j <= m; j++) tmp_s += 2 * (h[i - 1] + (j - i + 1)) * (r[i - 1] + (j - i + 1));
        tmp_s += (r[i - 1] + (m - i + 1)) * (r[i - 1] + (m - i + 1));
        if (tmp_s >= res) return;
    }
    for (int H = h[i - 1] + 1; H*(r[i-1]+1)*(r[i-1]+1) <= high; H++)
    {
        for (int R = r[i - 1] + 1; R*R*H<=high; R++)
        {
            r[i] = R; h[i] = H;
            find(i + 1, v - R*R*H, s + 2 * R*H);
            r[i] = 0; h[i] = 0;
        }
    }
}
int main()
{
    res = 0;
    scanf("%d %d", &n, &m);
    find(1, n, 0);
    printf("%d\n", res);
    return 0;
}