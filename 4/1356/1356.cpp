#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int n, r;
        scanf("%d %d", &n, &r);
        int x[101], y[101];
        vector<int> sx, sy;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &x[i], &y[i]);
            sx.push_back(x[i]);
            sy.push_back(y[i]);
        }
        int res = 0;
        for (int a = 0; a < sx.size(); a ++)
            for (int b = 0; b < sy.size(); b ++)
            {
                int sum = 0;
                for (int j = 0; j < n; j++)
                    if (sx[a] <= x[j] && x[j] <= sx[a] + r && sy[b] <= y[j] && y[j] <= sy[b] + r) sum++;
                if (sum > res) res = sum;
            }
        printf("%d\n", res);
    }
    return 0;
}