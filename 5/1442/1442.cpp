#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    int m, n;
    priority_queue<int, vector<int>, greater<int> > small;
    priority_queue<int> big;
    scanf("%d %d", &m, &n);
    int a[30000], u;
    int size = 0, get = 1;
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d", &u);
        while (size < u)
        {
            if (big.size() < get)
            {
                if (small.size() == 0 || a[size] <= small.top())
                {
                    big.push(a[size]);
                }
                else
                {
                    int x = small.top(); small.pop();
                    big.push(x);
                    small.push(a[size]);
                }
            }
            else
            {
                if (a[size] < big.top())
                {
                    int x = big.top(); big.pop();
                    small.push(x);
                    big.push(a[size]);
                }
                else small.push(a[size]);
            }
            size++;
        }
        while (big.size() < get)
        {
            int x = small.top(); small.pop();
            big.push(x);
        }
        printf("%d\n", big.top());
        get++;
    }
    return 0;
}
