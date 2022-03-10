#include <stdio.h>

int main()
{
    int a[301][301];
    int m, n;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = (i == j) ? 0 : (1 << 30);
    for (int i = 0; i < m; i++)
    {
        int mi;
        int b[301];
        scanf("%d", &mi);
        for (int j = 0; j < mi; j++) scanf("%d", &b[j]);
        for (int x = 0; x < mi; x++)
            for (int y = 0; y < mi; y++)
                if (x != y) a[b[x] - 1][b[y] - 1] = 1;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            if (i != k)
                for (int j = 0; j < n; j++)
                    if (j != k && j != i && a[i][k] < (1 << 30) && a[k][j] < (1 << 30) &&
                        a[i][j] > a[i][k] + a[k][j])
                        a[i][j] = a[i][k] + a[k][j];
    int minv = 1 << 30;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            if (i != j) sum += a[i][j];
        if (sum < minv) minv = sum;
    }
    printf("%d\n", minv * 100 / (n - 1));
    return 0;
}