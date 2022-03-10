#include <stdio.h>

int a[2001][2001] = {0} , day[2001] = {0};
int n , m;
int bo;

void find(int x)
{
int i , j;

    if (bo == 1) return;
    for (i = 1; i <= n; i ++)
        if (a[x][i] > 0)
        {
            if ((day[x] == 1) && (day[i] == 0)) {day[i] = 2; find(i);}
            else if ((day[x] == 2) && (day[i] == 0)) {day[i] = 1; find(i);}
            else if ((day[x] == 1) && (day[i] == 1)) {bo = 1; return;}
            else if ((day[x] == 2) && (day[i] == 2)) {bo = 1; return;}
        }
}

int main()
{
int x , y , k , i , tot , t , h , j;

    scanf("%d" , &t);
    for (h = 0; h < t; h ++)
    {
        
        scanf("%d %d" , &n , &m);
        for (i = 1; i <= n; i ++) day[i] = 0;
        for (i = 1; i <= n; i ++) for (j = 1; j <= n; j ++) a[i][j] = 0;
        for (i = 0; i < m; i ++) {scanf("%d %d" , &x , &y); a[x][y] = 1; a[y][x] = 1;}
        bo = 0;
        while (1)
        {
            k = 0;
            for (i = 1; i <= n; i ++) if (day[i] == 0) {k = i; break;}
            if (k == 0) break;
            day[k] = 1; 
            find(k);
            if (bo == 1) break;
        }
        printf("Scenario #%d:\n" , h + 1);
        if (bo == 1) printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}
