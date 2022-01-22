#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int a[21][21];
int du[21];
int v[21];
int n, t1, t2;
char s1[25], s2[25], s3[25];
char attributes[21][100][25];
int att_num;

void dfs(int x)
{
    v[x] = 1;
    if (du[x] < t1) strcpy(attributes[x][att_num], s1);
    else if (du[x] < t2) strcpy(attributes[x][att_num], s2);
    else strcpy(attributes[x][att_num], s3);
    for (int i = 1; i <= n; i++)
        if (a[x][i] && v[i] == 0) dfs(i);
}
int main()
{
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        memset(a, 0, sizeof(a));
        memset(du, 0, sizeof(du));
        memset(attributes, 0, sizeof(attributes));
        att_num = 0;
        for (int i = 1; i <= n; i++)
        {
            int j;
            du[i] = 0;
            while (scanf("%d", &j) == 1)
            {
                if (j == 0) break;
                a[i][j] = 1;
                du[i] ++;
            }
        }
        int x;
        while (scanf("%d", &x) == 1)
        {
            if (x == 0) break;
            memset(v, 0, sizeof(v));
            scanf("%d %d %s %s %s", &t1, &t2, s1, s2, s3);
            dfs(x);
            for (int i = 1; i <= n; i ++)
                if (v[i] == 0) strcpy(attributes[i][att_num], s1);
            att_num++;
        }
        for (int i = 1; i <= n; i++)
        {
            char name[23];
            scanf("%s", name);
            printf("%s:", name);
            for (int j = 0; j < att_num; j++)
                printf(" %s", attributes[i][j]);
            printf("\n");
        }
    }
    return 0;
}