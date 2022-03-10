#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

char a[55][55];
int w, h, num;
int p[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0,1} };

void dfs(int i, int j, int type)
{
    if (type) a[i][j] = '*';
    else a[i][j] = '.';
    for (int k = 0; k < 4; k++)
    {
        int ii = i + p[k][0];
        int jj = j + p[k][1];
        if (0 <= ii && ii < h && 0 <= jj && jj < w)
        {
            if (type == 1 && a[ii][jj] == 'X') dfs(ii, jj, 1);
            else if (type == 0)
            {
                if (a[ii][jj] == 'X')
                { 
                    num++; dfs(ii, jj, 1);
                    dfs(ii, jj, 0);
                }
                else if (a[ii][jj] == '*') dfs(ii, jj, 0);
            }
        }
    }
}
int main()
{
    int ca = 1;
    while (scanf("%d %d", &w, &h) == 2)
    {
        if (w == 0 && h == 0) break;
        vector<int> res;
        for (int i = 0; i < h; i++) scanf("%s", a[i]);
        for (int i = 0; i < h; i ++)
            for (int j = 0; j < w; j ++)
                if (a[i][j] == '*')
                {
                    num = 0;
                    dfs(i, j, 0);
                    res.push_back(num);
                }
        printf("Throw %d\n", ca++);
        sort(res.begin(), res.end());
        if (res.size() > 0)
        {
            printf("%d", res[0]);
            for (int i = 1; i < res.size(); i++) printf(" %d", res[i]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
