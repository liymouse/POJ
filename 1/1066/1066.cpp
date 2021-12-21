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
            has = 1;

        }
    }
    if (has)
    {

    }
}
int nn(Poly &a, Poly &b)
{
    int num = 0;
    for (int i = 0; i < a.num; i++)
    {
        for (int j = 0; j < b.num; j++)
            if (a.x[i] == b.x[j] && a.y[i] == b.y[j] &&
                a.x[(i + 1) % a.num] == b.x[(i + 1) % b.num] &&
                a.y[(i + 1) % a.num] == b.y[(i + 1) % b.num])
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
            cross(p[i], x1, y1, x2, y2);
    }
    int m = p.size();
    int a[500][500] = { 0 };
    for (int i = 0; i < n; i ++)
        for (int j = i+1; j < n; j ++)
            if (nn(p[i], p[j]))
            {
                a[i][j] = a[j][i] = 1;
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
        for (int j = 0; j <= m; j ++)
            if (mark[j] == 0 && a[k][j] && dist[k] + a[k][j] < dist[j])
            {
                dist[j] = dist[k] + a[k][j];
            }
    }
    printf("Number of doors = %d\n", a[s][m]);
    return 0;
}