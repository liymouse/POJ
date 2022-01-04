#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int a[101][101];
int mark[101];
int visit[101];
int res1, res2, n;
int sc, sm;

void dfs(int x, int label)
{
    mark[x] |= label;
    for (int i = 1; i <= n; i ++)
        if ((a[x][i] & label) && (mark[i] & label) == 0)
        {
            dfs(i, label);
        }
}
void check(int x, int num)
{
    visit[x] = 1;
    for (int i = 1; i <= n; i ++)
        if ((a[x][i] & 2) && mark[i] == 2)
        {
            if (i == sm && num >= 1) { res2 = 1; return; }
            if (visit[i] == 0)
            {
                check(i, num + 1);
                if (res2) return;
            }
        }
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        scanf("%d %d %d", &n, &sc, &sm);
        memset(a, 0, sizeof(a));
        memset(mark, 0, sizeof(mark));
        int x, y;
        while (scanf("%d %d", &x, &y) == 2)
        {
            if (x == -1 && y == -1) break;
            a[x][y] |= 1;
        }
        while (scanf("%d %d", &x, &y) == 2)
        {
            if (x == -1 && y == -1) break;
            a[x][y] |= 2;
        }
        dfs(sc, 1);
        dfs(sm, 2);
        res1 = 0;
        for (int i = 1; i <= n; i++) if (mark[i] == 3) res1 = 1;
        memset(visit, 0, sizeof(visit));
        res2 = 0;
        check(sm, 1);
        printf("%c %c\n", res1 ? 'Y' : 'N', res2 ? 'Y' : 'N');
    }
    return 0;
}