#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef struct {
    double x , y;
}Point;

double cross(Point sp , Point ep , Point op)
{
    return (sp.x - op.x) * (ep.y - op.y) - (sp.y - op.y) * (ep.x - op.x);
}

double dist(Point p1 , Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
bool cmp(const Point p1 , const Point p2)
{
    if (p1.y == p2.y) return p1.x < p2.x;
    return p1.y < p2.y;
}

int graham(Point p[] , Point res[])
{
    sort(p , p + 4 , cmp);
    for (int i = 0; i < 3; i ++) res[i] = p[i];
    int top = 1;
    for (int i = 2; i < 4; i ++)
    {
        while (top && cross(p[i] , res[top] , res[top-1]) > -1e-8) top --;
        res[++top] = p[i];
    }
    int len1 = top;
    res[++top] = p[2];
    for (int i = 1; i >= 0; i --)
    {
        while (top != len1 && cross(p[i] , res[top] , res[top-1]) > -1e-8) top --;
        res[++top] = p[i];
    }
    return top;      
}

Point intersect(Point u1,Point u2,Point v1,Point v2)
{
    Point res = u1;
    double t = ((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
               ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    res.x += (u2.x - u1.x) * t;
    res.y += (u2.y - u1.y) * t;
    return res;
}

int main()
{
    Point p[4];
    while (scanf("%lf %lf" , &p[0].x , &p[0].y) == 2)
    {
        for (int i = 1; i < 4; i ++) scanf("%lf %lf" , &p[i].x , &p[i].y);
        if (p[0].x < 0) break;
        Point pt[4];
        int sum = graham(p , pt);
        double res = 0;
        if (sum == 4)
        {
            Point c = intersect(pt[0] , pt[2] , pt[1] , pt[3]);
            for (int i = 0; i < 4; i ++) res += dist(p[i] , c);
        }
        else
        {
            res = 1e10;
            for (int i = 0; i < 4; i ++)
            {
                double s = 0;
                for (int j = 0; j < 4; j ++)
                    if (i != j) s += dist(p[i] , p[j]);
                res = min(res , s);
            }
        }
        printf("%.4f\n", res);
    }
    return 0;
}
