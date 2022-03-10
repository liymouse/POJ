#include <stdio.h>

int main()
{
    int n , x , y;
    while (scanf("%d %d %d" , &n , &x , &y) == 3)
    {
        if (n == 0 && x == 0 && y == 0) break;
        char a[11][10] = {0};
        int b[11][10] = {0};
        for (int i = 0; i < n; i ++)
        {
            char s[10];
            int xx , yy;
            scanf("%s %d %d" , s , &xx , &yy);
            a[xx][yy] = s[0];
        }
        for (int i = 1; i <= 10; i ++)
            for (int j = 1; j <= 9; j ++)
            {
                if (a[i][j] == 'G')
                {
                    for (int k = i-1; k >= 1; k --)
                    { 
                        b[k][j] = 1;
                        if (a[k][j] != 0) break;
                    }
                }
                else if (a[i][j] == 'R')
                {
                    for (int k = i+1; k <= 10; k ++)
                    {
                        b[k][j] = 1;
                        if (a[k][j] != 0) break;
                    }
                    for (int k = i-1; k >= 1; k --)
                    {
                        b[k][j] = 1;
                        if (a[k][j] != 0) break;
                    }
                    for (int k = j+1; k <= 9; k ++)
                    {
                        b[i][k] = 1;
                        if (a[i][k] != 0) break;
                    }
                    for (int k = j-1; k >= 1; k --)
                    {
                        b[i][k] = 1;
                        if (a[i][k] != 0) break;
                    }
                }
                else if (a[i][j] == 'H')
                {
                    int p[8][2] = {{-2,-1} , {-2,1} , {-1,2} , {1,2} , {2,1} , {2,-1} , {1,-2} , {-1,-2}};
                    int q[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};
                    for (int k = 0; k < 8; k ++)
                    {
                        int xx = i + p[k][0];
                        int yy = j + p[k][1];
                        int x1 = i + p[k/2][0];
                        int y1 = i + p[k/2][1];
                        if (xx >= 1 && xx <= 10 && yy >= 1 && yy <= 9 && a[x1][y1] == 0)
                        {
                            b[xx][yy] = 1;
                        }
                    }
                }
                else if (a[i][j] == 'C')
                {
                    int has = 0 , k;
                    for (k = i+1; k <= 10; k ++)
                        if (a[k][j] != 0) {has = 1; break;}
                    if (has)
                    {
                        k ++;
                        for (; k <= 10; k ++)
                        {
                            b[k][j] = 1;
                            if (a[k][j] != 0) break;
                        }
                    }
                    has = 0;
                    for (k = i-1; k >= 1; k --)
                        if (a[k][j] != 0) {has = 1; break;}
                    if (has)
                    {
                        k --;
                        for (; k >= 1; k --)
                        {
                            b[k][j] = 1;
                            if (a[k][j] != 0) break;
                        }
                    }
                    has = 0;
                    for (k = j+1; k <= 9; k ++)
                        if (a[i][k] != 0) {has = 1; break;}
                    if (has)
                    {
                        k ++;
                        for (; k <= 9; k ++)
                        {
                            b[i][k] = 1;
                            if (a[i][k] != 0) break;
                        }
                    }
                    has = 0;
                    for (k = j-1; k >= 1; k --)
                        if (a[i][k] != 0) {has = 1; break;}
                    if (has)
                    {
                        k --;
                        for (; k >= 1; k --)
                        {
                            b[i][k] = 1;
                            if (a[i][k] != 0) break;
                        }
                    }
                }
            }
        int ok = 0;
        if (x - 1 >= 1 && b[x-1][y] == 0) ok = 1;
        if (x + 1 <= 3 && b[x+1][y] == 0) ok = 1;
        if (y - 1 >= 4 && b[x][y-1] == 0) ok = 1;
        if (y + 1 <= 6 && b[x][y+1] == 0) ok = 1;
        for (int k = x + 1; k <= 10; k ++) 
        {
            if (a[k][y] == 0) continue;
            if (a[k][y] == 'G') ok = 1;
            break;
        }
        if (ok) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}