#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct {
    int x, y;
}Node;
char m[5001][5001] = { 0 };

int cmp(Node &x, Node &y)
{
    if (x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    int n;
    scanf("%d", &n);
    Node p[5005];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
        m[p[i].x][p[i].y] = 1;
    }
    sort(p, p + n, cmp);
    int res = 0;
    for (int i = 0; i < n; i ++)
        for (int j = i + 1; j < n; j++)
        {
            int a = p[j].x - p[i].x;
            int b = p[j].y - p[i].y;
            if (p[i].x - a < 1 || p[i].y - b < 1 || p[i].y - b > c)
            {
                int st = 100000;
                if (a > 0) st = (r - p[i].x) / a + 1;
                if (b > 0 && (c - p[i].y) / b + 1 < st) st = (c - p[i].y) / b + 1;
                else if (b < 0 && (p[i].y - 1) / (-b) + 1 < st) st = (p[i].y - 1) / (-b) + 1;
                if (st <= res) continue;
                int x = p[j].x + a;
                int y = p[j].y + b;
                while (1 <= x && x <= r && 1 <= y && y <= c && m[x][y]) { x += a; y += b; }
                if (x < 1 || x > r || y < 1 || y > c) res = st;
            }
        }
    if (res < 3) res = 0;
    printf("%d\n", res);
}