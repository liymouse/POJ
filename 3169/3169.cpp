#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define MAX 2000000000
int main()
{
    int n, ml, md;
    int al[10002], bl[10002], dl[10002];
    int ad[10002], bd[10002], dd[10002];
    int d[1002];
    scanf("%d %d %d", &n, &ml, &md);
    for (int i = 0; i < ml; i++)
    {
        scanf("%d %d %d", &al[i], &bl[i], &dl[i]);
        al[i] --; bl[i] --;
    }
    for (int i = 0; i < md; i++)
    {
        scanf("%d %d %d", &ad[i], &bd[i], &dd[i]);
        ad[i] --; bd[i] --;
    }
    for (int i = 0; i < n; i++) d[i] = MAX;
    d[0] = 0;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n - 1; i++)
            if (d[i + 1] < MAX)
            {
                d[i] = min(d[i], d[i + 1]);
            }
        for (int i = 0; i < ml; i++)
            if (d[al[i]] < MAX)
            {
                d[bl[i]] = min(d[bl[i]], d[al[i]] + dl[i]);
            }
        for (int i = 0; i < md; i ++)
            if (d[bd[i]] < MAX)
            {
                d[ad[i]] = min(d[ad[i]], d[bd[i]] - dd[i]);
            }
    }
    if (d[0] < 0) printf("-1\n");
    else if (d[n-1] == MAX) printf("-2\n");
    else printf("%d\n", d[n-1]);
    return 0;
}