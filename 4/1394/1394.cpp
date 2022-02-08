#include <stdio.h>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef struct
{
    int to;
    int st, et;
}Train;
int main()
{
    //freopen("railroad.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int c, ca = 1;
    while (scanf("%d", &c) == 1)
    {
        if (c == 0) break;
        char str[1000];
        gets_s(str);
        map<string, int> id;
        int index = 0;
        for (int i = 0; i < c; i++)
        {
            gets_s(str);
            if (id.find(string(str)) == id.end())
            {
                id[string(str)] = index++;
            }
        }
        int t;
        scanf("%d", &t);
        vector<Train> a[105] , b[105];
        for (int i = 0; i < t; i++)
        {
            int ti;
            scanf("%d", &ti);
            gets_s(str);
            gets_s(str);
            int pre_t = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + str[3] - '0';
            int pre_id = id[string(str + 5)];
            for (int j = 1; j < ti; j++)
            {
                gets_s(str);
                int cur_t = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + str[3] - '0';
                int cur_id = id[string(str + 5)];
                Train x;
                x.to = cur_id;
                x.st = pre_t;
                x.et = cur_t;
                a[pre_id].push_back(x);

                x.to = pre_id;
                b[cur_id].push_back(x);
                pre_t = cur_t;
                pre_id = cur_id;
            }
        }
        int st, si, ei;
        char s_station[1000], e_station[1000];
        scanf("%d", &st);
        gets_s(str);
        gets_s(s_station);
        si = id[string(s_station)];
        gets_s(e_station);
        ei = id[string(e_station)];
        int reach[105];
        int mark[105] = { 0 };
        for (int i = 0; i < c; i++) reach[i] = 10000;
        reach[si] = st;
        mark[si] = 1;
        for (int i = 0; i < a[si].size(); i++)
            if (st <= a[si][i].st && a[si][i].et < reach[a[si][i].to])
                reach[a[si][i].to] = a[si][i].et;
        for (int i = 0; i < c; i++)
        {
            int mint = 10000;
            int k = -1;
            for (int j = 0; j < c; j ++)
                if (mark[j] == 0 && reach[j] < mint)
                {
                    mint = reach[j];
                    k = j;
                }
            if (k == -1 || k == ei) break;
            mark[k] = 1;
            for (int j = 0; j < a[k].size(); j ++)
                if (mark[a[k][j].to] == 0 && reach[k] <= a[k][j].st &&
                    a[k][j].et < reach[a[k][j].to])
                {
                    reach[a[k][j].to] = a[k][j].et;
                }
        }
        printf("Scenario #%d\n", ca++);
        if (reach[ei] == 10000) //no solution
        {
            printf("No connection\n");
        }
        else
        {
            //find lastest start time
            int start[105];
            memset(start, 0xff, sizeof(start));
            memset(mark, 0, sizeof(mark));
            start[ei] = reach[ei];
            mark[ei] = 1;
            for (int i = 0; i < b[ei].size(); i++)
                if (reach[ei] == b[ei][i].et && b[ei][i].st > start[b[ei][i].to])
                    start[b[ei][i].to] = b[ei][i].st;
            for (int i = 0; i < c; i++)
            {
                int maxt = -1;
                int k = -1;
                for (int j = 0; j < c; j++)
                    if (mark[j] == 0 && start[j] > maxt)
                    {
                        maxt = start[j];
                        k = j;
                    }
                if (k == -1 || k == si) break;
                mark[k] = 1;
                for (int j = 0; j < b[k].size(); j++)
                    if (mark[b[k][j].to] == 0 && start[k] >= b[k][j].et &&
                        b[k][j].st > start[b[k][j].to])
                    {
                        start[b[k][j].to] = b[k][j].st;
                    }
            }
            //get path
            printf("Departure %04d %s\n", start[si], s_station);
            printf("Arrival   %04d %s\n", reach[ei], e_station);
        }
        printf("\n");
    }
    return 0;
}