#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
const int maxP = 1011;
int n, p1, p2, totGroup;
int fa[maxP], rival[maxP], tot[maxP], a[maxP], b[maxP], f[maxP][maxP], w[maxP][maxP], aa[maxP], bb[maxP];
bool v[maxP];
int find(int x)
{
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}
int unionT(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y || y == 0) return x;
    if (x == 0) return y;
    fa[x] = y;
    tot[y] += tot[x];
    return y;
}
void getWay(int i, int j)
{
    if (i == 0) return;
    if (w[i][j] == 1)
    {
        getWay(i - 1, j - a[i]);
        v[aa[i]] = true;
    }
    else
    {
        getWay(i - 1, j - b[i]);
        v[bb[i]] = true;
    }
    return;
}
int main()
{
    freopen("g1.txt", "r", stdin);
    freopen("output_test.txt", "w", stdout);
    while (cin >> n >> p1 >> p2)
    {
        if (n + p1 + p2 == 0) break;
        for (int i = 1; i <= p1 + p2; i++)
        {
            fa[i] = i;
            rival[i] = 0;
            tot[i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            string s;
            cin >> x >> y >> s;
            if (s == "yes")
            {
                x = find(x);
                y = find(y);
                int tx = unionT(x, y),
                    ty = unionT(rival[x], rival[y]);
                rival[tx] = ty;
                rival[ty] = tx;
            }
            else
            {
                x = find(x);
                y = find(y);
                rival[x] = find(rival[x]);
                rival[y] = find(rival[y]);
                if (rival[y] == 0) rival[y] = x;
                if (rival[x] == 0) rival[x] = y;
                int tx = unionT(x, rival[y]),
                    ty = unionT(rival[x], y);
                rival[tx] = ty;
                rival[ty] = tx;
            }
        }
        memset(v, false, sizeof(v));
        totGroup = 0;
        for (int i = 1; i <= p1 + p2; i++)
        {
            int x = find(i);
            if (!v[x])
            {
                rival[x] = find(rival[x]);
                totGroup++;
                a[totGroup] = tot[x];
                b[totGroup] = tot[rival[x]];
                aa[totGroup] = x;
                bb[totGroup] = rival[x];
                v[x] = true;
                v[rival[x]] = true;
            }
        }
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= totGroup; i++)
            for (int j = 1; j <= p1; j++)
            {
                if (j - a[i] >= 0 && f[i - 1][j - a[i]] > 0)
                {
                    f[i][j] += f[i - 1][j - a[i]];
                    w[i][j] = 1;
                }
                if (j - b[i] >= 0 && f[i - 1][j - b[i]] > 0)
                {
                    f[i][j] += f[i - 1][j - b[i]];
                    w[i][j] = 2;
                }
                if (f[i][j] >= 2) f[i][j] = 2;
            }

        if (f[totGroup][p1] == 1 || p1 == 0)
        {
            memset(v, false, sizeof(v));
            getWay(totGroup, p1);
            for (int i = 1; i <= p1 + p2; i++)
                if (v[find(i)]) cout << i << endl;
            cout << "end" << endl;
        }
        else cout << "no" << endl;
    }
    return 0;
}