#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int dd[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int getYear(int y)
{
    return y - 1970;
}
int getMonth(int y, int m)
{
    return (y - 1970) * 12 + m - 1;
}
int getDay(int y, int m, int d)
{
    int res = 0;
    for (int i = 1970; i < y; i++)
        if ((i % 100 != 0 && i % 4 == 0) || i % 400 == 0) res += 366;
        else res += 365;
    if ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0)) dd[2] = 29;
    else dd[2] = 28;
    for (int i = 1; i < m; i++) res += dd[i];
    res += d - 1;
    return res;
}
int getHour(int y, int m, int d, int h)
{
    int res = getDay(y, m, d) * 24;
    res += h - 1;
    return res;
}
int getMinute(int y, int m, int d, int h, int mm)
{
    int res = getHour(y, m, d, h) * 60;
    res += mm - 1;
    return res;
}
int getSceond(int y, int m, int d, int h, int mm, int s)
{
    int res = getMinute(y, m, d, h, mm) * 60;
    res += s - 1;
    return res;
}
int main()
{
    int y1, m1, d1, hh1, mm1, ss1;
    int y2, m2, d2, hh2, mm2, ss2;
    int t;
    char s[20];
    while (scanf("%d %d %d %d %d %d", &y1, &m1, &d1, &hh1, &mm1, &ss1) == 6)
    {
        scanf("%d %d %d %d %d %d", &y2, &m2, &d2, &hh2, &mm2, &ss2);
        scanf("%d %s", &t, s);
        int res = 0;
        if (!strcmp(s, "second"))
        {
            res = getSceond(y2, m2, d2, hh2, mm2, ss2) - getSceond(y1, m1, d1, hh1, mm1, ss1);
        }
        else if (!strcmp(s, "minute"))
        {
            if (ss1 != 0) mm1++;
            res = getMinute(y2, m2, d2, hh2, mm2) - getMinute(y1, m1, d1, hh1, mm1);
        }
        else if (!strcmp(s, "hour"))
        {
            if (mm1 != 0 || ss1 != 0) hh1++;
            res = getHour(y2, m2, d2, hh2) - getHour(y1, m1, d1, hh1);
        }
        else if (!strcmp(s, "day"))
        {
            if (hh1 != 0 || mm1 != 0 || ss1 != 0) d1++;
            res = getDay(y2, m2, d2) - getDay(y1, m1, d1);
        }
        else if (!strcmp(s, "month"))
        {
            if (d1 != 1 || hh1 != 0 || mm1 != 0 || ss1 != 0) m1++;
            res = getMonth(y2, m2) - getMonth(y1, m1);
        }
        else
        {
            if (m1 != 1 || d1 != 1 || hh1 != 0 || mm1 != 0 || ss1 != 0) y1++;
            res = getYear(y2) - getYear(y1);
        }
        printf("%d\n", max(0,res)/t);
    }
    return 0;
}