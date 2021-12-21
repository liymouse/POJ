#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x, y;
}Coord;

Coord a[10001], b[10001];
int n, m;
int from[10000], to[10000];

int check(Coord a[], Coord b[])
{
    int res = 0;
    for (int i = 0; i < m; i++)
        res += 1 + abs(a[from[i]].x - b[to[i]].x) + abs(a[from[i]].y - b[to[i]].y);
    return res;
}
void flip(Coord p[], int flip)
{
    for (int i = 0; i < n * n; i++)
    {
        if (flip == 0) //horizontal flip
        {
            p[i].y = n - 1 - p[i].y;
        }
        else
        {
            p[i].x = n - 1 - p[i].x;
        }
    }
}
void rotate(Coord p[])
{
    for (int i = 0; i < n*n; i++)
    {
        Coord org = p[i];
        p[i].x = org.y;
        p[i].y = n - 1 - org.x;
    }
}
int main()
{
    int ca = 1;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        for (int i = 0; i < n*n; i++)
        {
            a[i].x = b[i].x = i / n;
            a[i].y = b[i].y = i % n;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &from[i], &to[i]);
            from[i] --;
            to[i] --;
        }
        int res = 1 << 30;
        for (int i = 0; i < 4; i++)
        {
            int t = check(a, b);
            if (t < res) res = t;
            flip(b, i % 2);
            t = check(a, b);
            if (t < res) res = t;
            rotate(b);
        }
        printf("Scenario %d: smallest average = %.4lf\n\n", ca++, (double)res / m);
    }
    return 0;
}
