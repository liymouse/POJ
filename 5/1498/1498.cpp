#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int M[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
char name[8] = "SMTWRFS";
int curm, curd, curname;
int getDay(int m, int d)
{
    if (curm == m && curd <= d) return d - curd;
    int day = M[curm] - curd;
    int mm = (curm+1) % 12;
    while (mm != m)
    {
        day += M[mm];
        mm = (mm + 1) % 12;
    }
    day += d;
    return day;
}
void getDate(int &m, int &d, int day)
{
    m = curm;
    d = curd;
    while (day)
    {
        if (day <= M[m] - d)
        {
            d += day;
            return;
        }
        day -= M[m] - d;
        m = (m + 1) % 12;
        d = 0;
    }
}
int sche[365][32] = { 0 };
int main()
{
    char s[100];
    int n, t;
    scanf("%s %d %d", s, &curm, &curd);
    curm--;
    for (int i = 1; i <= 5; i++) if (s[0] == name[i]) { curname = i; break; }
    scanf("%d %d", &n, &t); gets_s(s);
    while (1)
    {
        gets_s(s);
        if (!strcmp(s, "done")) break;
        int m, d, st, et;
        while (scanf("%s", s) == 1)
        {
            if (!strcmp(s, "done")) break;
            scanf("%d %d %d %d", &m, &d, &st, &et);
            m--;
            int day = getDay(m, d);
            st = ((st / 100) - 9) * 4 + (st % 100) / 15;
            et = ((et / 100) - 9) * 4 + (et % 100) / 15;
            for (int i = st; i < et; i++) sche[day][i] = 1;
        }
        gets_s(s);
    }
    t = t / 15;
    int res = 0;
    for (int d = 0; d < 365; d++)
        if (1 <= (curname + d) % 7 && (curname + d) % 7 <= 5)
        {
            int L = 0;
            for (int i = 0; i < 32; i++)
                if (sche[d][i] == 0)
                {
                    L++;
                    if (L == t)
                    {
                        res++;
                        //output
                        int rn, rm, rd, rst;
                        rn = (curname + d) % 7;
                        getDate(rm, rd, d);
                        rm++;
                        rst = (9 + (i - L + 1) / 4) * 100 + ((i-L+1)%4)*15;
                        printf("%c %d %d %04d\n", name[rn], rm, rd, rst);
                        if (res == n) goto L_exit;
                        L = 0;
                    }
                }
                else L = 0;
        }
    if (res < n) printf("No more times available\n");
L_exit:
    return 0;
}
