#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAXN 100
#define EPS 1e-5
typedef struct _Point {
    double x, y;
    _Point() { x = y = 0; }
    _Point(double a, double b) { x = a; y = b; }
}Point, Vec;
typedef struct _Line {
    Point s, e;
    _Line() {}
    _Line(Point a, Point b) { s = a; e = b; }
}Line;
int n;
Point p[MAXN];
Line L[MAXN], que[MAXN];
double cha(Point &a, Point &b) { return a.x * b.y - a.y * b.x; }
double getAngle(Line &a) { return atan2(a.e.y - a.s.y, a.e.x - a.s.x); }

//按跟x轴夹角排序，如果角度相同，最左边的排在最前，可以去重复
int cmp(Line &a, Line &b)
{
    double angA = getAngle(a);
    double angB = getAngle(b);
    if (fabs(angA - angB) < EPS)
    {
        Vec v0 = Vec(a.e.x - a.s.x, a.e.y - a.s.y);
        Vec v1 = Vec(b.e.x - a.s.x, b.e.y - a.s.y);
        return cha(v0, v1) < 0;
    }
    return angA < angB;
}
Point getCross(Line &a, Line &b)
{
    double a1 = a.s.y - a.e.y, b1 = a.e.x - a.s.x, c1 = a.s.x * a.e.y - a.e.x * a.s.y;
    double a2 = b.s.y - b.e.y, b2 = b.e.x - b.s.x, c2 = b.s.x * b.e.y - b.e.x * b.s.y;
    return Point((c1*b2 - c2 * b1) / (a2*b1 - a1 * b2), (a2*c1 - a1 * c2) / (a1*b2 - a2 * b1));
}
//判断b，c交点是否在a的右边
bool isRightSide(Line &a, Line &b, Line &c)
{
    Point o = getCross(b, c);
    Vec x = Vec(a.e.x - a.s.x, a.e.y - a.s.y);
    Vec y = Vec(o.x - a.s.x, o.y - a.s.y);
    if (cha(x, y) < 0) return true;
    return false;
}
//是否存在半平面交
bool HalfPlaneIntersection()
{
    sort(L, L + n, cmp);
    int head = 0, tail = 0, cnt = 0;
    for (int i = 1; i < n; i++)
        if (fabs(getAngle(L[i]) - getAngle(L[cnt])) >= EPS)
        {
            L[++cnt] = L[i];
        }
    n = cnt + 1;

    for (int i = 0; i < n; i++)
    {
        //新加入一条直线
        while (tail - head > 1 && isRightSide(L[i], que[tail - 1], que[tail - 2])) tail--;
        while (tail - head > 1 && isRightSide(L[i], que[head], que[head + 1])) head++;
        que[tail++] = L[i];
    }
    //判断第一条直线跟最后一条直线的影响
    while (tail - head > 1 && isRightSide(que[head], que[tail - 1], que[tail - 2])) tail--;
    while (tail - head > 1 && isRightSide(que[tail - 1], que[head], que[head + 1])) head++;
    return tail - head >= 3;
}

//判断输入点的顺序，面积<0 = 顺时针， 否则为逆时针
bool isClockwise() {
    double res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        Vec a = Vec(p[i].x - p[0].x, p[i].y - p[0].y);
        Vec b = Vec(p[i + 1].x - p[0].x, p[i + 1].y - p[0].y);
        res += cha(a, b);
    }
    return res < 0;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca --)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }
        //按逆时针建边
        if (isClockwise())
        {
            for (int i = 0; i < n; i++)
                L[i] = Line(p[(i + 1) % n], p[i]);
        }
        else
        {
            for (int i = 0; i < n; i++)
                L[i] = Line(p[i], p[(i + 1) % n]);
        }
        if (HalfPlaneIntersection()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
