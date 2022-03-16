#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct
{
    int type; //0 = move to x, 1 = work x min(load/unload)
    int x;
}Task;
typedef struct
{
    int w, work_time, position, t;
    Task task[1000];
    int head, rear;
}Robot;

Robot r[30] = { 0 };
int n;

void moveToTime(int i, int t)
{
    if (r[i].t >= t) return;
    //if (r[i].task.empty()) { r[i].t = t; return; }
    int org_t = t;
    t = t - r[i].t;
    r[i].t = org_t;
    while (r[i].head != r[i].rear)
    {
        Task &x = r[i].task[r[i].head];
        if (x.type == 0)
        {
            int work_time = (x.x + n - r[i].position) % n;
            if (t >= work_time)
            {
                t -= work_time;
                r[i].work_time += work_time;
                r[i].position = x.x;
                r[i].head++;
            }
            else
            {
                r[i].work_time += t;
                r[i].position = (r[i].position + t) % n;
                x.x -= t;
                break;
            }
        }
        else
        {
            if (t >= x.x)
            {
                t -= x.x;
                r[i].work_time += x.x;
                r[i].head++;
            }
            else
            {
                r[i].work_time += t;
                x.x -= t;
                break;
            }
        }
    }
}
void addTask(int i, int src, int dst, int t)
{
    if (r[i].t < t) r[i].t = t;
    //move to src
    r[i].task[r[i].rear].type = 0; r[i].task[r[i].rear].x = src; r[i].rear++;
    r[i].task[r[i].rear].type = 1; r[i].task[r[i].rear].x = 5; r[i].rear++;
    r[i].task[r[i].rear].type = 0; r[i].task[r[i].rear].x = dst; r[i].rear++;
    r[i].task[r[i].rear].type = 1; r[i].task[r[i].rear].x = 5; r[i].rear++;
}
void finishTask(int i)
{
    while (r[i].head != r[i].rear)
    {
        Task &x = r[i].task[r[i].head];
        if (x.type == 0)
        {
            int work_time = (x.x + n - r[i].position) % n;
            r[i].t += work_time;
            r[i].work_time += work_time;
            r[i].position = x.x;
            r[i].head++;
        }
        else
        {
            r[i].t += x.x;
            r[i].work_time += x.x;
            r[i].head++;
        }
    }
}
int main()
{
    int m, ca = 1;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) break;
        memset(r, 0, sizeof(r));
        for (int i = 0; i < m; i++) scanf("%d", &r[i].w);
        int t, src, dst, w, t0 = -1;
        int tot_time = 0;
        int tot_wait_time = 0;
        int num = 0;
        while (scanf("%d %d %d %d", &t, &src, &dst, &w) == 4)
        {
            if (t == -1 && src == -1 && dst == -1 && w == -1) break;
            src--; dst--; num++;
            if (t0 == -1) t0 = t;

            for (int i = 0; i < m; i++)
                moveToTime(i, t);
            int choose = -1;
            int mind = 200;
            for (int i = 0; i < m; i++)
                if (r[i].w >= w) //can carry
                {
                    int dist = (src + n - r[i].position) % n;
                    if (dist < mind)
                    {
                        mind = dist;
                        choose = i;
                    }
                }
            addTask(choose, src, dst, t);
        }
        for (int i = 0; i < m; i++)
        {
            finishTask(i);
            tot_time = max(tot_time, r[i].t);
        }
        tot_time -= t0;
        double avg_utilization = 0.0;
        for (int i = 0; i < m; i++)
        {
            avg_utilization += r[i].work_time * 100.0 / tot_time;
        }

        printf("Simulation %d\n", ca++);
        printf("Average wait time   = %.3lf minutes\n", (double)tot_wait_time / num);
        printf("Average utilization = %.3lf %%\n", avg_utilization / m);
        printf("\n");
    }
    return 0;
}
#else
#include <stdio.h>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct
{
    int w, next, work_time, position;
}Robot;

int main()
{
    int n, m, ca = 1;
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0) break;
        Robot r[30] = { 0 };
        for (int i = 0; i < m; i++) scanf("%d", &r[i].w);
        int t, src, dst, w, t0 = -1;
        int tot_time = 0;
        int tot_wait_time = 0;
        int num = 0;
        while (scanf("%d %d %d %d", &t, &src, &dst, &w) == 4)
        {
            if (t == -1 && src == -1 && dst == -1 && w == -1) break;
            src--; dst--; num++;
            if (t0 == -1) t0 = t;
            int choose = -1;
            int start_time = 1 << 30;
            int mind = 200;
            for (int i = 0; i < m; i ++)
                if (r[i].w >= w) //can carry
                {
                    //earliest
                    int st = max(r[i].next, t);
                    if (st <= start_time)
                    {
                        start_time = st;
                        int dist = (src + n - r[i].position) % n;
                        if (dist < mind)
                        {
                            mind = dist;
                            choose = i;
                        }
                    }
                }
            int work_time = 10 + mind + (dst + n - src) % n;
            r[choose].work_time += work_time;
            r[choose].next = start_time + work_time;
            r[choose].position = dst;
            tot_wait_time += r[choose].next - t;
        }
        for (int i = 0; i < m; i ++) tot_time = max(tot_time, r[i].next);
        tot_time -= t0;
        double avg_utilization = 0.0;
        for (int i = 0; i < m; i++)
        {
            avg_utilization += r[i].work_time * 100.0 / tot_time;
        }

        printf("Simulation %d\n", ca++);
        if (num > 0) printf("Average wait time   = %.3lf minutes\n", (double)tot_wait_time / num);
        else printf("Average wait time   = %.3lf minutes\n", 0.0);
        if (m > 0) printf("Average utilization = %.3lf %%\n", avg_utilization / m);
        else printf("Average utilization = %.3lf %%\n", 0.0);
        printf("\n");
    }
    return 0;
}
#endif