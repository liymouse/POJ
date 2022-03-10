#include <stdio.h>

typedef struct{
    int x , y , step , pre;
}node;
node qu[100];
int main()
{
    int a[5][5] , f[5][5];
    int p[4][2] = {{-1 , 0} , {0 , -1} , {1 , 0} , {0 , 1}};
    int r = 1 , t = 0;
    for (int i = 0; i < 5; i ++) for (int j = 0; j < 5; j ++) scanf("%d" , &a[i][j]);
    qu[0].x = 0; qu[0].y = 0; qu[0].step = 0; qu[0].pre = -1;
    for (int i = 0; i < 5; i ++) for (int j = 0; j < 5; j ++) f[i][j] = 30;
    f[0][0] = 0;
    while (t < r)
    {
        if (qu[t].x == 4 && qu[t].y == 4) break;
        for (int i = 0; i < 4; i ++)
        {
            int x = qu[t].x + p[i][0];
            int y = qu[t].y + p[i][1];
            if (0 <= x && x < 5 && 0 <= y && y < 5 && a[x][y] == 0 && qu[t].step + 1 < f[x][y])
            {
                f[x][y] = qu[t].step + 1;
                qu[r].x = x; qu[r].y = y; qu[r].step = qu[t].step + 1; qu[r].pre = t;
                r ++;
            }
        }
        t ++;
    }
    int k = t;
    int road[100] , n = 0;
    while (k != -1)
    {
        road[n ++] = k;
        k = qu[k].pre;
    }
    for (int i = n-1; i >= 0; i --) printf("(%d, %d)\n" , qu[road[i]].x , qu[road[i]].y);
    return 0;
}
