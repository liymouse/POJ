#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 101

int n; //number of vertex (index from 1 to n)
int a[MAX][MAX];  //map (max capacity)

//get the maxflow from begin to end
int maxflow(int begin, int end)
{
    int p[MAX];  //check
    int L[MAX];  //flag
    int f[MAX][MAX];  //flow
    int done = 0;
    int res = 0;

    memset(f, 0, sizeof(f));
    while (done == 0)
    {
        done = 0;
        memset(L, 0, sizeof(L));
        memset(p, 0, sizeof(p));
        L[begin] = begin;
        while (1)
        {
            //find the uncheck point with label 0
            int i = begin;
            while ((i <= n) && !((L[i] != 0) && (p[i] == 0))) i++;
            //all point have been labeled , goto next step
            if (i > n) { done = 1; break; }

            //label the adjacent point of point i
            for (int j = 1; j <= n; j++)
                if ((L[j] == 0) && ((a[i][j] > 0) || (a[j][i] > 0)))
                {
                    if (f[i][j] < a[i][j]) L[j] = i;
                    if (f[j][i] > 0) L[j] = -i;
                }
            //checked point i
            p[i] = 1;
            //if end point have been labeled , goto next step
            if (L[end] != 0) break;
        }
        if (done == 0)
        {
            //search from end to begin to find min improvable flow
            int now = end;
            int minF = 0x7fffffff;
            while (now != begin)
            {
                int last = now;
                now = (int)fabs(L[last]);
                int x = (L[last] < 0) ? f[last][now] : a[now][last] - f[now][last];
                minF = min(minF, x);
            }
            //update the flow
            now = end;
            while (now != begin)
            {
                int last = now;
                now = (int)fabs(L[last]);
                if (L[last] < 0) f[last][now] -= minF;
                if (L[last] > 0) f[now][last] += minF;
            }
        }
    }
    for (int i = 1; i <= n; i++) res += f[i][end];
    return res;
}

int main()
{
    int max;

    //TODO: read map
    n = 10;
    max = maxflow(1, n);
    printf("%d\n", max);
    return 0;
}