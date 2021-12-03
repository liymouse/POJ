#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct
{
    char name[300];
    int star;
}Event;
typedef struct
{
    char name[300];
    char label[20];
    int m, d;
    int show;
}OutEvent;

vector<Event> a[12][33];
int mm[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int cmp(OutEvent &x, OutEvent &y)
{
    if (x.m < y.m) return 1; else if (x.m > y.m) return 0;
    if (x.d < y.d) return 1; else if (x.d > y.d) return 0;
    if (strcmp(x.label, y.label) > 0) return 1;
    else if (strcmp(x.label, y.label) < 0) return 0;
    if (x.show < y.show) return 1;
    return 0;
}

int main()
{
    int year, m, d;;
    scanf("%d", &year);
    mm[2] = (year % 4 == 0) ? 29: 28;
    char s[10];
    while (scanf("%s", s) == 1)
    {
        if (s[0] == '#') break;
        if (s[0] == 'A')
        {
            Event e;
            char str[300];
            scanf("%d %d %d", &d, &m, &e.star);
            gets_s(str);
            int k = 0;
            int L = strlen(str);
            if (str[L - 1] == '\n') str[L - 1] = 0;
            while (str[k] == ' ') k++;
            strcpy(e.name, str + k);
            a[m][d].push_back(e);
        }
        else if (s[0] == 'D')
        {
            scanf("%d %d", &d, &m);
            printf("Today is: %2d %2d\n", d, m);
            vector<OutEvent> out;
            int y = 0;
            for (int i = 0; i <= 7; i++)
            {
                for (int j = 0; j < a[m][d].size(); j ++)
                    if (a[m][d][j].star >= i)
                    {
                        OutEvent e;
                        e.d = d;
                        e.m = m + y;
                        e.show = j;
                        strcpy(e.name, a[m][d][j].name);
                        if (i == 0) sprintf(e.label, "*TODAY*");
                        else
                        {
                            int k = 0;
                            while (k < a[m][d][j].star - i + 1)
                            {
                                e.label[k ++] = '*';
                            }
                            e.label[k] = 0;
                        }
                        out.push_back(e);
                    }
                d++;
                if (d > mm[m])
                {
                    d = 1;
                    m++;
                    if (m > 12) {
                        m = 1; y = 12;
                    }
                }
            }
            if (out.size() > 0)
            {
                sort(out.begin(), out.end(), cmp);
                for (int i = 0; i < out.size(); i++)
                    printf(" %2d %2d %-7s %s\n", out[i].d, out[i].m>12?out[i].m-12:out[i].m, out[i].label, out[i].name);
            }
            printf("\n");
        }
    }
    return 0;
}