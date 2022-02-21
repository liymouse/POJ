#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

typedef struct {
    int sy, ey, x;
}Line;
int cmp(Line &x, Line &y)
{
    return x.x < y.x;
}

char a[8000][8000];
int n;
Line L[8000];
int v[32768]; //left can see which line
void updateVisible(int i, int tree_sy, int tree_ey, int id, int line_sy, int line_ey)
{
    if (v[i] != -1) { a[v[i]][id] = 1; return; }
    if (tree_sy == tree_ey) return;
    int m = (tree_sy + tree_ey) >> 1;
    if (line_sy <= m) updateVisible(i * 2 + 1, tree_sy, m, id, line_sy, line_ey);
    if (line_ey > m) updateVisible(i * 2 + 2, m + 1, tree_ey, id, line_sy, line_ey);
}
void addLine(int i, int tree_sy, int tree_ey, int id, int line_sy, int line_ey)
{
    //full cover
    if (line_sy <= tree_sy && tree_ey <= line_ey) { v[i] = id; return; }
    if (v[i] != -1) { v[i * 2 + 1] = v[i * 2 + 2] = v[i]; v[i] = -1; }
    int m = (tree_sy + tree_ey) >> 1;
    if (line_sy <= m) addLine(i * 2 + 1, tree_sy, m, id, line_sy, line_ey);
    if (line_ey > m) addLine(i * 2 + 2, m + 1, tree_ey, id, line_sy, line_ey);
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        
        scanf("%d", &n);
        int miny = 9000, maxy = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &L[i].sy, &L[i].ey, &L[i].x);
            L[i].sy *= 2; L[i].ey *= 2;
            miny = min(miny, L[i].sy);
            maxy = max(maxy, L[i].ey);
        }
        sort(L, L + n, cmp);
        memset(a, 0, sizeof(a));
        memset(v, 0xff, sizeof(v));
        for (int i = 0; i < n; i++)
        {
            updateVisible(0, miny, maxy, i, L[i].sy, L[i].ey);
            addLine(0, miny, maxy, i, L[i].sy, L[i].ey);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i][j])
                    for (int k = j + 1; k < n; k++)
                        if (a[i][k] && a[j][k]) res++;
        printf("%d\n", res);
    }
    return 0;
}
