#include <stdio.h>
#include <string.h>

int n;
int a[100][100];
int black[100];
int res_black[100];
int res, num;

void dfs(int x)
{
    if (x == n)
    {
        if (num > res)
        {
            res = num;
            for (int i = 0; i < num; i++) res_black[i] = black[i];
        }
        return;
    }
    if (num + n - x <= res) return;
    int can_set_black = 1;
    for (int i = 0; i < num; i++)
        if (a[x][black[i]]) { can_set_black = 0; break; }
    if (can_set_black)
    {
        black[num++] = x;
        dfs(x + 1); //set to black & find next
        black[--num] = 0;
    }
    dfs(x + 1); //set to white & find next
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int k;
        scanf("%d %d", &n, &k);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            x--; y--;
            a[x][y] = a[y][x] = 1;
        }
        memset(black, 0, sizeof(black));
        num = 0; res = 0;
        dfs(0);
        printf("%d\n", res);
        if (res > 0)
        {
            for (int i = 0; i < res - 1; i++) printf("%d ", res_black[i]+1);
            printf("%d\n", res_black[res - 1]+1);
        }
    }
    return 0;
}
