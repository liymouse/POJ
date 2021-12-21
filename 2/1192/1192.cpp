#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;
typedef struct {
    int v, num;
}Node;

int a[1001][1001] = { 0 };
int c[1001];
int x[1001];
int y[1001];
Node f[1001][1001];
int res;
int n;

Node find(int p)
{
    Node s;
    s.v = c[p];
    s.num = 1;
    x[p] = 1;
    for (int i = 0; i < n; i ++)
        if (a[p][i] && x[i] == 0)
        {
            if (f[p][i].num == -1)
            {
                f[p][i] = find(i);
            }
            if (f[p][i].v >= 0) { s.v += f[p][i].v; s.num += f[p][i].num; }
        }
    x[p] = 0;
    return s;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &x[i], &y[i], &c[i]);
        for (int j = 0; j < i; j++)
        {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) == 1)
            {
                a[i][j] = a[j][i] = 1;
                f[i][j].num = f[j][i].num = -1;
                break;
            }
        }
    }
    memset(x, 0, sizeof(x));
    res = -(1 << 30);
    for (int i = 0; i < n; i++)
    {
        Node k = find(i);
        
        if (k.num >= 2 && k.v > res) { res = k.v; }
    }
    if (res == -(1 << 30))
    {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i][j] && c[i] + c[j] > res) res = c[i] + c[j];
    }
    printf("%d\n", res);
    return 0;
}