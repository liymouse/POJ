#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int x;
        vector<int> a[101];
        int door[101] = { 0 };
        int n = 1;
        int stack[101] = { 1 }, top = 0;
        scanf("%d", &door[1]);
        while (scanf("%d", &x) == 1)
        {
            if (x == 0) break;
            if (x > 0)
            {
                door[stack[top]] --;
                door[++n] = x-1;
                a[stack[top]].push_back(n);
                a[n].push_back(stack[top]);
                if (x > 1) stack[++top] = n;
                else while (door[stack[top]] == 0 && top > 0) top--;
            }
            else
            {
                int id = stack[top+x];
                door[id] --;
                door[stack[top]] --;
                a[id].push_back(stack[top]);
                a[stack[top]].push_back(id);
                while (door[stack[top]] == 0 && top > 0) top--;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d", i);
            sort(a[i].begin(), a[i].end());
            for (int j = 0; j < a[i].size(); j++) printf(" %d", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}