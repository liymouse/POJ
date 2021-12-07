#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int a[30][30][30];
int gone[30][30][30];
int d[6][3] = { {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0,0,1}, {0,0,-1} };
int n, m, k;
int num;

void dfs(int x, int y, int z)
{
    num++;
    a[x][y][z] = 1;
    for (int i = 0; i < 6; i++)
    {
        int xx = x + d[i][0];
        int yy = y + d[i][1];
        int zz = z + d[i][2];
        if (0 <= xx && xx < k && 0 <= yy && yy < m && 0 <= zz && zz < n &&
            gone[xx][yy][zz] == 0 && !a[xx][yy][zz])
        {
            dfs(xx, yy, zz);
        }
    }
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int L;
        scanf("%d %d %d %d", &n, &m, &k, &L);
        int res = 0;
        memset(gone, 0, sizeof(gone));
        int last_num = n * m * k;
        for (int i = 0; i < L; i++)
        {
            int p, b;
            scanf("%d", &p);
            last_num -= p;
            for (int j = 0; j < p; j++) {
                scanf("%d", &b);
                int x = b / (m * n);
                int y = b % (m * n) / n;
                int z = b % n;
                gone[x][y][z] = 1;
            }
            memset(a, 0, sizeof(a));
            num = 0;
            for (int x = 0; x < k; x++)
                for (int y = 0; y < m; y++)
                    for (int z = 0; z < n; z++)
                        if (gone[x][y][z] == 0) {
                            dfs(x, y, z); goto L_out;
                        }
L_out:
            if (num < last_num) res++;
        }
        printf("%d\n", res);
    }
    return 0;
}