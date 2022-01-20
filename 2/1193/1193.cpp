#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _Node {
    int use;
    int s, t;
    struct _Node *next;
}Node;
typedef struct {
    int ts, tL;
    int type; //0 = malloc, 1 = free
    int ms, mL;
    int id;
}Schedual;
Schedual sche[12000];
int scheN, global_id;
int cmp(int x, int y)
{
    if (sche[x].ts == sche[y].ts)
    {
        if (sche[x].type == 0 && sche[y].type == 0) return sche[x].id < sche[y].id;
        return sche[x].type > sche[y].type;
    }
    return sche[x].ts < sche[y].ts;
}
void heapPop()
{
    sche[0] = sche[scheN - 1];
    scheN--;
    int k = 0;
    while (k * 2 + 1 < scheN)
    {
        int j = k * 2 + 1;
        if (j + 1 < scheN && cmp(j + 1, j)) j++;
        if (cmp(k, j)) break;
        Schedual tmp = sche[k]; sche[k] = sche[j]; sche[j] = tmp;
        k = j;
    }
}
void heapShiftUp(int x)
{
    while (x > 0 && cmp(x, (x - 1) / 2))
    {
        Schedual tmp;
        tmp = sche[x]; sche[x] = sche[(x - 1) / 2]; sche[(x - 1) / 2] = tmp;
        x = (x - 1) / 2;
    }
}
int canAdd(Node *mem, Schedual *a)
{
    Node *q = mem->next;
    while (q != NULL)
    {
        if (q->use == 0 && q->t - q->s + 1 >= a->mL) return 1;
        q = q->next;
    }
    return 0;
}
void addMem(Node *mem, Schedual *a)
{
    Node *q = mem->next;
    while (q != NULL)
    {
        if (q->use == 0 && q->t - q->s + 1 >= a->mL)
        {
            if (q->t - q->s + 1 == a->mL) q->use = 1;
            else
            {
                Node *t = (Node*)malloc(sizeof(Node));
                t->s = q->s + a->mL;
                t->t = q->t;
                t->use = 0;
                t->next = q->next;
                q->next = t;
                q->t = q->s + a->mL - 1;
                q->use = 1;
            }
            sche[scheN].type = 1;
            sche[scheN].ms = q->s;
            sche[scheN].ts = a->ts + a->tL;
            sche[scheN].id = global_id ++;
            scheN++;
            heapShiftUp(scheN - 1);
            break;
        }
        q = q->next;
    }
}
void freeMem(Node *mem, Schedual *a)
{
    Node *p = mem;
    while (p->next)
    {
        if (p->next->s == a->ms)
        {
            p->next->use = 0; break;
        }
        p = p->next;
    }
    Node *q = p->next;
    Node *r = q->next;
    if (r != NULL && r->use == 0)
    {
        q->t = r->t;
        q->next = r->next;
        free(r);
    }
    if (p->use == 0)
    {
        p->t = q->t;
        p->next = q->next;
        free(q);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    Node mem;
    mem.next = (Node*)malloc(sizeof(Node));
    mem.next->s = 0;
    mem.next->t = n - 1;
    mem.next->use = 0;
    mem.next->next = NULL;
    int t, m, p;
    int resNum = 0;
    int maxTime = 0;
    scheN = 0;
    global_id = 0;
    while (scanf("%d %d %d", &t, &m, &p) == 3)
    {
        if (t == 0 && m == 0 && p == 0) break;
        sche[scheN].id = global_id++;
        sche[scheN].ts = t;
        sche[scheN].tL = p;
        sche[scheN].ms = -1;
        sche[scheN].mL = m;
        sche[scheN].type = 0;
        scheN++;
    }
    queue<Schedual> qu;
    int last_del = 0;
    int last_time = 0;
    while (scheN > 0 || !qu.empty())
    {
        if (scheN > 0 && sche[0].type == 1 && 
            (last_del == 0 || (last_del == 1 && sche[0].ts == last_time)))
        {
            freeMem(&mem, &sche[0]);
            last_del = 1;
            last_time = sche[0].ts;
        }
        else
        {
            if (last_del)
            {
                while (!qu.empty())
                {
                    Schedual a = qu.front();
                    if (canAdd(&mem, &a))
                    {
                        a.ts = last_time;
                        addMem(&mem, &a);
                        qu.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (sche[0].type == 0)
            {
                last_del = 0;
                if (canAdd(&mem, &sche[0])) addMem(&mem, &sche[0]);
                else
                {
                    qu.push(sche[0]);
                    resNum++;
                }
            }
            else
            {
                freeMem(&mem, &sche[0]);
                last_del = 1;
                last_time = sche[0].ts;
            }
        }
        if (sche[0].ts > maxTime) maxTime = sche[0].ts;
        heapPop();
    }
    printf("%d\n%d\n", maxTime, resNum);
    {
        Node *p = mem.next;
        while (p)
        {
            Node *q = p;
            p = p->next;
            free(q);
        }
    }
    return 0;
}