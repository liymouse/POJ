#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

double hypot(int x, int y)
{
    return sqrt((double)x * x + y * y);
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        int x[1001], y[1001];
        int used[1001] = { 0 };
        vector<int> p;
        int sx, sy, k = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            if (i == 0) { sx = x[i]; sy = y[i]; k = 0; }
            else if (x[i] < sx || (x[i] == sx && y[i] < sy))
            {
                sx = x[i]; sy = y[i]; k = i;
            }
        }
        p.push_back(k);
        int px = x[k] - 1;
        int py = y[k];
        for (int c = 1; c < n; c++)
        {
            int x1 = x[k] - px;
            int y1 = y[k] - py;
            double L1 = hypot(x1, y1);
            double maxv = -1.0;
            double Len = 1e50;
            int t = -1;
            for (int i = 0; i < n; i ++)
                if (!used[i] && i != k)
                {
                    int x2 = x[i] - x[k];
                    int y2 = y[i] - y[k];
                    double L2 = hypot(x2, y2);
                    double si = (double)(x1 * y2 - x2 * y1) / L1 / L2;
                    if (si >= 0)
                    {
                        double co = (double)(x1 * x2 + y1 * y2) / L1 / L2;
                        if (co > maxv || (co == maxv && L2 < Len))
                        {
                            t = i;
                            maxv = co;
                            Len = L2;
                        }
                    }
                }
            if (t == -1 || t == p[0]) break;
            px = x[k];
            py = y[k];
            p.push_back(t);
            used[t] = 1;
            k = t;
        }
        if (p.size() < 6) { printf("NO\n"); continue; }
        p.push_back(p[0]);
        p.push_back(p[1]);
        int num = 0;
        for (int i = 1; i < p.size() - 1; i++)
        {
            int x1 = x[p[i]] - x[p[i - 1]];
            int y1 = y[p[i]] - y[p[i - 1]];
            int x2 = x[p[i + 1]] - x[p[i]];
            int y2 = y[p[i + 1]] - y[p[i]];
            int si = x1 * y2 - y1 * x2;
            int co = x1 * x2 + y1 * y2;
            if (si < 0 || (si == 0 && co < 0)) { num = 3; break; }
            if (si == 0) num = 0;
            else
            {
                num++;
                if (num >= 2) break;
            }
        }
        if (num >= 2) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}