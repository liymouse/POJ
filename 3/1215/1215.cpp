#include <stdio.h>

int main()
{
    int fee[5][3] = { {10, 6, 2}, {25, 15, 5}, {53, 33, 13}, {87, 47, 17}, {144,80,30} };
    int start[8] = { 0, 8, 18, 22, 8 + 24, 18 + 24, 22 + 24, 24+24 };
    int ty[7] = { 2, 0, 1, 2, 0, 1, 2 };
    char type[3], num[20];
    int sh, sm, eh, em;
    while (scanf("%s", type) == 1)
    {
        if (type[0] == '#') break;
        scanf("%s %d %d %d %d", num, &sh, &sm, &eh, &em);
        if (eh < sh || (eh == sh && em <= sm)) eh += 24;
        int mm[3] = { 0 };
        int cost = 0;
        for (int i = 0; i < 7; i ++)
            if (start[i] <= sh && sh < start[i+1])
            {
                int endh, endm;
                if (eh < start[i + 1])//count all
                {
                    endh = eh; endm = em;
                }
                else //count part
                {
                    endh = start[i + 1]; endm = 0;
                }
                if (endm < sm) { endh--; endm += 60; }
                int c = (endh - sh) * 60 + endm - sm;
                mm[ty[i]] += c;
                cost += fee[type[0] - 'A'][ty[i]] * c;
                sh = endh + endm / 60;
                sm = endm % 60;
                if (sh == eh && sm == em) break;
            }
        printf("%10s%6d%6d%6d%3s%5d.%02d\n", num, mm[0], mm[1], mm[2], type, cost / 100, cost % 100);
    }
    return 0;
}