#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct {
    char name[100], position[100];
    int vote[11];
    int point;
    int id;
}Teacher;

int cmp(Teacher &x, Teacher &y)
{
    if (x.point == y.point)
    {
        if (x.vote[10] == y.vote[10]) return x.id < y.id;
        return x.vote[10] > y.vote[10];
    }
    return x.point > y.point;
}
int main()
{
    int n, m;
    Teacher t[102];
    while (scanf("%d %d", &n, &m) == 2)
    {
        memset(t, 0, sizeof(t));
        for (int i = 0; i < 100; i++) t[i].id = 999;
        for (int i = 0; i < n; i++)
        {
            int id;
            scanf("%d", &id);
            t[id].id = id;
            scanf("%s %s", t[id].name, t[id].position);
        }
        for (int i = 0; i < m; i++)
        {
            char s[100];
            scanf("%s", s);
            int has[102] = { 0 };
            int ok = 1;
            for (int k = 0; k < 20; k += 2)
            {
                int id = (s[k] - '0') * 10 + (s[k + 1] - '0');
                if (id == 0) continue;
                if (t[id].id == id && has[id] == 0)
                {
                    has[id] = 1;
                }
                else ok = 0;
            }
            if (ok)
            {
                for (int k = 0; k < 20; k += 2)
                {
                    int id = (s[k] - '0') * 10 + (s[k + 1] - '0');
                    if (id != 0)
                    {
                        t[id].vote[k / 2] ++;
                        t[id].vote[10] ++;
                    }
                }
            }
        }
        int sc[10] = { 15,12,9,7,6,5,4,3,2,1 };
        for (int i = 1; i < 100; i ++)
            if (t[i].id != 999)
            {
                t[i].point = 0;
                for (int j = 0; j < 10; j++)
                    t[i].point += sc[j] * t[i].vote[j];
            }
        sort(t+1, t + 101, cmp);
        for (int i = 1; i <= min(10, n); i++)
            if (t[i].id != 999)
            {
                printf("%-2d  %02d  %-15s%-37s%6d%6d", i, t[i].id, t[i].name, t[i].position, t[i].point, t[i].vote[10]);
                for (int j = 0; j < 10; j++)
                    printf("%6d", t[i].vote[j]);
                printf("\n");
            }
    }
    return 0;
}