#include <stdio.h>
#include <string.h>

char a[50][50];
int use[50][50];
int xsize, ysize;

void prepare(int n)
{
    memset(a, 0, sizeof(a));
    memset(use, 0, sizeof(use));
    xsize = 2 + 2 * n + n + 1 + n;
    ysize = 2 + n + n - 1 + 2 * (n - 1);
    for (int i = 0; i < xsize; i++)
    {
        a[0][i] = '*';
        a[ysize - 1][i] = '*';
    }
    for (int i = 1; i < ysize-1; i++)
    {
        a[i][0] = '*';
        a[i][xsize - 1] = '*';
    }
    //H
    for (int i = 1; i < ysize; i += 4)
        for (int j = 1; j < xsize; j += 4)
            a[i][j] = 'H';
    for (int i = 3; i < ysize; i += 4)
        for (int j = 3; j < xsize; j += 4)
            a[i][j] = 'H';
    //O
    for (int i = 1; i < ysize; i += 4)
        for (int j = 3; j < xsize; j += 4)
            a[i][j] = 'O';
    //fill space
    for (int i = 0; i < ysize; i++)
        for (int j = 0; j < xsize; j++)
            if (a[i][j] == 0) a[i][j] = ' ';
}

void add(int i, int j, int x)
{
    int po_i = 1 + 4 * i;
    int po_j = 3 + 4 * j;
    if (x == 1) //hori
    {
        use[po_i][po_j - 2] = use[po_i][po_j + 2] = 1;
        a[po_i][po_j - 1] = a[po_i][po_j + 1] = '-';
    }
    else if (x == -1) //vert
    {
        use[po_i - 2][po_j] = use[po_i + 2][po_j] = 1;
        a[po_i - 1][po_j] = a[po_i + 1][po_j] = '|';
    }
    else
    {
        //up or down
        if (po_i > 1 && use[po_i - 2][po_j] == 0)
        {
            use[po_i - 2][po_j] = 1; a[po_i - 1][po_j] = '|';
        }
        else
        {
            use[po_i + 2][po_j] = 1; a[po_i + 1][po_j] = '|';
        }
        if (use[po_i][po_j - 2] == 0)
        {
            use[po_i][po_j - 2] = 1; a[po_i][po_j - 1] = '-';
        }
        else
        {
            use[po_i][po_j + 2] = 1; a[po_i][po_j + 1] = '-';
        }
    }
}
int main()
{
    int ca = 1;
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        prepare(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int x;
                scanf("%d", &x);
                add(i, j, x);
            }
        printf("Case %d:\n\n", ca++);
        for (int i = 0; i < ysize; i++) printf("%s\n", a[i]);
        printf("\n");
    }
    return 0;
}