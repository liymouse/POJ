#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef struct
{
    char name[]
};
typedef struct
{
    set<int> page;
    map<string, set<int> > secondary;
}Index;

int cmpIndex(Index &x, Index &y)
{
    char xs[200] = { 0 }, ys[200] = { 0 };
    for (int i = 0; i < )
    return strcmp(x.prime.ind_name, y.prime.ind_name);
}
int cmpElm(Elm &x, Elm &y)
{
    return strcmp(x.ind_name, y.ind_name);
}
int main()
{
    char s[200];
    int ca = 1;
    int page = 1;
    vector<Index> a;
    Index x;
    Elm y;
    int st;
    while (gets_s(s))
    {
        if (s[0] == '*' && s[1] == 0)
        {
            //output;
            printf("DOCUMENT %d\n", ca++);

            //clear
            a.clear();
            page = 1;
        }
        else if (s[0] == '*' && s[1] == '*' && s[2] == 0) break;
        else
        {
            int L = strlen(s);
            for (int i = 0; i < L; i++)
                if (s[L] == '&') page++;
                else if (s[L] == '{')
                {
                    initIndex(x);
                    initElm(y);
                }
        }
    }
    return 0;
}