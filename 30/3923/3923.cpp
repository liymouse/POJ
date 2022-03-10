#include <stdio.h>

int main()
{
    int m , n;
    while (scanf("%d %d" , &m , &n) == 2)
    {
        if (m == 0 && n == 0) break;
        char a[120][120];
        for (int i = 0; i < m; i ++) scanf("%s" , a[i]);
        for (int k = 0; k < 26; k ++)
        {
            int x1 = -1 , y1 , x2 , y2 , x3 , y3 , x4 , y4;
            for (int i = 0; i < m; i ++) for (int j = 0; j < n; j ++)
                if (a[i][j] == 'A' + k) {x1 = i; y1 = j; goto Loop1;}
Loop1:      for (int i = 0; i < m; i ++) for (int j = n-1; j >= 0; j --)
                if (a[i][j] == 'A' + k) {x2 = i; y2 = j; goto Loop2;}
Loop2:      for (int i = m-1; i >= 0; i --) for (int j = 0; j < n; j ++)
                if (a[i][j] == 'A' + k) {x3 = i; y3 = j; goto Loop3;}
Loop3:      for (int i = m-1; i >= 0; i --) for (int j = n-1; j >= 0; j --)
                if (a[i][j] == 'A' + k) {x4 = i; y4 = j; goto Loop4;}
Loop4:      if (x1 == -1) continue;
            if (x1 == x2 && y2 > y1 && x3 == x4 && y4 > y3 && 
                y1 == y3 && x3 > x1 && y2 == y4 && x4 > x2)
            {
                int ok = 1;
                for (int j = y1; j <= y2; j ++)
                    if (a[x1][j] != 'A' + k || a[x3][j] != 'A' + k) {ok = 0; break;}
                for (int i = x1; i <= x3; i ++)
                    if (a[i][y1] != 'A' + k || a[i][y2] != 'A' + k) {ok = 0; break;}
                for (int i = x1+1; i <= x3-1; i ++)
                    for (int j = y1+1; j <= y2-1; j ++)
                        if (a[i][j] != '.') {ok = 0; goto Loop5;}
Loop5:          if (ok) printf("%c" , 'A' + k);
            }
        }
        printf("\n");
    }
    return 0;
}
