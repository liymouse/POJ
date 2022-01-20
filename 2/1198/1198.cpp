#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

char has[61][62][63][64] = { 0 };
typedef struct
{
    int a[4];
}State;

int p[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int main()
{
    //memset(has, 0, sizeof(has));
    int x, y;
    State a;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &x, &y); a.a[i] = (x-1) * 8 + y-1;
    }
    sort(a.a, a.a + 4);
    has[a.a[0]][a.a[1]][a.a[2]][a.a[3]] = 1;
    queue<State> begin, end;
    begin.push(a);

    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &x, &y); a.a[i] = (x-1) * 8 + y-1;
    }
    sort(a.a, a.a + 4);
    if (has[a.a[0]][a.a[1]][a.a[2]][a.a[3]] != 0) printf("YES\n");
    else
    {
        has[a.a[0]][a.a[1]][a.a[2]][a.a[3]] = -1;
        end.push(a);
        int ok = 0;
        while (!begin.empty() || !end.empty())
        {
            if (!begin.empty())
            {
                a = begin.front();
                begin.pop();
                int step = has[a.a[0]][a.a[1]][a.a[2]][a.a[3]];
                int map[8][8] = { 0 };
                for (int i = 0; i < 4; i++) map[a.a[i] / 8][a.a[i] % 8] = 1;
                for (int i = 0; i < 4; i++)
                {
                    x = a.a[i] / 8; y = a.a[i] % 8;
                    for (int j = 0; j < 4; j++)
                    {
                        int xx = x + p[j][0];
                        int yy = y + p[j][1];
                        int can = 0;
                        if (0 <= xx && xx < 8 && 0 <= yy && yy < 8 && map[xx][yy] == 0) can = 1;
                        else
                        {
                            xx += p[j][0]; yy += p[j][1];
                            if (0 <= xx && xx < 8 && 0 <= yy && yy < 8 && map[xx][yy] == 0) can = 1;
                        }
                        if (can)
                        {
                            State b = a;
                            b.a[i] = xx * 8 + yy;
                            sort(b.a, b.a + 4);
                            if (has[b.a[0]][b.a[1]][b.a[2]][b.a[3]] < 0)
                            {
                                ok = 1; goto L_exit;
                            }
                            else if (has[b.a[0]][b.a[1]][b.a[2]][b.a[3]] == 0)
                            {
                                has[b.a[0]][b.a[1]][b.a[2]][b.a[3]] = step + 1;
                                if (step + 1 < 5) begin.push(b);
                            }
                        }
                    }
                }
            }
            if (!end.empty())
            {
                a = end.front();
                end.pop();
                int step = has[a.a[0]][a.a[1]][a.a[2]][a.a[3]];
                int map[8][8] = { 0 };
                for (int i = 0; i < 4; i++) map[a.a[i] / 8][a.a[i] % 8] = 1;
                for (int i = 0; i < 4; i++)
                {
                    x = a.a[i] / 8; y = a.a[i] % 8;
                    for (int j = 0; j < 4; j++)
                    {
                        int xx = x + p[j][0];
                        int yy = y + p[j][1];
                        int can = 0;
                        if (0 <= xx && xx < 8 && 0 <= yy && yy < 8 && map[xx][yy] == 0) can = 1;
                        else
                        {
                            xx += p[j][0]; yy += p[j][1];
                            if (0 <= xx && xx < 8 && 0 <= yy && yy < 8 && map[xx][yy] == 0) can = 1;
                        }
                        if (can)
                        {
                            State b = a;
                            b.a[i] = xx * 8 + yy;
                            sort(b.a, b.a + 4);
                            if (has[b.a[0]][b.a[1]][b.a[2]][b.a[3]] > 0)
                            {
                                ok = 1; goto L_exit;
                            }
                            else if (has[b.a[0]][b.a[1]][b.a[2]][b.a[3]] == 0)
                            {
                                has[b.a[0]][b.a[1]][b.a[2]][b.a[3]] = step - 1;
                                if (step - 1 > -5) end.push(b);
                            }
                        }
                    }
                }
            }
        }
    L_exit:
        if (ok) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}