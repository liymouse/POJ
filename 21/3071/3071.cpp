#include <stdio.h>
#include <stdlib.h>

const int st[8] = {1,2,4,8,16,32,64,128};
int n,m;
double p[200][200],a[200][10];

void work()
{
int i,j,k;
double s,o,w;
    for (j=1;j<=m;j++)
    {
        if (j % 2 == 0)
        {
           a[j][1] = p[j][j-1];
        } 
        else
        {
           a[j][1] = p[j][j+1];
        }
    }
    for (i=2;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            s = 0;
            for (k=1;k<=m;k++)
            {
                if ((((k-1) / st[i-1]) != ((j-1) / st[i-1])) && ((((k-1) / st[i]) == ((j-1) / st[i]))))
                {
                   s = s + p[j][k]*a[k][i-1];
                }
            }
            a[j][i] = s * a[j][i-1];
        }
    }
}

int main()
{
int i,j,maxi;
double max;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while (true)
    {
        scanf("%d\n",&n);
        if (n == -1){return 0;}
        m = st[n];
        for (i=1;i<=m;i++)
        {
            for (j=1;j<=m;j++)
            {
                scanf("%lf",&p[i][j]);
            }
            scanf("\n");
        }
        for (i=1;i<=m;i++)
        {
            for (j=1;j<=n;j++)
            {
                a[i][j] = 0;
            }
        }
        work();
        max = 0;
        maxi = 1;
        for (i=1;i<=m;i++)
        {
            if (max<a[i][n])
            {
               max = a[i][n];
               maxi = i;
            }
        }
        printf("%d\n",maxi);
    }
}
