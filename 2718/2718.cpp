#include <stdio.h>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int cas;
    char str[100];
    scanf("%d", &cas); gets_s(str);
    while (cas--)
    {
        gets_s(str);
        int a[10], t;
        int n = 0;
        int res = 1<<30;
        stringstream ss;
        ss.str(string(str));
        while (ss >> a[n]) n++;
        sort(a, a + n);
        int L = n / 2;
        do
        {
            int x = 0, y = 0;
            if ((L > 1 && a[0] == 0) || (n - L > 1 && a[L] == 0)) continue;
            for (int i = 0; i < L; i++) x = x * 10 + a[i];
            for (int i = L; i < n; i++) y = y * 10 + a[i];
            res = min(res, abs(x - y));
        } while (next_permutation(a, a + n));
        printf("%d\n", res);
    }
}