#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef struct
{
    int a, b, no;
}node;
int cmp(node &x, node &y)
{
    if (x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}

int main()
{
    int n;
    node a[50001];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > qu;
    int no[50001];
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &a[i].a, &a[i].b);
            a[i].no = i;
        }
        sort(a, a + n, cmp);
        int k = 1;
        for (int i = 0; i < n; i++)
        {
            if (!qu.empty() && qu.top().first < a[i].a)
            {
                pair<int, int> sp = qu.top();
                qu.pop();
                sp.first = a[i].b;
                no[a[i].no] = sp.second;
                qu.push(sp);
            }
            else
            {
                pair<int, int> sp;
                sp.first = a[i].b;
                sp.second = k;
                no[a[i].no] = k++;
                qu.push(sp);
            }
        }
        printf("%d\n", qu.size());
        for (int i = 0; i < n; i++) printf("%d\n", no[i]);
    }
    return 0;
}