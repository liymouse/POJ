#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int start;
    int sub;
    int num;
}Bus;
vector<Bus> p;

int cmp(Bus &x, Bus &y)
{
    if (x.num == y.num) return x.start < y.start;
    return x.num > y.num;
}

int t[60] = { 0 };
int n, res = 17;

void find(int num, int pi)
{
    if (n == 0) {
        if (num < res) res = num;
        return;
    }
    if (num + 1 >= res) return;
    while (pi < p.size())
    {
        if (p[pi].num <= n && num + 1 + (n-1)/p[pi].num < res && t[p[pi].start])
        {
            int can = 1;
            for (int k = p[pi].start + p[pi].sub; k < 60; k += p[pi].sub)
                if (t[k] == 0) { can = 0; break; }
            if (can)
            {
                for (int k = p[pi].start; k < 60; k += p[pi].sub) { t[k] --; n--; }
                find(num + 1, pi);
                for (int k = p[pi].start; k < 60; k += p[pi].sub) { t[k] ++; n++; }
            }
        }
        pi++;
    }
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        memset(t, 0, sizeof(t));
        p.clear();
        res = 17;
        int x;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x); t[x] ++;
        }
        for (int start = 0; start < 30; start ++)
            for (int sub = start + 1; start + sub < 60; sub++)
            {
                int can = 1, num = 0;
                for (int i = start; i < 60; i += sub)
                {
                    if (t[i] == 0) { can = 0; break; }
                    num++;
                }
                if (can)
                {
                    Bus x;
                    x.start = start;
                    x.sub = sub;
                    x.num = num;
                    p.push_back(x);
                }
            }
        sort(p.begin(), p.end(), cmp);
        find(0, 0);
        printf("%d\n", res);
    }
    return 0;
}