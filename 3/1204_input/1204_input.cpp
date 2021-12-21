#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define L 100
#define C 100
#define W 129
#define FOR(i,l,r) for (i=l;i<=r;i++)

using namespace std;

int fx[8] = { -1,-1,0,1,1, 1, 0,-1 },
fy[8] = { 0 ,1 ,1,1,0,-1,-1,-1 };
int p, x, y, i, j;
char map[1005][1005];
bool flag[1005][1005][8];

int main() {
    freopen("1204.in", "w", stdout);
    srand(time(0));
    FOR(i, 1, L) {
        FOR(j, 1, C) map[i][j] = 'A' + rand() % 26;
    }
    printf("%d %d %d\n", L, C, W);
    FOR(i, 1, L) {
        FOR(j, 1, C) printf("%c", map[i][j]);
        printf("\n");
    }
    FOR(i, 1, W) {
        p = rand() % 8;
        x = rand() % (L - 4) + 3;
        y = rand() % (C - 4) + 4;
        while (flag[x][y][p]) {
            p = rand() % 8;
            x = rand() % (L - 4) + 3;
            y = rand() % (C - 4) + 4;
        }
        flag[x][y][p] = true;
        while (x <= L && x >= 1 && y <= C && y >= 1) {
            printf("%c", map[x][y]);
            x += fx[p]; y += fy[p];
        }
        printf("\n");
    }
    return 0;
}
