#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    char str[4][15];
    while (scanf("%s", str[0]) == 1)
    {
        if (str[0][0] == 'Q') break;
        scanf("%s%s%s", str[1], str[2], str[3]);
        int id[4] = { 0, 1, 2, 3 };
        int res = 0;
        do
        {
            //    c  d
            // aaacaadaa
            //    c  d
            // bbbcbbdbb
            //    c  d
            int w, h;
            char *a = str[id[0]], *b = str[id[1]], *c = str[id[2]], *d = str[id[3]];
            for (int a0 = 1; a0 < 9; a0 ++)
                for (int c0 = 1; c0 < 9; c0 ++)
                    if (a[a0] == c[c0])
                    {
                        for (int a1 = a0+2; a1 < 11; a1 ++)
                            for (int d0 = 1; d0 < 9; d0 ++)
                                if (a[a1] == d[d0])
                                {
                                    w = a1 - a0 - 1;
                                    int max_h = min(10 - c0 - 1, 10 - d0 - 1);
                                    if (w * max_h <= res) break;
                                    for (int b0 = 1; b0 < 10-w; b0 ++)
                                        for (int c1 = c0 + 2; c1 < 11; c1 ++)
                                            if (b[b0] == c[c1])
                                            {
                                                h = c1 - c0 - 1;
                                                int b1 = b0 + w + 1;
                                                int d1 = d0 + h + 1;
                                                if (d1 < 11 && b[b1] == d[d1])
                                                {
                                                    res = max(res, w * h);
                                                }
                                            }
                                }
                    }
            if (res == 64) break;
        } while (next_permutation(id, id + 4));
        printf("%d\n", res);
    }
    return 0;
}
