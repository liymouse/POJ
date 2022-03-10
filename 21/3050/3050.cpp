#include <stdio.h>

char hash[1000000] = { 0 };
int a[5][5] = { 0 };
int num = 0, L = 0;
int f[4][2] = { { -1, 0 },{ 0, -1 },{ 1, 0 },{ 0, 1 } };
void dfs(int x, int y)
{
    if (L == 6)
    {
        hash[num] = 1;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int xx = x + f[i][0];
        int yy = y + f[i][1];
        if (0 <= xx && xx < 5 && 0 <= yy && yy < 5)
        {
            num = num * 10 + a[xx][yy];
            L++;
            dfs(xx, yy);
            L--;
            num /= 10;
        }
    }
}
int main()
{
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) scanf("%d", &a[i][j]);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            num = a[i][j]; L = 1;
            dfs(i, j);
        }
    }
    int res = 0;
    for (int i = 0; i < 1000000; i++) if (hash[i]) res++;
    printf("%d\n", res);
    return 0;
}