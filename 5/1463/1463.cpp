#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))

vector<int> son[10001];
int father[10001];
int dp[10001][2]; //0 = not set person, 1 = set person

void dfs(int x)
{
    dp[x][0] = 0; dp[x][1] = 1; //init point x non-choose & choose
    for (int i = 0; i < son[x].size(); i++)
    {
        dfs(son[x][i]);
        dp[x][0] += dp[son[x][i]][1]; //if x not choose, must all son choose
        dp[x][1] += min(dp[son[x][i]][0], dp[son[x][i]][1]); //if x chose, whatever son choose or not
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++) son[i].clear();
        memset(father, 0, sizeof(father));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            int x, m;
            scanf("%d:(%d)", &x, &m);
            for (int j = 0; j < m; j++)
            {
                int y;
                scanf("%d", &y);
                son[x].push_back(y);
                father[y] = 1; //y has father
            }
        }
        int k = 0;
        //find a non-father point as root
        for (int i = 0; i < n; i++) if (!father[i]) { k = i; break; }
        dfs(k);
        printf("%d\n", min(dp[k][0], dp[k][1]));
    }
    return 0;
}
