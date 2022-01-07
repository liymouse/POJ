#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100000
char p[N] = { 1, 1, };
vector<int> a[10]; //a[0] = prime can be set in 1st row, 1 line
typedef struct {
    int a[5];
}Cube;
Cube res[1000];
int res_num = 0;

int cmp(Cube &a, Cube &b)
{
    if (a.a[0] == b.a[0])
    {
        if (a.a[1] == b.a[1])
        {
            if (a.a[2] == b.a[2])
            {
                if (a.a[3] == b.a[3])
                {
                    return a.a[4] < b.a[4];
                }
                else return a.a[3] < b.a[3];
            }
            else return a.a[2] < b.a[2];
        }
        else return a.a[1] < b.a[1];
    }
    else return a.a[0] < b.a[0];
}
int get(int x, int d)
{
    if (d == 0) return x / 10000;
    if (d == 1) return (x / 1000) % 10;
    if (d == 2) return (x / 100) % 10;
    if (d == 3) return (x / 10) % 10;
    return x % 10;
}

int check(vector<int> &x, int &size, int d, int value)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (get(x[i], d) != value)
        {
            int t = x[i]; x[i] = x[size - 1]; x[size - 1] = t;
            size--;
        }
    }
    return size;
}
int crosscheck(vector<int> &x, int &size, int r, vector<int> c[5], int nc[5], vector<int> d[2], int nd[2])
{
    int b[5][10] = { 0 };
    for (int k = 1; k < 5; k++)
    {
        for (int i = 0; i < nc[k]; i++) b[k][get(c[k][i], r)] = 1;
    }
    for (int i = 0; i < nd[0]; i++) b[r][get(d[0][i], r)] = 1;
    for (int i = 0; i < nd[1]; i++) b[4-r][get(d[1][i], 4-r)] = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 1; j < 5; j++)
            if (b[j][get(x[i], j)] == 0)
            { 
                int t = x[i]; x[i] = x[size - 1]; x[size - 1] = t;
                size--;
                break;
            }
    }
    return size;
}
int combine(int a0, int a1, int a2, int a3, int a4)
{
    return a0 * 10000 + a1 * 1000 + a2 * 100 + a3 * 10 + a4;
}
void find()
{
    for (int i = 0; i < a[0].size(); i++)
    {
        int a0 = a[0][i];
        vector<int> c[5] = { a[0], a[get(a0, 1)], a[get(a0,2)], a[get(a0,3)], a[get(a0,4)] };
        int nc[5] = { 0 };
        for (int k = 0; k < 5; k++) nc[k] = c[k].size();
        vector<int> d[2] = { a[get(a0, 0)] };
        int nd[2] = { 0 };
        nd[0] = d[0].size();
        for (int j = i; j < nc[0]; j++)
        {
            d[1] = a[get(c[0][j], 4)];
            nd[1] = d[1].size();
            vector<int> r[5] = { a[0], a[get(c[0][j], 1)], a[get(c[0][j], 2)], a[get(c[0][j], 3)], a[get(c[0][j], 4)] };
            int nr[5] = { 0 };
            for (int k = 0; k < 5; k++) nr[k] = r[k].size();

            if (check(d[1], nd[1], 4, get(a0, 4)) == 0 ||
                crosscheck(r[1], nr[1], 1, c, nc, d, nd) == 0 ||
                crosscheck(r[2], nr[2], 2, c, nc, d, nd) == 0 ||
                crosscheck(r[3], nr[3], 3, c, nc, d, nd) == 0 ||
                crosscheck(r[4], nr[4], 4, c, nc, d, nd) == 0) continue;
            for (int t1 = 0; t1 < nr[1]; t1++)
            {
                int a1 = r[1][t1];
                int nc1[5] = { nc[0], nc[1], nc[2], nc[3], nc[4] };
                int nr1[5] = { nr[0], nr[1], nr[2], nr[3], nr[4] };
                int nd1[2] = { nd[0], nd[1] };
                if (check(c[1], nc1[1], 1, get(a1, 1)) == 0 ||
                    check(c[2], nc1[2], 1, get(a1, 2)) == 0 ||
                    check(c[3], nc1[3], 1, get(a1, 3)) == 0 ||
                    check(c[4], nc1[4], 1, get(a1, 4)) == 0 ||
                    check(d[0], nd1[0], 1, get(a1, 1)) == 0 ||
                    check(d[1], nd1[1], 3, get(a1, 3)) == 0 ||
                    crosscheck(r[2], nr1[2], 2, c, nc1, d, nd1) == 0 ||
                    crosscheck(r[3], nr1[3], 3, c, nc1, d, nd1) == 0 ||
                    crosscheck(r[4], nr1[4], 4, c, nc1, d, nd1) == 0) continue;

                for (int t2 = 0; t2 < nr1[2]; t2++)
                {
                    int a2 = r[2][t2];
                    int nc2[5] = { nc1[0], nc1[1], nc1[2], nc1[3], nc1[4] };
                    int nr2[5] = { nr1[0], nr1[1], nr1[2], nr1[3], nr1[4] };
                    int nd2[2] = { nd1[0], nd1[1] };
                    if (check(c[1], nc2[1], 2, get(a2, 1)) == 0 ||
                        check(c[2], nc2[2], 2, get(a2, 2)) == 0 ||
                        check(c[3], nc2[3], 2, get(a2, 3)) == 0 ||
                        check(c[4], nc2[4], 2, get(a2, 4)) == 0 ||
                        check(d[0], nd2[0], 2, get(a2, 2)) == 0 ||
                        check(d[1], nd2[1], 2, get(a2, 2)) == 0 ||
                        crosscheck(r[3], nr2[3], 3, c, nc2, d, nd2) == 0 ||
                        crosscheck(r[4], nr2[4], 4, c, nc2, d, nd2) == 0) continue;

                    for (int t3 = 0; t3 < nr2[3]; t3++)
                    {
                        int a3 = r[3][t3];
                        int nc3[5] = { nc2[0], nc2[1], nc2[2], nc2[3], nc2[4] };
                        int nr3[5] = { nr2[0], nr2[1], nr2[2], nr2[3], nr2[4] };
                        int nd3[2] = { nd2[0], nd2[1] };
                        if (check(c[1], nc3[1], 3, get(a3, 1)) == 0 ||
                            check(c[2], nc3[2], 3, get(a3, 2)) == 0 ||
                            check(c[3], nc3[3], 3, get(a3, 3)) == 0 ||
                            check(c[4], nc3[4], 3, get(a3, 4)) == 0 ||
                            check(d[0], nd3[0], 3, get(a3, 3)) == 0 ||
                            check(d[1], nd3[1], 1, get(a3, 1)) == 0 ||
                            crosscheck(r[4], nr3[4], 4, c, nc3, d, nd3) == 0) continue;

                        for (int t4 = 0; t4 < nr3[4]; t4++)
                        {
                            int a4 = r[4][t4];
                            int nc4[5] = { nc3[0], nc3[1], nc3[2], nc3[3], nc3[4] };
                            int nd4[2] = { nd3[0], nd3[1] };
                            if (check(c[1], nc4[1], 4, get(a4, 1)) == 0 ||
                                check(c[2], nc4[2], 4, get(a4, 2)) == 0 ||
                                check(c[3], nc4[3], 4, get(a4, 3)) == 0 ||
                                check(c[4], nc4[4], 4, get(a4, 4)) == 0 ||
                                check(d[0], nd4[0], 4, get(a4, 4)) == 0) continue;
                            //OK
                            res[res_num].a[0] = a0;
                            res[res_num].a[1] = a1;
                            res[res_num].a[2] = a2;
                            res[res_num].a[3] = a3;
                            res[res_num].a[4] = a4;
                            res_num++;
                            if (i != j) //save trans
                            {
                                res[res_num].a[0] = a[0][j];
                                res[res_num].a[1] = combine(get(a0, 1), get(a1, 1), get(a2, 1), get(a3, 1), get(a4, 1));
                                res[res_num].a[2] = combine(get(a0, 2), get(a1, 2), get(a2, 2), get(a3, 2), get(a4, 2));
                                res[res_num].a[3] = combine(get(a0, 3), get(a1, 3), get(a2, 3), get(a3, 3), get(a4, 3));
                                res[res_num].a[4] = combine(get(a0, 4), get(a1, 4), get(a2, 4), get(a3, 4), get(a4, 4));
                                res_num++;
                            }
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    for (int i = 2; i*i < N; i++)
    {
        for (int k = i + i; k < N; k += i) p[k] = 1;
    }
    int sum, first;
    scanf("%d %d", &sum, &first);
    //freopen("output.txt", "w", stdout);
    //for (sum = 5; sum <= 45; sum++)
    //for (first = 1; first <= 9; first++)
    {
        res_num = 0;
        for (int k = 1; k < 10; k++)
        {
            a[k].clear();
            for (int i = k * 10000; i < (k + 1) * 10000; i++)
                if (p[i] == 0)
                {
                    int t = i;
                    int s = 0;
                    while (t) { s += t % 10; t /= 10; }
                    if (s == sum) a[k].push_back(i);
                }
        }
        a[0].clear();
        for (int i = 0; i < a[first].size(); i++)
        {
            int t = a[first][i];
            int haszero = 0;
            while (t) { if (t % 10 == 0) haszero = 1; t /= 10; }
            if (haszero == 0) a[0].push_back(a[first][i]);
        }
        find();
        if (res_num > 0)
        {
#if 0
            printf("(%d %d) num = %d\n", sum, first, res_num);
#else
            sort(res, res + res_num, cmp);
            for (int i = 0; i < res_num; i++)
            {
                for (int j = 0; j < 5; j++) printf("%d\n", res[i].a[j]);
                printf("\n");
            }
#endif
        }
    }
    return 0;
}