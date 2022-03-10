#include <stdio.h>
#define max 2170000

long t[402] , min;
long wait;
long a[402][402] = {0};
long order[402];
long mark[402] = {0};
long p[402] = {0};
long tb[402] , tp[402] , r[402] , fc[402];
long n , m , s , tt;

long time(long ti , long x , long y)
{
long a , b , c1 , c2 , a1 , b1 , timea , timeb;
    
    a = ti;
    if (a < r[x]) {timea = r[x]; c1 = fc[x];}
    else
    {
        a -= r[x];
        if (fc[x] == 0) c1 = 1; else c1 = 0;
        while (1)
        {
            if ((c1 == 1) && (a >= tp[x])) {c1 = 0; a -= tp[x];}
            else if ((c1 == 0) && (a >= tb[x])) {c1 = 1; a-= tb[x];}
                else break;
        }
        if (c1 == 0) timea = tb[x]; else timea = tp[x];
    }
    b = ti;
    if (b < r[y]) {timeb = r[y]; c2 = fc[y];}
    else
    {
        b -= r[y];
        if (fc[y] == 0) c2 = 1; else c2 = 0;
        while (1)
        {
            if ((c2 == 1) && (b >= tp[y])) {c2 = 0; b -= tp[y];}
            else if ((c2 == 0) && (b >= tb[y])) {c2 = 1; b -= tb[y];}
                else break;
        }
        if (c2 == 0) timeb = tb[y]; else timeb = tp[y];
    }
    if (c1 == c2) return 0;
    a1 = timea - a; b1 = timeb - b;
    if (a1 != b1)
    {
        if (a1 < b1) return a1; else return b1;
    }
    else
    {
        if (c1 == 0)
        {
            if (tp[x] != tb[y])
            {
                if (tp[x] < tb[y]) return a1 + tp[x]; else return a1 + tb[y];
            }
            else
            {
                if (tb[x] != tp[y])
                {
                    if (tb[x] < tp[y]) return a1 + tp[x] + tb[x];
                    else return a1 + tp[x] + tp[y];
                }
                else return max;
            }
        }
        else
        {
            if (tb[x] != tp[y])
            {
                if (tb[x] < tp[y]) return a1 + tb[x]; else return a1 + tp[y];
            }
            else
            {
                if (tp[x] != tb[y])
                {
                    if (tp[x] < tb[y]) return a1 + tb[x] + tp[x];
                    else return a1 + tb[x] + tb[y];
                }
                else return max;
            }
        }
    }
}

int main()
{
long i , j , k , x , y;
char c;

    scanf("%ld %ld" , &s , &tt);
    scanf("%ld %ld" , &n , &m);
    for (i = 1; i <= n; i ++)
    {
        scanf("%c" , &c);
        scanf("%c %ld %ld %ld" , &c , &r[i] , &tb[i] , &tp[i]);
        if (c == 'B') fc[i] = 0; else fc[i] = 1;
    }
    for (i = 1; i <= m; i ++)
    {
        scanf("%ld %ld %ld" , &x , &y , &k);
        a[x][y] = k; a[y][x] = k;
    }
    //³õÖµ 
    mark[s] = 1;
    for (i = 1; i <= n; i ++)
        if (i == s) t[i] = 0;
        else
        {
            k = time(0 , s , i);
            if ((k == max) || (a[s][i] == 0)) t[i] = max;
            else t[i] = k + a[s][i];
            p[i] = s;
        }
    //Dijkstra
    for (i = 1; i <= n; i ++)
    {
        min = max; k = 0;
        for (j = 1; j <= n; j ++)
            if ((mark[j] == 0) && (t[j] < min))
            {
                min = t[j];
                k = j;
            }
        if (k == 0) break;
        mark[k] = 1;
        for (j = 1; j <= n; j ++)
            if ((a[k][j] > 0) && (t[k] < max) && (mark[j] == 0))
            {
                wait = time(t[k] , k , j);
                if (wait + t[k] + a[k][j] < t[j])
                {
                    t[j] = wait + t[k] + a[k][j];
                    p[j] = k;
                }
            }
    }
    if (t[tt] != max) printf("%ld\n" , t[tt]);
    else printf("0\n");
    return 0;
}
