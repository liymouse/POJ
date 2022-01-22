#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int main()
{
    int x, y;
    int sx = 100, sy = 100, ex = -1, ey = -1;
    char out[75][95] = { 0 };
    vector<pair<int, int> > a;
    int ca = 1;
    for (int yy = 1; yy <= 74; yy++) for (int xx = 1; xx <= 94; xx++) out[yy][xx] = '.';
    int minv[95], maxv[95] = { 0 };
    for (int i = 0; i <= 94; i++) { maxv[i] = 0;  minv[i] = 100; }
    while (scanf("%d %d", &x, &y) == 2)
    {
        if (x == 0 && y == 0) break;

        if (x == -1 && y == -1)
        {
            int minL = 1 << 30;
            int res = 0;
            for (int yy = sy; yy <= ey; yy++)
            {
                int sum = 0;
                for (int i = sx; i <= ex; i ++)
                    if (maxv[i] > 0)
                    {
                        if (minv[i] <= yy && yy <= maxv[i]) sum += maxv[i] - minv[i];
                        else sum += max(abs(minv[i] - yy), abs(maxv[i] - yy));
                    }
                if (sum < minL) {minL = sum; res = yy;}
            }
            printf("OIL FIELD %d\n", ca++);
            int bottom = (sy - 1) / 5 * 5;
            int top = (ey / 5 + 1) * 5;
            int left = (sx - 1) / 5 * 5;
            int right = (ex / 5 + 1) * 5;
            if (right - left <= 70 && top - bottom <= 20)
            {
                for (int xx = left + 1; xx <= right - 1; xx++)
                    if (out[res][xx] == '.') out[res][xx] = '*';
                for (int i = 0; i < a.size(); i++)
                {
                    int dy = a[i].second < res ? 1 : -1;
                    for (int yy = a[i].second; yy != res; yy += dy)
                        if (out[yy][a[i].first] == '.') out[yy][a[i].first] = '*';
                }
                //1st line
                printf("%d", top);
                for (int xx = left; xx <= right; xx++)
                    if (xx % 5 == 0) printf("+"); else printf("-");
                printf("\n");
                for (int yy = top - 1; yy > bottom; yy--)
                {
                    if (yy % 5 == 0)
                    {
                        if (top < 10) printf("%d+", yy);
                        else printf("%2d+", yy);
                    }
                    else
                    {
                        if (top < 10) printf(" |");
                        else printf("  |");
                    }
                    out[yy][right] = 0;
                    printf("%s", out[yy]+left+1);
                    if (yy % 5 == 0) printf("+\n");
                    else printf("|\n");
                }
                //last
                if (top < 10) printf("%d", bottom); else printf("%2d", bottom);
                for (int xx = left; xx <= right; xx++)
                    if (xx % 5 == 0) printf("+"); else printf("-");
                printf("\n");
                //x label
                if (top < 10) printf(" "); else printf("  ");
                for (int xx = left; xx < right; xx += 5) printf("%-5d", xx);
                printf("%d\n", right);
            }
            else
            {
                printf("Map is too big to draw for pipeline at %d\n", res);
            }
            for (int yy = 1; yy <= 74; yy++) for (int xx = 1; xx <= 94; xx++) out[yy][xx] = '.';
            a.clear();
            sx = 100, sy = 100, ex = -1, ey = -1;
            for (int i = 0; i <= 94; i++) { maxv[i] = 0;  minv[i] = 100; }
        }
        else
        {
            a.push_back(make_pair(x, y));
            out[y][x] = '@';
            sx = min(sx, x);
            sy = min(sy, y);
            ex = max(ex, x);
            ey = max(ey, y);
            maxv[x] = max(maxv[x], y);
            minv[x] = min(minv[x], y);
        }
    }
    return 0;
}