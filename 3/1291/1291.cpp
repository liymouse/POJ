#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct
{
    int id;
    int num;
}Elm;

int cmp(Elm &x, Elm &y)
{
    return x.num > y.num;
}
int f[1001];

int getF(int x)
{
    if (x == f[x]) return x;
    f[x] = getF(f[x]);
    return f[x];
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        for (int i = 1; i <= n; i++) f[i] = i;
        int bad = 0;
        int id[1001], judge[1001];
        int check[1001];
        for (int i = 1; i <= n; i++)
        {
            char s1[20], s2[20], s3[20];
            int x;
            scanf("%s %d %s %s", s1, &x, s2, s3);
            id[i] = x; judge[i] = (s3[0] == 't');
            if (s3[0] == 'f' && x == i) bad = 1;
            else if (s3[0] == 't')
            {
                int a = getF(i);
                int b = getF(x);
                f[a] = b;
                check[i] = 1;
            }
            else check[i] = -1;
        }
        if (bad) printf("Inconsistent\n");
        else
        {
            Elm a[1001];
            for (int i = 1; i <= n; i++)
            {
                a[i].id = i; a[i].num = 0;
            }
            for (int i = 1; i <= n; i ++) a[getF(i)].num ++;
            sort(a+1, a + n+1, cmp);
            int res = 0;
            int k = 1;
            while (k <= n)
            {
                if (a[k].num == 0) break;
                if (judge[a[k].id]) res += a[k].num;
                else
                {
                    if (check[id[a[k].id]] == 1) //a[k].id must be false
                    {
                        if (check[a[k].id] == 1) { bad = 1; break; }
                        check[a[k].id] = 0;
                    }
                    else
                    {
                        if (check[a[k].id] == 0) { bad = 1; break; }
                        check[a[k].id] = 1;
                        check[id[a[k].id]] = 0;
                        res += a[k].num;
                    }
                }
                k++;
            }
            if (bad) printf("Inconsistent\n");
            printf("%d\n", res > n - res ? res : n - res);
        }
    }
    return 0;
}