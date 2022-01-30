#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace std;
typedef struct {
    int s, id;
}Bus;
int f[600];
int getF(int x)
{
    if (x == f[x]) return x;
    f[x] = getF(f[x]);
    return f[x];
}
int gcd(int x, int y)
{
    while (y)
    {
        int r = x % y;
        x = y; y = r;
    }
    return x;
}
int canMeet(int a, int b, int c, int d)
{
    int t = abs(b - d);
    int k = gcd(a, c);
    if (t % k == 0) return 1;
    else return 0;
}
int main()
{
    int n, d, s;
    while (scanf("%d %d %d", &n, &d, &s) == 3)
    {
        if (n == 0 && d == 0 && s == 0) break;
        vector<int> line[20];
        vector<Bus> dir[20];
        int id = 0;
        char st[1000];
        gets_s(st);
        for (int i = 0; i < n; i++)
        {
            {
                gets_s(st);
                stringstream ss(st);
                int x;
                while (ss >> x)
                {
                    line[i].push_back(x);
                }
            }
            {
                gets_s(st);
                stringstream ss(st);
                int si, di;
                while (ss >> si >> di)
                {
                    Bus b;
                    b.s = si;
                    b.id = id++;
                    dir[i].push_back(b);
                }
            }
        }
        for (int i = 0; i < id; i++) f[i] = i;
        for (int i = 0; i < n; i ++)
            for (int j = i + 1; j < n; j++)
            {
                int has[50] = { 0 };
                for (int k = 0; k < line[i].size(); k++)
                    has[line[i][k]] = 1;
                vector<int> same;
                for (int k = 0; k < line[j].size(); k++)
                    if (has[line[j][k]]) same.push_back(line[j][k]);
                if (same.size() > 0)
                {
                    for (int k = 0; k < same.size(); k++)
                    {
                        vector<int> ri, rj;
                        for (int ii = 0; ii < dir[i].size(); ii++)
                        {
                            int start = 0;
                            for (int x = 0; x < line[i].size(); x++)
                                if (dir[i][ii].s == line[i][x]) { start = x; break; }
                            int num = 0;
                            while (line[i][start] != same[k])
                            {
                                num++;
                                start = (start + 1) % line[i].size();
                            }
                            ri.push_back(num);
                        }
                        for (int ii = 0; ii < dir[j].size(); ii++)
                        {
                            int start = 0;
                            for (int x = 0; x < line[j].size(); x++)
                                if (dir[j][ii].s == line[j][x]) { start = x; break; }
                            int num = 0;
                            while (line[j][start] != same[k])
                            {
                                num++;
                                start = (start + 1) % line[j].size();
                            }
                            rj.push_back(num);
                        }
                        for (int ii = 0; ii < ri.size(); ii++)
                            for (int jj = 0; jj < rj.size(); jj++)
                            {
                                if (canMeet(line[i].size(), ri[ii], line[j].size(), rj[jj]))
                                {
                                    int a = getF(dir[i][ii].id);
                                    int b = getF(dir[j][jj].id);
                                    f[a] = b;
                                }
                            }
                    }
                }
            }
        int t = getF(0);
        int ok = 1;
        for (int i = 1; i < id; i ++)
            if (getF(i) != t) { ok = 0; break; }
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}