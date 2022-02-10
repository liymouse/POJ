#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

typedef struct {
    char dealers[11];
    int com;
    int type;
    int cost;
}Record;

typedef struct {
    int maxv, minv, totv, num;
}Com;

typedef struct {
    int cost[3];
}Dealers;
int main()
{
    int n;
    //freopen("MARKET.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        Record a[1000] = { 0 };
        Com c[26] = { 0 };
        int finish[1000] = { 0 };
        map<string, Dealers> d;
        for (int i = 0; i < 26; i++) c[i].minv = 2000;
        for (int i = 0; i < n; i++)
        {
            char type[6], name[3];
            scanf("%s %s %s %d", a[i].dealers, type, name, &a[i].cost);
            a[i].type = (type[0] == 'S') ? -1 : 1;
            a[i].com = name[0] - 'A';
            if (d.find(string(a[i].dealers)) == d.end())
            {
                Dealers x;
                x.cost[0] = x.cost[1] = x.cost[2] = 0;
                d[string(a[i].dealers)] = x;
            }
            int k = -1;
            int maxv = -1;
            for (int j = 0; j < i; j ++)
                if (!finish[j] && a[i].com == a[j].com &&
                    strcmp(a[i].dealers, a[j].dealers) != 0 &&
                    a[i].type + a[j].type == 0 &&
                    a[i].cost * a[i].type + a[j].cost * a[j].type > maxv)
                {
                    maxv = a[i].cost * a[i].type + a[j].cost * a[j].type;
                    k = j;
                }
            if (k != -1)
            {
                finish[k] = finish[i] = 1;
                int v = (a[i].cost + a[k].cost) / 2;
                d[string(a[i].dealers)].cost[a[i].type + 1] += v;
                d[string(a[k].dealers)].cost[a[k].type + 1] += v;
                c[a[i].com].totv += v;
                c[a[i].com].num++;
                c[a[i].com].maxv = max(c[a[i].com].maxv, v);
                c[a[i].com].minv = min(c[a[i].com].minv, v);
            }
        }
        for (int i = 0; i < 26; i++)
            if (c[i].num)
            {
                printf("%c %d %d %d\n", 'A' + i, c[i].minv, c[i].totv / c[i].num, c[i].maxv);
            }
        printf("--\n");
        for (map<string, Dealers>::iterator it = d.begin(); it != d.end(); it++)
        {
            printf("%s %d %d\n", (it->first).c_str(), (it->second).cost[2], (it->second).cost[0]);
        }
        printf("----------\n");
    }
    return 0;
}
