#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int x, y;
}Point;
typedef struct
{
    Point p[100];
    int num;
    int dest;
}Kindom;
Point base;
int cha(Point &p1, Point &p2, Point &p0)
{
    int x1 = p1.x - p0.x;
    int y1 = p1.y - p0.y;
    int x2 = p2.x - p0.x;
    int y2 = p2.y - p0.y;
    return x1 * y2 - x2 * y1;
}
int cmp(Point &x, Point &y)
{
    int ax = x.x - base.x;
    int ay = x.y - base.y;
    int bx = y.x - base.x;
    int by = y.y - base.y;
    int cross = cha(x, y, base);
    if (cross == 0)
    {
        int La = ax * ax + ay * ay;
        int Lb = bx * bx + by * by;
        return La < Lb;
    }
    return cross > 0;
}


void getKindom(Kindom &a, Point p[], int n)
{
    int k = 0;
    for (int i = 1; i < n; i++)
        if (p[i].y < p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x)) k = i;
    Point tmp = p[0]; p[0] = p[k]; p[k] = tmp;
    base = p[0];
    sort(p + 1, p + n, cmp);
    a.num = 2;
    a.p[0] = p[0];
    a.p[1] = p[1];
    a.p[2] = p[2];
    for (int i = 3; i < n; i++)
    {
        while (cha(p[i], a.p[a.num], a.p[a.num - 1]) >= 0) a.num--;
        a.num++;
        a.p[a.num] = p[i];
    }
    a.num++;
    a.p[a.num] = p[0];
    a.num++;
    a.dest = 0;
}
void check(Kindom &a, Point &p)
{
    int zheng = 0, fu = 0;
    for (int i = 1; i < a.num; i++)
    {
        int k = cha(a.p[i - 1], a.p[i], p);
        if (k < 0) fu++;
        else if (k > 0) zheng++;
        if (zheng > 0 && fu > 0) return;
    }
    a.dest = 1;
}
double calArea(Kindom &a)
{
    double area = 0.0;
    for (int i = 2; i < a.num; i++)
        area += cha(a.p[i - 1], a.p[i], a.p[0]);
    return area;
}
int main()
{
    Point p[200];
    int n;
    Kindom a[30] = { 0 };
    int num = 0;
    freopen("1264.in", "r", stdin);
    while (scanf("%d", &n) == 1)
    {
        if (n == -1) break;
        for (int i = 0; i < n; i++) scanf("%d %d", &p[i].x, &p[i].y);
        getKindom(a[num++], p, n);
    }
    Point pao;
    while (scanf("%d %d", &pao.x, &pao.y) == 2)
    {
        for (int i = 0; i < num; i++)
            if (a[i].dest == 0) check(a[i], pao);
    }
    double area = 0.0;
    for (int i = 0; i < num; i++)
        if (a[i].dest) area += calArea(a[i]);
    printf("%.2lf\n", area/2.0);
    return 0;
}