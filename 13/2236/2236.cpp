#include <stdio.h>
#include <math.h>

int x[1010] , y[1010] , father[1010] = {0} , a[1010] = {0};

int getfather(int x)
{
int f;
    
    if (father[x] == x) return x;
    else
    {
        f = getfather(father[x]);
        father[x] = f;
        return f;
    }
}

int main()
{
int n , d , k , t , p , q;
int i;
char c;

    scanf("%d %d" , &n , &d);
    for (i = 1; i <= n; i ++) {scanf("%d %d\n" , &x[i] , &y[i]); father[i] = i;}
    while (scanf("%c" , &c) == 1)
    {
        if (c == 'O')
        {
            scanf("%d" , &k);
            scanf("%c" , &c);
            a[k] = 1;
            for (i = 1; i <= n; i ++)
                if ((i != k) && (a[i] == 1) &&
                (sqrt((x[i]-x[k])*(x[i]-x[k]) + (y[i]-y[k])*(y[i]-y[k])) <= d))
                {
                    p = getfather(i);
                    father[p] = k;
                }
        }
        else
        {
            scanf("%d %d" , &k , &t);
            scanf("%c" , &c);
            p = getfather(k); q = getfather(t);
            if (p == q) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}
