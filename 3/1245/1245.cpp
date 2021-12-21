#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

typedef struct
{
    char name[20];
    int p[7];
    int tot;
    int gavg;
    int num;
    int rank;
}Team;

int sort_cmp(Team &x, Team &y)
{
    if (x.num != y.num) return x.num > y.num;
    if (x.tot != y.tot) return x.tot < y.tot;
    if (x.gavg != y.gavg) return x.gavg < y.gavg;
    return strcmp(x.name, y.name) < 0;
}

int cmp(Team &x, Team &y)
{
    if (x.num > y.num) return 1; else if (x.num < y.num) return -1;
    if (x.tot < y.tot) return 1; else if (x.tot > y.tot) return -1;
    if (x.gavg < y.gavg) return 1; else if (x.gavg > y.gavg) return -1;
    return 0;
}

int main()
{
    int n, ca = 1;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        Team a[30];
        for (int i = 0; i < n; i++)
        {
            scanf("%s", a[i].name);
            a[i].tot = 0;
            a[i].num = 0;
            double gavg = 0.0;
            for (int j = 0; j < 7; j++)
            {
                scanf("%d", &a[i].p[j]);
                a[i].tot += a[i].p[j];
                if (a[i].p[j] > 0)
                {
                    a[i].num ++;
                    gavg += log((double)a[i].p[j]);
                }
            }
            if (a[i].num > 0) gavg = exp(gavg / a[i].num);
            a[i].gavg = (int)(gavg + 0.5);
        }
        sort(a, a + n, sort_cmp);
        a[0].rank = 1;
        for (int i = 1; i < n; i ++)
            if (cmp(a[i], a[i - 1]) < 0)
            {
                a[i].rank = i + 1;
            }
            else a[i].rank = a[i - 1].rank;
        printf("CONTEST %d\n", ca++);
        for (int i = 0; i < n; i++)
        {
            printf("%02d %-10s %d %4d %3d", a[i].rank, a[i].name, a[i].num, a[i].tot, (int)(a[i].gavg + 0.5));
            for (int j = 0; j < 7; j++) printf(" %3d", a[i].p[j]);
            printf("\n");
        }
    }
    return 0;
}
