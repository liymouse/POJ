#include <stdio.h>
#include <vector>
using namespace std;
typedef struct
{
    int a[20];
    int n;
    int has;
}SQ;

void init(vector<SQ> &a, int n)
{
    int line = 2 * n + 1;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j++)
        {
            for (int L = 1; L <= n; L ++)
                if (L <= n - i && L <= n - j)
                {
                    SQ x;
                    memset(x.a, 0, sizeof(x.a));
                    x.n = 0;
                    x.has = 1;
                    //up
                    for (int k = 1; k <= L; k++) x.a[x.n++] = (i*line + j) + k;
                    //down
                    for (int k = 1; k <= L; k++) x.a[x.n++] = ((i + L)*line + j) + k;
                    //left & right
                    for (int k = 0; k < L; k++)
                    {
                        x.a[x.n++] = ((i + k)*line + j + n) + 1;
                        x.a[x.n++] = ((i + k)*line + j + n) + 1 + L;
                    }
                    a.push_back(x);
                }
        }
}
void remove(vector<SQ> &a, int x)
{
    for (int i = 0; i < a.size(); i ++)
        if (a[i].has)
        {
            for (int j = 0; j < a[i].n; j ++)
                if (a[i].a[j] == x)
                {
                    a[i].has = 0;
                    break;
                }
        }
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        vector<SQ> a;
        init(a, n);
        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int x;
            scanf("%d", &x);
            remove(a, x);
        }
        int res = 0;
        while (1)
        {
            int ok = 1;
            for (int i = 0; i < a.size(); i ++)
                if (a[i].has) { ok = 0; break; }
            int num[70] = { 0 };
            for (int i = 0; i < a.size(); i ++)
                if (a[i].has)
                {
                    for (int j = 0; j < a[i].n; j++) num[a[i].a[j]] ++;
                }
            int k = -1;
            int maxv = 0;
            for (int i = 0; i < 70; i ++)
                if (num[i] > maxv)
                {
                    maxv = num[i];
                    k = i;
                }
            if (k == -1) break;
            remove(a, k);
            res++;
        }
        printf("%d\n", res);
    }
    return 0;
}