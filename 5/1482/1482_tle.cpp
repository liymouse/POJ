#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    int must_bug, must_fix;
    int process_bug, process_fix;
    int t;
}Patch;
int memo[1 << 20];
Patch a[100];
int n, m;

int find(int s)
{
    if (s == (1 << n) - 1) return 0;
    if (memo[s] != -1) return memo[s];
    memo[s] = -2;
    int res = -2;
    for (int i = 0; i < m; i ++)
        if ((s & a[i].process_bug) == a[i].process_bug &&
            (s | a[i].process_fix) == a[i].process_fix)
        {
            int can_change = (a[i].must_bug ^ a[i].must_fix) & (a[i].process_bug | (~a[i].process_fix));
            int num = 0;
            int change_bit[10];
            for (int i = 0; i < n; i ++)
                if (can_change & (1 << i)) change_bit[num++] = i;
            int st = s & (a[i].must_bug ^ a[i].must_fix); //0 keep same as s
            st |= a[i].must_bug; //set +
            st &= a[i].must_fix; //set -
            for (int j = 0; j < 1 << num; j++)
            {
                for (int k = 0; k < num; k ++)
                    if (j & (1 << k)) st |= 1 << change_bit[k];
                    else st &= ~(1 << change_bit[k]);
                int ans = find(st);
                if (ans >= 0)
                {
                    if (res < 0 || ans + a[i].t < res) res = ans + a[i].t;
                }
            }
        }
    memo[s] = res;
    return res;
}

int main()
{
    int ca = 1;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) break;
        char s[105];
        memset(memo, 0xff, sizeof(memo));
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; i++)
        {
            scanf("%d %s", &a[i].t, s);
            for (int j = 0; j < n; j++)
                if (s[j] == '+') a[i].must_bug |= 1 << j;
                else if (s[j] == '-') a[i].must_fix |= 1 << j;
            a[i].must_fix = ~a[i].must_fix;
            scanf("%s", s);
            for (int j = 0; j < n; j++)
                if (s[j] == '+') a[i].process_bug |= 1 << j;
                else if (s[j] == '-') a[i].process_fix |= 1 << j;
            a[i].process_fix = ~a[i].process_fix;
        }
        int res = find(0);
        printf("Product %d\n", ca++);
        if (res < 0) printf("Bugs cannot be fixed.\n");
        else printf("Fastest sequence takes %d seconds.\n", res);
        printf("\n");
    }
    return 0;
}
