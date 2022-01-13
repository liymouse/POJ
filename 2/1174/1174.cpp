#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct
{
    int L , t, num;
}Type;

int a, b, n;
char s[2000010];
vector<Type> res;
int num[13][1 << 12] = { 0 };

int cmp(Type &x, Type &y)
{
    if (x.num == y.num)
    {
        if (x.L == y.L) return x.t > y.t;
        return x.L > y.L;
    }
    return x.num > y.num;
}
int main()
{
    //freopen("contact5.in", "r", stdin);
    scanf("%d %d %d %s", &a, &b, &n, s);
    int len = strlen(s)-1;
    s[len] = 0;
    int x = 0, y = 0, L = 1;
    if (len >= L)
    {
        int t = s[0] - '0';
        while (L < a) { y++; t = (t << 1) + s[y] - '0'; L++; }
        while (x <= len - a)
        {
            num[L][t] ++;
            while (y < len-1 && L < b)
            {
                y++; L++;
                t = (t << 1) + s[y] - '0';
                num[L][t] ++;
            }
            y = a + x;
            if (y >= len) break;
            x++;
            t = (t >> (L - 1 - a)) & (~(1 << a));
            L = a;
        }
        for (int L = a; L <= b; L ++)
            for (int t = 0; t < (1<<L); t ++)
                if (num[L][t])
                {
                    Type k;
                    k.L = L;
                    k.t = t;
                    k.num = num[L][t];
                    res.push_back(k);
                }
        sort(res.begin(), res.end(), cmp);
        int rank = 0;
        int i = 0;
        while (i < res.size() && rank < n)
        {
            if (rank < n)
            {
                int p = res[i].num;
                if (p == 0) break;
                printf("%d", p);
                while (i < res.size() && res[i].num == p)
                {
                    char s[20] = { 0 };
                    int k = res[i].t;
                    for (int j = res[i].L-1; j >= 0; j--)
                    {
                        s[j] = '0' + k % 2;
                        k /= 2;
                    }
                    printf(" %s", s);
                    i++;
                }
                printf("\n");
                rank++;
            }
        }
    }
    return 0;
}