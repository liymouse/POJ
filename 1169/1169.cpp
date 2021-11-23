#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool operator < (pair<int, int> &x, pair<int, int> &y)
{
    return x.first < y.first;
}

#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define max3(a,b,c) max(a,max(b,c))

int res = -1;
set<pair<int, int> > rect;
int x[4];
int y[4];

void check(int x, int y)
{
    if (res == -1 || (res > 0 && x*y <= res))
    {
        if (x*y != res) 
        {
            res = x*y;
            rect.clear();
        }
        rect.insert(make_pair(min(x, y), max(x, y)));
    }
}

//abcd
void check_type1(int a, int b, int c, int d)
{
    int xx = x[a] + x[b] + x[c] + x[d];
    int yy = max4(y[a], y[b], y[c], y[d]);
    check(xx, yy);
}

//abc
//d
void check_type2(int a, int b, int c, int d)
{
    int xx = max(x[d], x[a] + x[b] + x[c]);
    int yy = y[d] + max3(y[a], y[b], y[c]);
    check(xx, yy);
}

//ab|c
//d |
void check_type3(int a, int b, int c, int d)
{
    int xx = max(x[a] + x[b], x[d]) + x[c];
    int yy = max(max(y[a], y[b]) + y[d], y[c]);
    check(xx, yy);
}
//a|bc
//d|
void check_type4(int a, int b, int c, int d)
{
    int xx = max(x[a], x[d]) + x[b] + x[c];
    int yy = max3(y[a] + y[d], y[b], y[c]);
    check(xx, yy);
}
//ab
//cd
void check_type5(int a, int b, int c, int d)
{
    if (x[c] < x[a] || y[d] < y[c]) return;
    int xx = max(x[a] + x[b], x[c] + x[d]);
    int yy = max(y[a] + y[c], y[b] + y[d]);
    check(xx, yy);
}

int main()
{
    int org[4][2];
    for (int i = 0; i < 4; i++) scanf("%d %d", &org[i][0], &org[i][1]);
    for (int a0 = 0; a0 < 2; a0 ++)
        for (int a1 = 0; a1 < 2; a1 ++)
            for (int a2 = 0; a2 < 2; a2 ++)
                for (int a3 = 0; a3 < 2; a3 ++)
                {
                    x[0] = org[0][a0];
                    y[0] = org[0][1 - a0];
                    x[1] = org[1][a1];
                    y[1] = org[1][1 - a1];
                    x[2] = org[2][a2];
                    y[2] = org[2][1 - a2];
                    x[3] = org[3][a3];
                    y[3] = org[3][1 - a3];
                    int id[4] = { 0, 1, 2, 3 };
                    do
                    {
                        check_type1(id[0], id[1], id[2], id[3]);
                        check_type2(id[0], id[1], id[2], id[3]);
                        check_type3(id[0], id[1], id[2], id[3]);
                        check_type4(id[0], id[1], id[2], id[3]);
                        check_type5(id[0], id[1], id[2], id[3]);
                    } while (next_permutation(id, id + 4));
                }
    printf("%d\n", res);
    for (set<pair<int, int> >::iterator it = rect.begin(); it != rect.end(); it++)
        printf("%d %d\n", it->first, it->second);
    return 0;
}