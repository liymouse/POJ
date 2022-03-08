#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#define N 20
#define M 55
using namespace std;

typedef struct {
    int address;
    int island;
    vector<pair<int, int> > package;
}Host;
typedef struct {
    int id;
    int connect[M];
}Group;

int cmpGroup(Host &x, Host &y)
{
    return x.address < y.address;
}
int cmpPackage(pair<int, int> &x, pair<int, int> &y)
{
    return x.first < y.first;
}

int main()
{
    int ca = 1, n, m;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        
        int line;
        char t[10], name[30];
        vector<pair<int, string> > to[N];
        map<int, int> hid;
        map<string, int> iid;
        int a[N][N];
        Host h[M];
        m = 0;
        memset(a, 0xff, sizeof(a));

        for (int i = 0; i < n; i++)
        {
            a[i][i] = 0;
            scanf("%s %d", name, &line);
            iid[string(name)] = i;
            for (int j = 0; j < line; j++)
            {
                scanf("%s", t);
                if (t[0] == 'T')
                {
                    int ttl;
                    scanf("%d %s", &ttl, name);
                    to[i].push_back(make_pair(ttl, string(name)));
                }
                else //H
                {
                    scanf("%d", &h[m].address);
                    h[m].island = i;
                    hid[h[m].address] = m;
                    m++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < to[i].size(); j++)
            {
                a[i][iid[to[i][j].second]] = to[i][j].first;
            }
        }
        for (int k = 0; k < n; k ++)
            for (int i = 0; i < n; i ++)
                if (i != k)
                    for (int j = 0; j < n; j ++)
                        if (j != k && j != i && a[i][k] >= 0 && a[k][j] >= 0 && 
                            (a[i][j] == -1 || a[i][k] + a[k][j] < a[i][j]))
                        {
                            a[i][j] = a[i][k] + a[k][j];
                        }
        map<int, int> gid;
        vector<Group> g;
        scanf("%d", &line);
        int address, id;
        for (int f = 0; f < line; f++)
        {
            scanf("%s", t);
            if (t[0] == 'J')
            {
                scanf("%d %d", &address, &id);
                if (gid.find(id) == gid.end())
                {
                    gid[id] = g.size();
                    Group x = { 0 };
                    x.id = id;
                    x.connect[hid[address]] = 1;
                    g.push_back(x);
                }
                else
                {
                    g[gid[id]].connect[hid[address]] = 1;
                }
            }
            else if (t[0] == 'L')
            {
                scanf("%d %d", &address, &id);
                id = gid[id];
                g[id].connect[hid[address]] = 0;
            }
            else
            {
                int pid, ttl;
                scanf("%d %d %d %d", &address, &id, &pid, &ttl);
                id = gid[id];
                int x = h[hid[address]].island;
                for (int i = 0; i < m; i++)
                    if (g[id].connect[i])
                    {
                        if (a[x][h[i].island] >= 0 && ttl >= a[x][h[i].island])
                        {
                            h[i].package.push_back(make_pair(pid, ttl - a[x][h[i].island]));
                        }
                    }
            }
        }
        printf("Network #%d\n", ca++);
        sort(h, h + m, cmpGroup);
        for (int i = 0; i < m; i ++)
            if (h[i].package.size() > 0)
            {
                sort(h[i].package.begin(), h[i].package.end(), cmpPackage);
                for (int j = 0; j < h[i].package.size(); j++)
                    printf("%d %d %d\n", h[i].address, h[i].package[j].first, h[i].package[j].second);
            }
        printf("\n");
    }
    return 0;
}
