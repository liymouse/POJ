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
int f[2001];

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
        //1~n = true  n+1~n+n = false
        for (int i = 1; i <= 2*n; i++) f[i] = i;
        int bad = 0;
        for (int i = 1; i <= n; i++)
        {
            char s1[20], s2[20], s3[20];
            int x;
            scanf("%s %d %s %s", s1, &x, s2, s3);
            if (s3[0] == 't')
            {
                //i,x must both true or both false
                if (getF(i) == getF(x + n) || getF(i + n) == getF(x)) bad = 1;
                else
                {
                    f[getF(i)] = getF(x);
                    f[getF(i + n)] = getF(x + n);
                }
            }
            else
            {
                //i,x must in different union
                if (getF(i) == getF(x) || getF(i + n) == getF(x + n)) bad = 1;
                else
                {
                    f[getF(i)] = getF(x + n);
                    f[getF(i + n)] = getF(x);
                }
            }
        }
        if (bad) printf("Inconsistent\n");
        else
        {
            char checked[2001] = { 0 };
            int num[2001] = { 0 };
            int res = 0;
            for (int i = 1; i <= n; i ++) num[getF(i)] ++;
            for (int i = 1; i <= n; i++)
            {
                //if sentense i has been checked
                if (checked[getF(i)] || checked[getF(i + n)]) continue;
                res += max(num[getF(i)], num[getF(i + n)]);
                checked[getF(i)] = checked[getF(i + n)] = 1;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}