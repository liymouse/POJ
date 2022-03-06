#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 5000
char s[5000];
int f[5000];

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2)
    {
        int a[10] = { 0 };
        int q[5000], top = 0, rear = 0;
        int has_even = 0;
        int b[10] = { 0 };
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a[i]);
            b[a[i]] = 1;
            if (a[i] % 2 == 0) has_even = 1;
        }
        if (n % 2 == 0 && has_even == 0) { printf("0\n"); continue; }
        if (n % 10 == 5 && b[0] == 0 && b[5] == 0) { printf("0\n"); continue; }
        if (n % 10 == 0 && b[0] == 0) { printf("0\n"); continue; }
        if (n == 0) { printf("0\n"); continue; }
        sort(a, a + m);
        int found = 0;
        memset(s, 0xff, sizeof(s));
        for (int i = 0; i < m; i ++)
            if (a[i])
            {
                int k = a[i] % n;
                if (s[k] == -1)
                {
                    s[k] = a[i]; f[k] = -1;
                    if (k == 0) { found = 1; goto L_exit; }
                    q[rear++] = k;
                }
            }
        while (rear != top)
        {
            int x = q[top];
            top++; if (top >= N) top = 0;
            for (int i = 0; i < m; i ++)
            {
                int k = (x * 10 + a[i]) % n;
                if (s[k] == -1)
                {
                    s[k] = a[i]; f[k] = x;
                    if (k == 0) { found = 1; goto L_exit; }
                    q[rear] = k;
                    rear++; if (rear >= N) rear = 0;
                }
            }
        }
    L_exit:
        if (found)
        {
            char res[5000] = { 0 };
            int L = 0;
            int x = 0;
            while (x != -1)
            {
                res[L++] = s[x];
                x = f[x];
            }
            for (int i = L - 1; i >= 0; i--) printf("%d", res[i]);
            printf("\n");
        }
        else printf("0\n");
    }
    return 0;
}
