#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

vector<int> tree[3001];
vector<int> cost[3001];
int f[3001][3001];
int num[3001];
#define max(a, b) ((a)>(b)?(a):(b))
void find(int x)
{
    f[x][0] = 0;
    if (tree[x].size() == 0)
    {
        num[x] = 1;
        return;
    }
    for (int i = 0; i < tree[x].size(); i++)
    {
        find(tree[x][i]);
        num[x] += num[tree[x][i]];
        for (int j = num[x]; j >= 1; j--)
        {
            for (int k = 0; k < j; k ++)
                if (j - k <= num[tree[x][i]])
                {
                    f[x][j] = max(f[x][j], f[x][k] + f[tree[x][i]][j - k] - cost[x][i]);
                }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n - m; i++)
    {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            int v, c;
            scanf("%d %d", &v, &c);
            tree[i].push_back(v);
            cost[i].push_back(c);
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 0; j <= n; j++) f[i][j] = -1000000;
    memset(num, 0, sizeof(num));
    for (int i = n - m + 1; i <= n; i++)
        scanf("%d", &f[i][1]);
    find(1);
    for (int i = n; i >= 0; i --)
        if (f[1][i] >= 0)
        {
            printf("%d\n", i);
            break;
        }
    return 0;
}