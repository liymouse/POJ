#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 2010
int a[N][N];
int low[N] , visited[N] , instack[N] , dfn[N];
int stack[N] , top , check[N];
int index;
int ok;
int n;

void tarjan(int x)
{
    if (!ok) return;
    low[x] = dfn[x] = index ++;
    visited[x] = 1;
    stack[++top] = x;
    instack[x] = 1;
    for (int i = 0; i < n; i ++)
        if (a[x][i])
        {
            if (visited[i] == 0)
            {
                tarjan(i);
                low[x] = min(low[x] , low[i]);
            }
            else if (instack[i])
            {
                low[x] = min(low[x] , dfn[i]);
            }
        }
    if (low[x] == dfn[x])
    {
        int k;
        memset(check , 0 , sizeof(check));
        do
        {
            k = stack[top--];
            instack[k] = 0;
            check[k] = 1;
            //printf("%d " , k-n/2);
            if (check[k] && check[n-k-1])
            {
                ok = 0; break;
            }
        }while (top > -1 && k != x);
        //printf("\n");
    }
}

int main()
{
    int m;
    while (scanf("%d %d" , &n , &m) == 2)
    {
        memset(a , 0 , sizeof(a));
        for (int i = 0; i < m; i ++)
        {
            int x , y;
            scanf("%d %d" , &x , &y);
            a[-x + n][y + n] = 1;
            a[-y + n][x + n] = 1;
        }
        n = 2 * n + 1;
        memset(low , 0 , sizeof(low));
        memset(dfn , 0 , sizeof(dfn));
        memset(visited , 0 , sizeof(visited));
        memset(instack , 0 , sizeof(instack));
        top = -1;
        index = 1;
        ok = 1;
        for (int i = 0; i < n; i ++)
        {
            if (i != n/2 && visited[i] == 0) tarjan(i);
            if (ok == 0) break;
        }
        printf("%d\n" , ok);
    }
    return 0;
}
