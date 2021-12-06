#include <stdio.h>
#include <string.h>

int a[300][300];
int id[100];
int visit[300];
int n;
int bimap;

void dfs(int x, int flag)
{
    visit[x] = flag;
    for (int i = 0; i < n; i ++)
        if (visit[id[i]] == 0 && a[x][id[i]])
        {
            dfs(id[i], (flag%2)+1);
        }
        else if (a[x][id[i]] && visit[id[i]] == flag)
        {
            bimap = 0;
        }
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int k;
        int list[100];
        scanf("%d %d", &n, &k);
        memset(a, 0, sizeof(a));
        memset(id, 0, sizeof(id));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &id[i]);
            int m;
            scanf("%d", &m);
            for (int j = 0; j < m; j++)
            {
                int x;
                scanf("%d", &x);
                a[id[i]][x] = 1;
                a[x][id[i]] = 1;
            }
        }
        for (int i = 0; i < k; i++) scanf("%d", &list[i]);
        memset(visit, 0, sizeof(visit));
        bimap = 1;
        dfs(list[0], 1);
        int ok = 1;
        if (bimap == 0) printf("YES\n");
        else
        {
            for (int i = 1; i < k; i++)
                if (visit[list[i]] != 1) { ok = 0; break; }
            if (ok) printf("YES\n"); else printf("NO\n");
        }
    }
    return 0;
}