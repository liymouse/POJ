#include <stdio.h>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
typedef struct {
    int state;
    vector<string> step;
}Step;

int main()
{
    int r, d, s;
    int ca = 1;
    while (scanf("%d %d %d", &r, &d, &s) == 3)
    {
        if (r == 0 && d == 0 && s == 0) break;
        int a[11][11] = { 0 };
        char check[10240] = { 0 };
        vector<int> sw[11];
        for (int i = 0; i < d; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            a[x - 1][y - 1] = a[y - 1][x - 1] = 1;
        }
        for (int i = 0; i < s; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            sw[x - 1].push_back(y - 1);
        }
        for (int i = 0; i < r; i ++)
            if (sw[i].size() > 1) sort(sw[i].begin(), sw[i].end());
        queue<Step> qu;
        Step cur;
        cur.state = 10; cur.step.clear();
        check[cur.state] = 1;
        qu.push(cur);
        int ok = 0;
        while (!qu.empty())
        {
            cur = qu.front();
            if (cur.state == (1 << (r - 1)) * 10 + r - 1) {
                ok = 1; break;
            }
            qu.pop();
            int room_state = cur.state / 10;
            int cur_room = cur.state % 10;
            //Move
            for (int i = 0; i < r; i ++)
                if (i != cur_room && (room_state & (1 << i)) && a[cur_room][i] && check[room_state * 10 + i] == 0)
                {
                    Step y;
                    stringstream ss;
                    ss << i+1;
                    string s = "Move to room " + ss.str() + ".";
                    y.step = cur.step;
                    y.step.push_back(s);
                    y.state = room_state * 10 + i;
                    check[y.state] = 1;
                    qu.push(y);
                }
            //Turn off
            for (int i = 0; i < sw[cur_room].size(); i ++)
                if (sw[cur_room][i] != cur_room && (room_state & (1 << sw[cur_room][i])))
                {
                    int new_state = (room_state - (1 << sw[cur_room][i])) * 10 + cur_room;
                    if (check[new_state] == 0)
                    {
                        Step y;
                        stringstream ss;
                        ss << sw[cur_room][i] + 1;
                        string s = "Switch off light in room " + ss.str() + ".";
                        y.step = cur.step;
                        y.step.push_back(s);
                        y.state = new_state;
                        check[y.state] = 1;
                        qu.push(y);
                    }
                }
            //Turn on
            for (int i = 0; i < sw[cur_room].size(); i++)
                if ((room_state & (1 << sw[cur_room][i])) == 0)
                {
                    int new_state = (room_state + (1 << sw[cur_room][i])) * 10 + cur_room;
                    if (check[new_state] == 0)
                    {
                        Step y;
                        stringstream ss;
                        ss << sw[cur_room][i] + 1;
                        string s = "Switch on light in room " + ss.str() + ".";
                        y.step = cur.step;
                        y.step.push_back(s);
                        y.state = new_state;
                        check[y.state] = 1;
                        qu.push(y);
                    }
                }
        }
        printf("Villa #%d\n", ca++);
        if (ok == 0) printf("The problem cannot be solved.\n");
        else
        {
            printf("The problem can be solved in %d steps:\n", cur.step.size());
            for (int i = 0; i < cur.step.size(); i++)
            {
                printf("- %s\n", cur.step[i].c_str());
            }
        }
        printf("\n");
    }
    return 0;
}