#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <map>
using namespace std;

int f[101];
int getF(int x)
{
    if (f[x] == x) return f[x];
    f[x] = getF(f[x]);
    return f[x];
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n;
        scanf("%d", &n);
        map<int, int> L;
        int a[101], b[101], ar[101], br[101];
        int id[101];
        for (int i = 0; i < n; i++)
        {
            int x;
            char s0[3], s1[3];
            scanf("%d %d %s %d %s", &x, &a[i], s0, &b[i], s1);
            ar[i] = (s0[0] == 'Y');
            br[i] = (s1[0] == 'Y');
            L[x] = i;
            id[i] = x;
        }
        int find = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            int ok = 1;
            for (int j = 0; j < n; j ++)
                if (j != i)
                {
                    if ((ar[j] == 0 && L[a[j]] != i) || (ar[j] == 1 && L[a[j]] == i)) { ok = 0; break; }
                    if ((br[j] == 0 && L[b[j]] != i) || (br[j] == 1 && L[b[j]] == i)) { ok = 0; break; }
                }
            if (ok) { find++; res = i; }
        }
        if (find == 1) printf("%d\n", id[res]);
        else printf("impossible\n");
    }
    return 0;
}