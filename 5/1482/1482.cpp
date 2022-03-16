#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef struct {
    int must_bug, must_fix;
    int process_bug, process_fix;
    int t;
}Patch;
int memo[1 << 20];
char has[1 << 20];
Patch a[100];
int n, m;

int main()
{
    int ca = 1;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) break;
        char s[105];
        memset(memo, 0xff, sizeof(memo));
        memset(a, 0, sizeof(a));
        memset(has, 0, sizeof(has));
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

        queue<int> q;
        int s0 = (1 << n) - 1;
        q.push(s0);
        memo[s0] = 0;
        while (!q.empty())
        {
            s0 = q.front();
            q.pop();
            has[s0] = 0;
            for (int i = 0; i < m; i++)
                if ((s0 & a[i].must_bug) == a[i].must_bug &&
                    (s0 | a[i].must_fix) == a[i].must_fix) //can use patch i
                {
                    int s1 = s0 & (a[i].process_bug ^ a[i].process_fix); //0 keep same as s
                    s1 |= a[i].process_bug; //set +
                    s1 &= a[i].process_fix; //set -
                    if (memo[s1] == -1 || memo[s0] + a[i].t < memo[s1])
                    {
                        memo[s1] = memo[s0] + a[i].t;
                        if (!has[s1])
                        {
                            has[s1] = 1;
                            q.push(s1);
                        }
                    }
                }
        }

        int res = memo[0];
        printf("Product %d\n", ca++);
        if (res < 0) printf("Bugs cannot be fixed.\n");
        else printf("Fastest sequence takes %d seconds.\n", res);
        printf("\n");
    }
    return 0;
}
