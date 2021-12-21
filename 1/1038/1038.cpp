#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, num;
int p3[11];
int f[2][59050];
int id;
int pre[10]; //i-2 & i-1
int cur[10]; //i-1 & i
int a[151][11];

inline int getState(int t[])
{
    int st = 0;
    for (int i = 0; i < m; i++)
        st = st * 3 + t[i];
    return st;
}

inline void getArray(int t[], int s)
{
    for (int i = m - 1; i >= 0; i--)
    {
        t[i] = s % 3;
        s /= 3;
    }
}

void dfs(int x, int cnt, int state)
{
    f[1 - id][state] = max(f[1 - id][state], cnt);
    if (x >= m) return;
    //3x2
    if (x < m-1 && pre[x] == 0 && pre[x+1] == 0 && cur[x] == 0 && cur[x+1] == 0)
    {
        cur[x] = cur[x+1] = 2;
        dfs(x + 2, cnt + 1, getState(cur));
        cur[x] = cur[x + 1] = 0;
    }
    //2x3
    if (x < m - 2 && cur[x] == 0 && cur[x + 1] == 0 && cur[x + 2] == 0)
    {
        cur[x] = cur[x + 1] = cur[x + 2] = 2;
        dfs(x + 3, cnt + 1, getState(cur));
        cur[x] = cur[x + 1] = cur[x + 2] = 0;
    }
    //skip
    dfs(x + 1, cnt, state);
}

int main()
{
    int ca;
    //freopen("output.txt", "w", stdout);
    scanf("%d", &ca);
    p3[0] = 1;
    for (int i = 1; i <= 10; i++) p3[i] = p3[i - 1] * 3;
    while (ca --)
    {
        scanf("%d %d %d", &n, &m, &num);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < num; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            a[x-1][y-1] = 1;
        }
        id = 0;
        for (int i = 0; i < m; i++)
            pre[i] = a[0][i] ? 2 : 1;
        memset(f[id], 0xff, sizeof(f[id]));
        f[id][getState(pre)] = 0;
        for (int i = 1; i < n; i++)
        {
            memset(f[1 - id], 0xff, sizeof(f[1 - id]));
            for (int s = 0; s < p3[m]; s ++)
                if (f[id][s] != -1)
                {
                    getArray(pre, s);
                    for (int j = 0; j < m; j++)
                        if (pre[j] == 2) cur[j] = a[i][j] ? 2 : 1;
                        else cur[j] = a[i][j] ? 2 : 0;
                    dfs(0, f[id][s], getState(cur));
                }
            id = 1 - id;
        }
        int res = 0;
        for (int i = 0; i < p3[m]; i++) if (f[id][i] > res) res = f[id][i];
        printf("%d\n", res);
    }
    return 0;
}