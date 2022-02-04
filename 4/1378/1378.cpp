#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int n, m, k;
    while (scanf("%d %d %d", &n, &m, &k) == 3)
    {
        vector<int> a[10000];
        int check[55] = { 0 };
        for (int i = 0; i < m; i++)
        {
            int num, x;
            scanf("%d", &num);
            for (int j = 0; j < num; j++)
            {
                scanf("%d", &x);
                a[x].push_back(i);
            }
        }
        for (int i = 0; i < k; i++)
        {
            int x;
            scanf("%d", &x);
            for (int j = 0; j < a[x].size(); j ++)
                check[a[x][j]] = 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int tingdian = 1;
            for (int j = 0; j < a[i].size(); j++)
                tingdian &= check[a[i][j]];
            if (tingdian) res++;
        }
        printf("%d\n", res);
        scanf("%d %d %d", &n, &m, &k);
        if (n == -1 && m == -1 && k == -1) break;
    }
    return 0;
}
