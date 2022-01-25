#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[150][101];
int f[150];
string s[150];

string convert(vector<int> a[], int x)
{
    if (a[x].size() == 0) return "01";
    vector<string> child;
    for (int i = 0; i < a[x].size(); i++)
        child.push_back(convert(a, a[x][i]));
    sort(child.begin(), child.end());
    string res = "0";
    for (int i = 0; i < child.size(); i++) res += child[i];
    return res + "1";
}
int getF(int x)
{
    if (f[x] == x) return x;
    f[x] = getF(f[x]);
    return f[x];
}
int main()
{
    int k, n, x, y;
    scanf("%d %d", &k, &n);
    memset(tree, 0, sizeof(tree));
    for (int i = 0; i < k; i++)
    {
        int du[101] = { 0 };
        for (int j = 0; j < n - 1; j++)
        {
            scanf("%d %d", &x, &y);
            tree[i][x].push_back(y);
            du[y] ++;
        }
        int root = 0;
        for (int j = 1; j <= n; j++) if (du[j] == 0) { root = j; break; }
        s[i] = convert(tree[i], root);
        f[i] = i;
    }
    for (int i = 0; i < k; i++)
        if (getF(i) == i)
        {
        
            for (int j = i + 1; j < k; j++)
                if (getF(j) == j)
                {
                    if (s[i] == s[j]) f[j] = i;
                }
        }
    int check[151] = { 0 };
    for (int i = 0; i < k; i ++)
        if (check[i] == 0)
        {
            int type = getF(i);
            check[i] = 1;
            printf("%d", i + 1);
            for (int j = i+1; j < k; j ++)
                if (check[j] == 0 && getF(j) == type)
                { 
                    printf(" = %d", j + 1);
                    check[j] = 1;
                }
            printf(" ;\n");
        }
    return 0;
}