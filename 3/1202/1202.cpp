#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define N (10)

typedef struct {
    int p0, p1;
    int lv;
}Monster;
typedef struct {
    int zhengshu;
    int L;
    char d[400];
    int set;
}Number; //number = zhengshu.d[0 ~ L-1]

Monster a[305] = { 0 };
Number r[305][305] = { 0 };
int n;

void set(Number *x, int a)
{
    x->set = 1;
    x->zhengshu = a;
    x->L = 0;
    memset(x->d, 0, sizeof(x->d));
}
//c = (a + b) / 2
void cal(Number *c, Number *a, Number *b)
{
    //c = 0
    set(c, 0);
    //c = a + b
    c->zhengshu = a->zhengshu + b->zhengshu;
    for (int i = 0; i < a->L; i++)
        c->d[i] = a->d[i];
    for (int i = 0; i < b->L; i++)
        c->d[i] += b->d[i];
    c->L = max(a->L, b->L);

    // c / 2
    if (c->zhengshu % 2 == 1)
    {
        c->d[0] += 10;
    }
    c->zhengshu /= 2;
    for (int i = 0; i < c->L; i++)
    {
        if (c->d[i] % 2 == 1) c->d[i + 1] += 10;
        c->d[i] /= 2;
    }
    while (c->d[c->L] > 0)
    {
        c->L++;
        if (c->d[c->L - 1] % 2 == 1) c->d[c->L] += 10;
        c->d[c->L-1] /= 2;
    }
    for (int i = c->L-1; i > 0; i --)
        if (c->d[i] > 9)
        {
            c->d[i - 1] += c->d[i] / 10;
            c->d[i] %= 10;
        }
    if (c->d[0] > 9)
    {
        c->zhengshu += c->d[0] / 10;
        c->d[0] %= 10;
    }
    while (c->L > 0 && c->d[c->L - 1] == 0) c->L--;
}
Number* find(int x, int y)
{
    //if relation ship has been calculated
    if (r[x][y].set) return &r[x][y];
    if (x == y) { set(&r[x][y], 100); return &r[x][y]; }
    if (a[x].p0 == 0 && a[y].p0 == 0) { set(&r[x][y], 0); set(&r[y][x], 0); return &r[x][y]; }
    if (a[x].lv >= a[y].lv)
    {
        cal(&r[x][y], find(a[x].p0, y), find(a[x].p1, y));
    }
    else
    {
        cal(&r[x][y], find(x, a[y].p0), find(x, a[y].p1));
    }
    r[y][x] = r[x][y];
    return &r[x][y];
}
void print(Number *x)
{
    printf("%d", x->zhengshu);
    if (x->L != 0)
    {
        printf(".");
        for (int i = 0; i < x->L; i++) printf("%d", x->d[i]);
    }
    printf("%%\n");
}

int main()
{
    int k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int c;
        scanf("%d", &c);
        scanf("%d %d", &a[c].p0, &a[c].p1);
        a[c].lv = max(a[a[c].p0].lv, a[a[c].p1].lv) + 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        print(find(x, y));
    }
    return 0;
}