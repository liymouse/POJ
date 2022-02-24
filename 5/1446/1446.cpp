#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char weeks[7][5] = { "SUN,", "MON,", "TUE,", "WED,", "THU,", "FRI,", "SAT," };
char months[13][4] = { "", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
char days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void getPreDay(int &yy, int &mm, int &dd)
{
    dd--;
    if (dd <= 0)
    {
        mm--;
        if (mm <= 0)
        {
            mm = 12; yy--;
        }
        dd = days[mm];
        if (mm == 2 && ((yy % 100 != 0 && yy % 4 == 0) || yy % 400 == 0)) dd = 29;
    }
}
void getNextDay(int &yy, int &mm, int &dd)
{
    dd++;
    if (mm == 2 && ((yy % 100 != 0 && yy % 4 == 0) || yy % 400 == 0)) days[2] = 29;
    if (dd > days[mm])
    {
        dd = 1;
        mm++;
        if (mm > 12)
        {
            mm = 1; yy++;
        }
    }
    days[2] = 28;
}
int main()
{
    char wws[10], mms[10], yys[10], tt[20], tz[10];
    int dd, yy, ww, mm, hour, mini, sec, of_hour, of_mini = 0;
    scanf("%s %d %s %s %s %s", wws, &dd, mms, yys, tt, tz);
    for (int i = 0; i < 7; i ++)
        if (!strcmp(wws, weeks[i])) { ww = i; break; }
    for (int i = 1; i <= 12; i ++)
        if (!strcmp(mms, months[i])) { mm = i; break; }
    yy = atoi(yys);
    if (strlen(yys) == 2) yy += 1900;
    hour = (tt[0] - '0') * 10 + (tt[1] - '0');
    mini = (tt[3] - '0') * 10 + (tt[4] - '0');
    sec = (tt[6] - '0') * 10 + (tt[7] - '0');
    if (tz[0] == '+' || tz[0] == '-')
    { 
        of_hour = (tz[1] - '0') * 10 + tz[2] - '0';
        of_mini = (tz[3] - '0') * 10 + tz[4] - '0';
        if (tz[0] == '-') {
            of_hour = -of_hour; of_mini = -of_mini;
        }
    }
    else if (!strcmp(tz, "UT") || !strcmp(tz, "GMT")) of_hour = 0;
    else if (!strcmp(tz, "EDT")) of_hour = -4;
    else if (!strcmp(tz, "CDT")) of_hour = -5;
    else if (!strcmp(tz, "MDT")) of_hour = -6;
    else of_hour = -7;
    int offset = 3 * 60 - (of_hour * 60 + of_mini);
    int t = hour * 60 + mini;
    t += offset;
    if (t < 0) {
        t += 24 * 60; getPreDay(yy, mm, dd);
        ww = (ww + 6) % 7;
    }
    else if (t >= 24 * 60)
    {
        t -= 24 * 60; getNextDay(yy, mm, dd);
        ww = (ww + 1) % 7;
    }
    hour = t / 60;
    mini = t % 60;
    printf("%s %02d %s %04d %02d:%02d:%02d +0300\n", weeks[ww], dd, months[mm], yy, hour, mini, sec);
    return 0;
}
