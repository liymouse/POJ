#include <stdio.h>
#include <queue>
using namespace std;

typedef struct _Node {
    int use;
    int s, t;
    struct _Node *next;
}Node;
typedef struct _Schedual {
    int ts, tL;
    int type; //0 = malloc, 1 = free
    int ms, mL;
    struct _Schedual *next;
}Schedual;

void addSchedual(Schedual *sche, Schedual *a)
{
    Schedual *p = sche;
    while (p != NULL)
    {
        if (a->type == 1 && p->ts < a->ts && (p->next == NULL || p->next->ts >= a->ts))
        {
            Schedual *q = (Schedual *)malloc(sizeof(Schedual));
            *q = *a;
            q->next = p->next;
            p->next = q;
            break;
        }
        else if (a->type == 0 && p->ts <= a->ts && (p->next == NULL || p->next->ts > a->ts))
        {
            Schedual *q = (Schedual *)malloc(sizeof(Schedual));
            *q = *a;
            q->next = p->next;
            p->next = q;
            break;
        }
        p = p->next;
    }
}
void removeSchedual(Schedual *sche, Schedual *a)
{
    Schedual *p = sche;
    while (p != NULL)
    {
        if (p->next == a)
        {
            p->next = a->next;
            break;
        }
        p = p->next;
    }
    free(a);
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
void addMem(Node *mem, Schedual *sche, Schedual *a)
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
            Schedual sche_f;
            sche_f.type = 1;
            sche_f.ms = q->s;
            sche_f.ts = a->ts + a->tL;
            addSchedual(sche, &sche_f);
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
#if 0
    p = mem->next;
    Node *q = p->next;
    while (p != NULL && q != NULL)
    {
        if (p->use == 0 && q->use == 0)
        {
            p->t = q->t;
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else { p = q; q = q->next; }
    }
#else
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
#endif
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
    Schedual sche;
    sche.ts = -1;
    sche.next = NULL;
    int resNum = 0;
    int maxTime = 0;
    while (scanf("%d %d %d", &t, &m, &p) == 3)
    {
        if (t == 0 && m == 0 && p == 0) break;
        Schedual a;
        a.ts = t;
        a.tL = p;
        a.ms = -1;
        a.mL = m;
        a.type = 0;
        a.next = NULL;
        addSchedual(&sche, &a);
    }
    queue<Schedual> qu;
    while (sche.next != NULL)
    {
        Schedual *e = sche.next;
        int curT = e->ts;
        if (e->type == 1)
        {
            freeMem(&mem, e);
            if (!(e->next != NULL && e->ts == e->next->ts && e->next->type == 1))
            {
                while (!qu.empty())
                {
                    Schedual a = qu.front();
                    if (canAdd(&mem, &a))
                    {
                        a.ts = curT;
                        addMem(&mem, &sche, &a);
                        qu.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        else if (e->type == 0)
        {
            if (canAdd(&mem, e)) {
                addMem(&mem, &sche, e);
            }
            else
            {
                qu.push(*e);
                resNum++;
            }
        }
        if (e->ts > maxTime) maxTime = e->ts;
        removeSchedual(&sche, e);
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