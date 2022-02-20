#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

typedef struct
{
    int b, k, t, w, i;
}Cle;

char Tzolkin[20][10] = { "Imix","Ik","Akbal","Kan","Chikchan","Kimi", "Manik",
"Lamat", "Muluk", "Ok", "Chuen", "Eb", "Ben", "Ix", "Men", "Kib", "Kaban",
"Etznab", "Kawak", "Ajaw" };

char Haab[19][10] = { "Pohp", "Wo", "Sip", "Zotz", "Sek", "Xul", "Yaxkin",
"Mol", "Chen", "Yax", "Sak", "Keh", "Mak", "Kankin", "Muan", "Pax", "Kayab",
"Kumku", "Wayeb" };
int Hd[19] = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
20, 20, 20, 20, 20, 20, 20, 20, 5 };

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        int tn, hn;
        char ts[20], hs[20];
        scanf("%d %s %d %s", &tn, ts, &hn, hs);
        int tid = -1, hid = -1;
        for (int i = 0; i < 20; i ++)
            if (!strcmp(Tzolkin[i], ts)) { tid = i; break; }
        for (int i = 0; i < 19; i ++)
            if (!strcmp(Haab[i], hs)) { hid = i; break; }
        if (tid == -1 || hid == -1 || tn < 1 || tn > 13 || hn < 1 || (hid < 18 && hn > 20) || (hid == 18 && hn > 5)) printf("0\n");
        else
        {
            tn--; hn--;
            int x0 = 8, x1 = 19, y0 = 2, y1 = 2; //9 Ajaw 3 Sip
            vector<Cle> res;
            for (int b = 8; b <= 9; b ++)
                for (int k= 0; k < 20; k ++)
                    for (int t = 0; t < 20; t ++)
                        for (int w = 0; w < 18; w ++)
                            for (int i = 0; i < 20; i++)
                            {
                                if (x0 == tn && x1 == tid && y0 == hn && y1 == hid)
                                {
                                    Cle a;
                                    a.b = b; a.k = k; a.t = t; a.w = w; a.i = i;
                                    res.push_back(a);
                                }
                                x0++; if (x0 == 13) x0 = 0;
                                x1++; if (x1 == 20) x1 = 0;
                                y0++;
                                if (y0 == Hd[y1]) {
                                    y0 = 0;
                                    y1++;
                                    if (y1 == 19) y1 = 0;
                                }
                            }
            printf("%d\n", res.size());
            for (int i = 0; i < res.size(); i++)
                printf("%d.%d.%d.%d.%d\n", res[i].b, res[i].k, res[i].t, res[i].w, res[i].i);
        }
    }
    return 0;
}
