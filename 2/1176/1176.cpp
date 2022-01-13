#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, c, k;
    int on[3], off[3];
    int on_num = 0, off_num = 0;
    vector<string> res;
    scanf("%d %d", &n, &c);
    while (scanf("%d", &k) == 1)
    {
        if (k == -1) break;
        on[on_num++] = k;
    }
    while (scanf("%d", &k) == 1)
    {
        if (k == -1) break;
        off[off_num++] = k;
    }
    for (int i = 0; i < (1 << 4); i++)
    {
        int a[101];
        for (int j = 1; j <= n; j++) a[j] = 1;
        int num = 0, t = i;
        while (t) { num++; t &= t - 1; }
        if (num > c || (c - num) % 2 == 1) continue;
        if (i & (1 << 0))
        {
            for (int j = 1; j <= n; j++) a[j] = 1 - a[j];
        }
        if (i & (1 << 1))
        {
            for (int j = 1; j <= n; j += 2) a[j] = 1 - a[j];
        }
        if (i & (1 << 2))
        {
            for (int j = 2; j <= n; j += 2) a[j] = 1 - a[j];
        }
        if (i & (1 << 3))
        {
            for (int j = 1; j <= n; j += 3) a[j] = 1 - a[j];
        }
        int ok = 1;
        for (int j = 0; j < on_num; j++) if (a[on[j]] == 0) { ok = 0; break; }
        for (int j = 0; j < off_num; j++) if (a[off[j]] == 1) { ok = 0; break; }
        if (ok)
        {
            string s = "";
            for (int j = 1; j <= n; j++) s += a[j] + '0';
            res.push_back(s);
        }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        printf("%s\n", res[i].c_str());
    return 0;
}