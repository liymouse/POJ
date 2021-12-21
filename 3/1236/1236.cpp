#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))

int a[101][101] = { 0 };
int mark[101] = { 0 };
int n;
int merge;
int st[101] = { 0 };
int st_top = -1;


void dfs(int x)
{
    if (st_top > 0 && st[0] == x) // found
    {
        merge = 1;
        mark[x] = 0;
        for (int i = 1; i < st_top; i++)
        {
            for (int j = 0; j < n; j ++)
                if (j != x && mark[j] == 0 && a[st[i]][j])
                {
                    a[x][j] = 1;
                }
            a[x][st[i]] = 0;
        }
        for (int i = 0; i < n; i ++)
            if (i != x && mark[i] == 0)
            {
                for (int j = 1; j < st_top; j ++)
                    if (a[i][st[j]])
                    {
                        a[i][x] = 1;
                        a[i][st[j]] = 0;
                    }
            }
        return;
    }
    for (int i = 0; i < n; i ++)
        if (i != x && mark[i] == 0 && a[x][i])
        {
            mark[i] = 1;
            st_top++;
            st[st_top] = i;
            dfs(i);
            if (merge) return;
            st_top--;
            mark[i] = 0;
        }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        while (scanf("%d", &x) == 1)
        {
            if (x == 0) break;
            a[i][x - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        if (mark[i] == 0)
        {
            do
            {
                merge = 0;
                st_top = 0;
                st[0] = i;
                dfs(i);
            } while (merge);
        }
    int num = 0;
    int in0 = 0, out0 = 0;
    for (int i = 0; i < n; i ++)
        if (mark[i] == 0)
        {
            num++;
            int in = 0;
            int out = 0;
            for (int j = 0; j < n; j ++)
                if (i != j && mark[j] == 0)
                {
                    in += a[j][i];
                    out += a[i][j];
                }
            if (in == 0) in0++;
            if (out == 0) out0++;
        }
    int ans1 = in0;
    int ans2 = max(in0, out0);
    if (num == 1) ans2 = 0;
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}
