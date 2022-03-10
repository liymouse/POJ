#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[10];
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do
    {
        int c = 1;
        int tot = 0;
        for (int i = 0; i < n; i++)
        {
            tot += a[i] * c;
            c = c * (n - i - 1) / (i + 1);
        }
        if (tot == m) break;
    } while (next_permutation(a, a + n));
    for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
    return 0;
}