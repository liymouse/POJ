#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    double a, b;
}Elm;

int cmp(Elm &x, Elm &y)
{
    if (x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        int x1, y1, x2, y2, r;
        vector<Elm> p;
        scanf("%d %d", &x1, &y1);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &x2, &y2, &r);
            double A = ((double)x1 * y2 - (double)y1*x2) / r;
            double B = (double)(y1 - y2) / r;
            double a = B * B - 1;
            double b = 2 * A *B + 2 * x1;
            double c = A * A - x1 * x1 - y1 * y1;
            Elm x;
            double delta = sqrt(b*b - 4 * a*c);
            x.a = (-b - delta) / (2 * a);
            x.b = (-b + delta) / (2 * a);
            p.push_back(x);
        }
        sort(p.begin(), p.end(), cmp);
        vector<Elm> res;
        res.push_back(p[0]);
        int k = 0;
        for (int i = 1; i < p.size(); i++)
        {
            if (p[i].a <= res[k].b)
            {
                if (p[i].b > res[k].b) res[k].b = p[i].b;
            }
            else
            {
                res.push_back(p[i]);
                k++;
            }
        }
        for (int i = 0; i < res.size(); i++)
            printf("%.2lf %.2lf\n", res[i].a, res[i].b);
        printf("\n");
    }
}