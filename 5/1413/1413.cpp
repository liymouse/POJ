#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct
{
    int get, goaldiff, score;
}Team;
int sc[4], fix[4], point[4][4];
int cmp(Team &x, Team &y)
{
    if (x.score > y.score) return 1;
    else if (x.score < y.score) return -1;
    else
    {
        if (x.goaldiff > y.goaldiff) return 1;
        else if (x.goaldiff < y.goaldiff) return -1;
        else
        {
            if (x.get > y.get) return 1;
            else if (x.get < y.get) return -1;
            return 0;
        }
    }
}
void rankTeam(int ta, int n)
{
    Team y[4] = { 0 };
    for (int i = 0; i < 3; i++)
        if (!fix[i])
            for (int j = i + 1; j < 4; j++)
                if (!fix[j])
                {
                    y[i].get += point[i][j];
                    y[i].goaldiff += point[i][j] - point[j][i];
                    y[j].get += point[j][i];
                    y[j].goaldiff += point[j][i] - point[i][j];
                    if (point[i][j] > point[j][i]) y[i].score += 3;
                    else if (point[j][i] > point[i][j]) y[j].score += 3;
                    else { y[i].score++; y[j].score++; }
                }
    int tile = 1;
    for (int i = 0; i < 4; i++)
        if (i != ta && !fix[i])
        {
            int check = cmp(y[ta], y[i]);
            if (check > 0) {
                fix[i] = 1; sc[i] = -n;
            }
            else if (check < 0) {
                fix[i] = 1; sc[i] = n;
            }
            else {
                tile++;
            }
        }
    if (1 < tile && tile < n)
    {
        rankTeam(ta, tile);
    }
}
int main()
{
    //calculate p
    double p[9];
    double jie[9] = { 1.0 };
    for (int i = 1; i <= 8; i++) jie[i] = jie[i - 1] * i;
    for (int i = 0; i <= 8; i++)
    {
        p[i] = 40320.0 / (jie[i] * jie[8 - i]);
        for (int j = 0; j < i; j++) p[i] *= 0.25;
        for (int j = 0; j < 8 - i; j++) p[i] *= 0.75;
        //printf("%lf,", p[i]);
    }
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        char s[100];
        int t[4];
        int target = 0;
        scanf("%s", s);
        int tn = 0;
        memset(point, 0, sizeof(point));
        for (int i = 0; i < 4; i++)
        {
            scanf("%s", s);
            if (s[0] == '*') target = i;
            for (int j = i+1; j < 4; j ++)
                if (s[5 * (j + 1) + 1] == '_') { t[tn++] = i; t[tn++] = j; }
                else
                {
                    point[i][j] = s[5 * (j + 1) + 1] - '0';
                    point[j][i] = s[5 * (j + 1) + 3] - '0';
                }
        }
        double res = 0;
        for (int a = 0; a <= 8; a ++)
            for (int b = 0; b <= 8; b ++)
                for (int c = 0; c <= 8; c ++)
                    for (int d = 0; d <= 8; d ++)
                    {
                        double pp = p[a] * p[b] * p[c] * p[d];
                        point[t[0]][t[1]] = a;
                        point[t[1]][t[0]] = b;
                        point[t[2]][t[3]] = c;
                        point[t[3]][t[2]] = d;
                        memset(sc, 0, sizeof(sc));
                        memset(fix, 0, sizeof(fix));
                        rankTeam(target, 4);
                        int win = 0, lose = 0, tile = 0;
                        for (int i = 0; i < 4; i ++)
                            if (i != target)
                            {
                                if (sc[target] > sc[i]) win++;
                                else if (sc[target] < sc[i]) lose++;
                                else tile++;
                            }
                        if (win >= 2) res += pp;
                        else if (win == 1)
                        {
                            if (tile == 1) res += pp * 0.5;
                            else if (tile == 2) res += pp * 2.0 / 3.0;
                        }
                        else
                        {
                            if (tile == 2) res += pp / 3.0;
                            else if (tile == 3) res += pp * 0.5;
                        }
                    }
        printf("%.7lf\n", res);
    }
    return 0;
}
