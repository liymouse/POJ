#include <stdio.h>

int father[10010];
int getfather(int x)
{
    if (father[x] == x) return x;
    father[x] = getfather(father[x]);
    return father[x];
}
int main()
{
    int n , x , y;
    while (scanf("%d" , &n) == 1)
    {
        char command[3];
        int yes = 0 , no = 0;
        for (int i = 1; i <= n; i ++) father[i] = i;
        while (scanf("%s" , command) == 1)
        {
            if (command[0] == 'e') break;
            else if (command[0] == 'c')
            {
                scanf("%d %d" , &x , &y);
                x = getfather(x);
                y = getfather(y);
                father[x] = y;
            }
            else if (command[0] == 'd')
            {
                scanf("%d" , &x);
                int t = -1;
                for (int i = 1; i <= n; i ++) if (getfather(i) == x && i != x) {t = i; break;}
                if (t != -1)
                {
                    for (int i = 1; i <= n; i ++)
                        if (getfather(i) == x && i != x) father[i] = t;
                }
                father[x] = x;
            }
            else
            {
                scanf("%d %d" , &x , &y);
                if (getfather(x) == getfather(y)) yes ++;
                else no ++;
            }
        }
        printf("%d , %d\n" , yes , no);
    }
    return 0;
}
