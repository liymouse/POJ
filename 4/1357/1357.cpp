#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
typedef struct {
    int x, y, t, predir;
}Node;
Node heap[10005];
int heapn;
int p[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
char a[105][105];

void heapPop()
{
    heap[0] = heap[heapn - 1];
    heapn--;
    int k = 0;
    while (k * 2 + 1 < heapn)
    {
        int j = k * 2 + 1;
        if (j + 1 < heapn && heap[j + 1].t < heap[j].t) j++;
        if (heap[k].t < heap[j].t) break;
        Node tmp = heap[k]; heap[k] = heap[j]; heap[j] = tmp;
        k = j;
    }
}
void heapShiftUp(int x)
{
    while (x > 0 && heap[x].t < heap[(x - 1) / 2].t)
    {
        Node tmp = heap[x]; heap[x] = heap[(x - 1) / 2]; heap[(x - 1) / 2] = tmp;
        x = (x - 1) / 2;
    }
}
void addHeap(int x, int y, int t, int predir)
{
    heap[heapn].t = t;
    heap[heapn].x = x;
    heap[heapn].y = y;
    heap[heapn].predir = predir;
    heapShiftUp(heapn);
    heapn++;
}
int getNext(int x, int y, int d, int curt)
{
    if (a[x][y] == '+') return 1;
    int change = a[x][y] - '0';
    int has[4] = { 0 };
    int n = 0;
    for (int i = 0; i < 4; i ++)
        if ((i % 2 == 0 && a[x + p[i][0]][y + p[i][1]] == '|') ||
            (i % 2 == 1 && a[x + p[i][0]][y + p[i][1]] == '-'))
        {
            has[i] = 1;
            n++;
        }
    d = (d + 2) % 4;
    int s = has[0] ? 0 : 2;
    int num = 0;
    while (s != d) {
        num++;
        s = (s + 1) % 4;
        while (has[s] == 0) s = (s + 1) % 4;
    }
    curt %= n * change;
    int curnum = curt / change;
    if (curnum == num) return 1;
    else if (curnum < num) return num*change - curt + 1;
    else return num*change - curt + n * change + 1;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n, m;
        int t[105][105];
        scanf("%d %d", &n, &m); gets_s(a[0]);
        memset(t, 0xff, sizeof(t));
        int sx, sy, ex, ey;
        for (int i = 0; i < n; i++)
        {
            gets_s(a[i]);
            for (int j = 0; j < m; j ++)
                if (a[i][j] == 'S') { sx = i; sy = j; }
                else if (a[i][j] == 'D') { ex = i; ey = j; }
        }
        heapn = 0;
        memset(heap, 0, sizeof(heap));
        for (int i = 0; i < 4; i++)
        {
            if ((i % 2 == 0 && a[sx + p[i][0]][sy + p[i][1]] == '|') ||
                (i % 2 == 1 && a[sx + p[i][0]][sy + p[i][1]] == '-'))
            {
                addHeap(sx + p[i][0], sy + p[i][1], 1, i);
                t[sx + p[i][0]][sy + p[i][1]] = 1;
            }
        }
        while (heapn)
        {
            Node x = heap[0];
            heapPop();
            if (x.t > t[x.x][x.y]) continue;
            int xx = x.x + p[x.predir][0];
            int yy = x.y + p[x.predir][1];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (a[xx][yy] == '*' || a[xx][yy] == ' ' || a[xx][yy] == 'S') continue;
            if (x.predir % 2 == 0 && a[xx][yy] == '-') continue;
            if (x.predir % 2 == 1 && a[xx][yy] == '|') continue;
            if (a[xx][yy] == 'D') { t[xx][yy] = x.t; goto L_exit; }
            if ((a[xx][yy] == '-' || a[xx][yy] == '|'))
            {
                if (t[xx][yy] == -1 || x.t + 1 < t[xx][yy])
                {
                    addHeap(xx, yy, x.t + 1, x.predir);
                    t[xx][yy] = x.t + 1;
                }
            }
            else
            {
                int nextt = getNext(xx, yy, x.predir, x.t);
                for (int j = 0; j < 4; j++)
                    if (j != (x.predir + 2) % 4)
                    {
                        int nx = xx + p[j][0];
                        int ny = yy + p[j][1];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if ((j % 2 == 0 && a[nx][ny] == '|') ||
                            (j % 2 == 1 && a[nx][ny] == '-'))
                        {
                            if (t[nx][ny] == -1 || x.t + nextt < t[nx][ny])
                            {
                                addHeap(nx, ny, x.t + nextt, j);
                                t[nx][ny] = x.t + nextt;
                            }
                        }
                    }
            }
        }
        L_exit:
        if (t[ex][ey] == -1) printf("impossible\n");
        else printf("%d\n", t[ex][ey]);
    }
    return 0;
}
