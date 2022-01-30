#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    char line[50];
    while (gets_s(line))
    {
        vector<int> p, r;
        int pi, ri;
        while (sscanf(line, "%d", &pi) == 1)
        {
            p.push_back(pi);
            if (pi == 0) r.push_back(1);
            else
            {
                sscanf(line, "%d %d", &pi, &ri);
                r.push_back(ri);
            }
            gets_s(line);
        }
        int res = 0;
        for (int i = 0; i < p.size() - 1; i++)
        {
            int L2 = 0;
            int ok = 1;
            for (int j = i + 1; j < p.size(); j++)
            {
                if (p[j] == 0) L2++;
                else if (p[j] > L2) { ok = 0; break; }
                else L2 += r[j];
            }
            if (ok) res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
