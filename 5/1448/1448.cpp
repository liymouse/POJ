#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

typedef struct
{
    int p[4]; //0=top, 1=right, 2=bottom 3=left
}Face;

vector<Face> pis[5];
int bottom[4];
int use[5];
Face *match[4];

int canMatchTop(int x)
{
    int top[4];
    //get top 4 edges
    for (int i = 0; i < 4; i++)
    {
        top[i] = match[i]->p[0] | (match[(i + 3) % 4]->p[0] >> 5) | ((match[(i + 1) % 4]->p[0] & 1) << 5);
    }
    //try all rotation & flip
    for (int k = 0; k < pis[x].size(); k ++)
    {
        int can_match = 1;
        for (int i = 0; i < 4; i ++)
            if ((top[i] & pis[x][k].p[i]) != 0 ||
                (top[i] | pis[x][k].p[i]) != 63)
            {
                can_match = 0; break;
            }
        if (can_match) return 1;
    }
    return 0;
}
int revert(int L)
{
    int res = 0;
    for (int i = 0; i < 6; i ++)
    {
        res = (res << 1) | (L & 1);
        L >>= 1;
    }
    return res;
}
int canMatch(int x, Face &a)
{
    if (x == 0) //Bottom: a.p[2] <-> bottom[0], 1~4 must be filled
    {
        int b = revert(bottom[0]);
        if ((a.p[2] & b) == 0 && ((a.p[2] | b) & 30) == 30) return 1;
    }
    else if (x == 1)
    {
        //Bottom: a.p[2] <-> bottom[1], 1~5 must be filled
        //Left: a.p[3] <-> match[0]->p[1], 0~4 must be filled
        int b = bottom[1] | (match[0]->p[1] >> 5);
        int L = match[0]->p[1] | ((bottom[1] & 1) << 5);
        b = revert(b);
        L = revert(L);
        if ((a.p[2] & b) == 0 && ((a.p[2] | b) & 62) == 62 &&
            (a.p[3] & L) == 0 && ((a.p[3] | L) & 31) == 31) return 1;
    }
    else if (x == 2)
    {
        //Bottom: a.p[2] <-> bottom[2], 1~5 must be filled
        //Left: a.p[3] <-> match[1]->p[1], 0~4 must be filled
        int b = bottom[2] | (match[1]->p[1] >> 5);
        int L = match[1]->p[1] | ((bottom[2] & 1) << 5);
        b = revert(b);
        L = revert(L);
        if ((a.p[2] & b) == 0 && ((a.p[2] | b) & 62) == 62 &&
            (a.p[3] & L) == 0 && ((a.p[3] | L) & 31) == 31) return 1;
    }
    else
    {
        //Bottom: a.p[2] <-> bottom[3], 0~5 must be filled
        //Left: a.p[3] <-> match[2]->p[1], 0~4 must be filled
        //Right: a.p[1] <-> match[0]->p[3], 1~5 must be filled
        int b = bottom[3] | (match[2]->p[1] >> 5) | ((match[0]->p[3] & 1) << 5);
        int L = match[2]->p[1] | ((bottom[3] & 1) << 5);
        int r = match[0]->p[3] | (bottom[0] & 1);
        b = revert(b);
        L = revert(L);
        r = revert(r);
        if ((a.p[2] & b) == 0 && (a.p[2] | b) == 63 &&
            (a.p[3] & L) == 0 && ((a.p[3] | L) & 31) == 31 &&
            (a.p[1] & r) == 0 && ((a.p[1] | r) & 62) == 62) return 1;
    }
    return 0;
}
int dfs(int x)
{
    if (x == 4)
    {
        for (int i = 0; i < 5; i++)
            if (use[i] == 0) return canMatchTop(i);
    }
    for (int i = 0; i < 5; i ++)
        if (use[i] == 0)
        {
            for (int j = 0; j < pis[i].size(); j ++)
                if (canMatch(x, pis[i][j]))
                {
                    use[i] = 1;
                    match[x] = &pis[i][j];
                    if (dfs(x + 1)) return 1;
                    match[x] = 0;
                    use[i] = 0;
                }
        }
    return 0;
}
int main()
{
    int cas;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        char s[100];
        char a[6][6][6] = { 0 };
        int tot = 0;
        int ok = 1;
        for (int i = 0; i < 6; i++)
        {
            scanf("%s", s);
            for (int k = 0; k < 6; k++)
            {
                for (int j = 0; j < 6; j ++)
                    if (s[k * 7 + j] == 'X') { tot++; a[k][i][j] = 1; }
                    else a[k][i][j] = 0;
            }
        }
        if (tot != 152) ok = 0;
        else
        {
            //set pic[5] as bottom pic
            memset(bottom, 0, sizeof(bottom));
            for (int i = 0; i < 6; i++) bottom[0] |= a[5][0][i] << i;
            for (int i = 0; i < 6; i++) bottom[1] |= a[5][i][5] << i;
            for (int i = 5; i >= 0; i--) bottom[2] |= a[5][5][i] << (5-i);
            for (int i = 5; i >= 0; i--) bottom[3] |= a[5][i][0] << (5-i);
            memset(use, 0, sizeof(use));
            //generate all rotation & flip for each pics
            for (int k = 0; k < 5; k++)
            {
                pis[k].clear();
                Face x = { 0 };
                for (int i = 0; i < 6; i++) x.p[0] |= a[k][0][i] << i;
                for (int i = 0; i < 6; i++) x.p[1] |= a[k][i][5] << i;
                for (int i = 5; i >= 0; i--) x.p[2] |= a[k][5][i] << (5-i);
                for (int i = 5; i >= 0; i--) x.p[3] |= a[k][i][0] << (5-i);
                pis[k].push_back(x);
                //rotate
                Face y = { 0 };
                for (int of = 1; of <= 3; of ++)
                {
                    for (int i = 0; i < 4; i ++) y.p[i] = x.p[(i + of) % 4];
                    int find = -1;
                    for (int t = 0; t < pis[k].size(); t++)
                    {
                        int same = 1;
                        for (int i = 0; i < 4; i++) if (y.p[i] != pis[k][t].p[i]) { same = 0; break; }
                        if (same) { find = t; break; }
                    }
                    if (find == -1) pis[k].push_back(y);
                }
                //flip & rotate
                memset(x.p, 0, sizeof(x.p));
                for (int i = 5; i >= 0; i--) x.p[0] |= a[k][0][i] << (5-i);
                for (int i = 0; i < 6; i++) x.p[1] |= a[k][i][0] << i;
                for (int i = 0; i < 6; i++) x.p[2] |= a[k][5][i] << i;
                for (int i = 5; i >= 0; i--) x.p[3] |= a[k][i][5] << (5-i);
                for (int of = 0; of <= 3; of ++)
                {
                    for (int i = 0; i < 4; i ++) y.p[i] = x.p[(i + of) % 4];
                    int find = -1;
                    for (int t = 0; t < pis[k].size(); t++)
                    {
                        int same = 1;
                        for (int i = 0; i < 4; i++) if (y.p[i] != pis[k][t].p[i]) { same = 0; break; }
                        if (same) { find = t; break; }
                    }
                    if (find == -1) pis[k].push_back(y);
                }
            }
            //try to stitch them as bottom[0], bottom[1], bottom[2], bottom[3], top order
            ok = dfs(0);
        }
        printf("Scenario #%d:\n", ca);
        if (ok) printf("Yes\n"); else printf("No\n");
        printf("\n");
    }
    return 0;
}
