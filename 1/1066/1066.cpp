#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

typedef struct
{
    double x[33], y[33];
    int num;
}Poly;
vector<Poly> p;

int linecross(double x1, double y1, double x2, double y2,
    double x3, double y3, double x4, double y4)
{
    if (((x3 - x2) * (y1 - y2) - (y3 - y2) * (x1 - x2)) * ((x4 - x2)*(y1 - y2) - (y4 - y2)*(x1 - x2)) <= 0 &&
        ((x1 - x3) * (y4 - y3) - (y1 - y3) * (x4 - x3)) * ((x2 - x3)*(y4 - y3) - (y2 - y3)*(x4 - x3)) <= 0)
        return 1;
    return 0;
}
void cross(Poly &a, int x1, int y1, int x2, int y2)
{
    double px[80] = { 0 }, py[80] = { 0 };
    int type[80] = { 0 };
    int n = 0;
    int has = 0;
    for (int i = 0; i < a.num; i++)
    {
        px[i * 2] = a.x[i];
        py[i * 2] = a.y[i];
        type[i * 2] = 1;
        if (linecross(a.x[i], a.y[i], a.x[(i + 1) % a.num], a.y[(i + 1) % a.num], x1, y1, x2, y2))
        {
            has ++;
            double a0 = a.y[i] - a.y[(i + 1) % a.num];
            double b0 = a.x[(i + 1) % a.num] - a.x[i];
            double c0 = a.x[i] * a.y[(i + 1) % a.num] - a.y[i] * a.x[(i + 1) % a.num];
            double a1 = y1 - y2;
            double b1 = x2 - x1;
            double c1 = x1 * y2 - x2 * y1;
            double D = a0 * b1 - a1 * b0;
            if (D != 0)
            {
                double xx = (b0*c1 - b1 * c0) / D;
                double yy = (a1*c0 - a0 * c1) / D;
                if (xx == a.x[i] && yy == a.y[i]) type[i * 2] = 2;
                else if (xx == a.x[(i + 1) % a.num] && yy == a.y[(i + 1) % a.num])
                {
                    px[(i + 1) * 2] = xx;
                    py[(i + 1) * 2] = yy;
                    type[(i + 1) * 2] = 2;
                    i++;
                }
                else
                {
                    px[i * 2 + 1] = xx;
                    py[i * 2 + 1] = yy;
                    type[i * 2 + 1] = 2;
                }
            }
        }
    }
    if (has > 1)
    {
        int num = a.num * 2;
        int k = 0;
        a.num = 0;
        //1st poly 1-..-1-2-2-1..1
        //2nd poly 2-1-...-1-2
        while (k < num)
        {
            if (type[k])
            {
                a.x[a.num] = px[k]; a.y[a.num] = py[k]; a.num++; 
                if (type[k] == 2) break;
            }
            k++;
        }
        Poly b;
        b.num = 1;
        b.x[0] = px[k]; b.y[0] = py[k];
        k++;
        while (k < num)
        {
            if (type[k])
            {
                b.x[b.num] = px[k]; b.y[b.num] = py[k]; b.num++;
                if (type[k] == 2) break;
            }
            k++;
        }
        while (k < num)
        {
            if (type[k])
            {
                a.x[a.num] = px[k]; a.y[a.num] = py[k]; a.num++;
            }
            k++;
        }
        p.push_back(b);
    }
}
int nn(Poly &a, Poly &b)
{
    int num = 0;
    for (int i = 0; i < a.num; i++)
    {
        for (int j = 0; j < b.num; j++)
            if (a.x[i] == b.x[j] && a.y[i] == b.y[j])
            {
                num++;
                break;
            }
    }
    if (num == 2) return 1;
    return 0;
}
int in(Poly &a, double x, double y)
{
    double px = a.x[a.num - 1] - x;
    double py = a.y[a.num - 1] - y;
    for (int i = 0; i < a.num; i++)
    {
        double cx = a.x[i] - x;
        double cy = a.y[i] - y;
        if (px * cy - py * cx <= 0) return 0;
        px = cx;
        py = cy;
    }
    return 1;
}
int main()
{
    int n;
    Poly x;
    x.num = 4;
    x.x[0] = 0; x.y[0] = 0;
    x.x[1] = 100; x.y[1] = 0;
    x.x[2] = 100; x.y[2] = 100;
    x.x[3] = 0; x.y[3] = 100;
    p.push_back(x);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int size = p.size();
        for (int k = 0; k < size; k++)
            cross(p[k], x1, y1, x2, y2);
    }
    int m = p.size();
    int a[500][500] = { 0 };
    for (int i = 0; i < m; i++)
    {
        int count[4] = { 0 };
        for (int j = 0; j < p[i].num; j++)
        {
            if (p[i].x[j] == 0) count[0] ++;
            if (p[i].x[j] == 100) count[1] ++;
            if (p[i].y[j] == 0) count[2] ++;
            if (p[i].y[j] == 100) count[3] ++;
        }
        if (count[0] == 2 || count[1] == 2 || count[2] == 2 || count[3] == 2)
        {
            a[i][m] = a[m][i] = 1;
        }
        for (int j = i + 1; j < m; j++)
            if (nn(p[i], p[j]))
            {
                a[i][j] = a[j][i] = 1;
            }
    }
    double px, py;
    scanf("%lf %lf", &px, &py);
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        if (in(p[i], px, py)) { s = i; break; }
    }
    //0~m-1=poly, m = outsize
    //dijkstra find mindist s to m
    int dist[500] = { 0 };
    int mark[500] = { 0 };
    for (int i = 0; i <= m; i++)
        if (a[s][i]) dist[i] = a[s][i];
        else dist[i] = 1 << 30;
    mark[s] = 1;
    for (int i = 0; i <= m; i++)
    {
        int k = -1;
        int minv = 1 << 30;
        for (int j = 0; j <= m; j ++)
            if (mark[j] == 0 && dist[j] < minv) { minv = dist[j]; k = j; }
        if (k == -1) break;
        mark[k] = 1;
        for (int j = 0; j <= m; j ++)
            if (mark[j] == 0 && a[k][j] && dist[k] + a[k][j] < dist[j])
            {
                dist[j] = dist[k] + a[k][j];
            }
    }
    printf("Number of doors = %d\n", dist[m]);
    return 0;
}