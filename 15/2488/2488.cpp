#include <stdio.h>

int n , m , done;
int a[26][26] , tot;
int p[8][2] = {{-2 , -1} , {-2 , 1} , {-1 , -2} , {-1 , 2} ,
               {1 , -2} , {1 , 2} , {2 , -1} , {2 , 1}};

void find(int step , int x , int y)
{
int i , j , k , s , t;

    if (done == 1) return;
    if (step == tot)
    {
        for (k = 1; k <= tot; k ++)
        {
            for (i = 0; i < n; i ++)
                for (j = 0; j < m; j ++)
                    if (a[i][j] == k) printf("%c%d" , 'A'+i , j+1);
        }
        done = 1; return;
    }
    else
    {
        for (i = 0; i < 8; i ++)
            {
                s = x + p[i][0]; t = y + p[i][1];
                if ((0 <= s) && (s < n) && (0 <= t) && (t < m))
                {
                    if (a[s][t] == 0)
                    {
                        step ++;
                        a[s][t] = step;
                        find(step , s , t);
                        if (done == 1) return;
                        a[s][t] = 0;
                        step --;
                    }
                }
            }
    }
}

int main()
{
int t , h;
int i , j , x , y;

    scanf("%d" , &t);
    for (h = 1; h <= t; h ++)
    {
        scanf("%d %d" , &m , &n);
        printf("Scenario #%d:\n" , h);
        done = 0; tot = n * m;
        for (i = 0; i < n; i ++)
        {
            for (j = 0; j < m; j ++)
            {
                for (x = 0; x < n; x ++) for (y = 0; y < m; y ++) a[x][y] = 0;
                a[i][j] = 1;
                find(1 , i , j);
                if (done == 1) {printf("\n"); break;}
            }
            if (done == 1) break;
        }
        if (done == 0) printf("impossible\n");
        printf("\n");
    }
    return 0;
}

