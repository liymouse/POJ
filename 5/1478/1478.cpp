#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
    int x, y, is, type;
}Talk;
enum {
    NONE, DIVINE, HUMAN, EVIL, LYING, DAY, NIGHT, ANY
};
char name[10][11] = { "none", "divine", "human", "evil", "lying", "day", "night" };
int cur_type[5];
int res_type[5], res_time, res_num;
Talk a[100];
int n;

int check_talk(int i, int t)
{
    int lier = (cur_type[a[i].x] == EVIL) || (t == NIGHT && cur_type[a[i].x] == HUMAN);
    int correct;
    if (DIVINE <= a[i].type && a[i].type <= EVIL)
    {
        if (cur_type[a[i].y] == a[i].type && a[i].is == 1) correct = 1;
        else if (cur_type[a[i].y] != a[i].type && a[i].is == 0) correct = 1;
        else correct = 0;
    }
    else if (a[i].type == LYING)
    {
        int y_lier = (cur_type[a[i].y] == EVIL) || (t == NIGHT && cur_type[a[i].y] == HUMAN);
        if (y_lier && a[i].is == 1) correct = 1;
        else if (!y_lier && a[i].is == 0) correct = 1;
        else correct = 0;
    }
    else if (a[i].type == DAY) correct = (t == DAY);
    else correct = (t == NIGHT);
    if (lier) return !correct;
    return correct;
}
void check(int t)
{
    for (int i = 0; i < n; i++)
        if (check_talk(i, t) == 0) return;
    res_num++;
    for (int i = 0; i < 5; i++)
        if (cur_type[i] != NONE)
        {
            if (res_type[i] == NONE) res_type[i] = cur_type[i];
            else if (res_type[i] != cur_type[i]) res_type[i] = ANY;
        }
    if (res_time == NONE) res_time = t;
    else if (res_time != t) res_time = ANY;
}
int main()
{
    int ca = 1;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        char s1[30], s2[30];
        int has[5] = { 0 };
        for (int i = 0; i < n; i++)
        {
            scanf("%s%s", s1, s2);
            a[i].x = s1[0] - 'A';
            if (s2[0] == 'I') a[i].y = a[i].x;
            else a[i].y = s2[0] - 'A';
            has[a[i].x] = has[a[i].y] = 1;
            scanf("%s%s", s1, s2); //skip s1
            if (!strcmp(s2, "not")) //not
            {
                a[i].is = 0;
                scanf("%s", s2);
            }
            else a[i].is = 1;
            if (!strcmp(s2, "divine.")) a[i].type = DIVINE;
            else if (!strcmp(s2, "human.")) a[i].type = HUMAN;
            else if (!strcmp(s2, "evil.")) a[i].type = EVIL;
            else if (!strcmp(s2, "lying.")) a[i].type = LYING;
            else if (!strcmp(s2, "day.")) a[i].type = DAY;
            else a[i].type = NIGHT;
        }
        res_num = 0;
        memset(res_type, 0, sizeof(res_type));
        res_time = 0;
        int si[5], ei[5];
        for (int i = 0; i < 5; i++) if (has[i]) { si[i] = DIVINE; ei[i] = EVIL; }
        else si[i] = ei[i] = NONE;
        for (cur_type[0] = si[0]; cur_type[0] <= ei[0]; cur_type[0] ++)
            for (cur_type[1] = si[1]; cur_type[1] <= ei[1]; cur_type[1] ++)
                for (cur_type[2] = si[2]; cur_type[2] <= ei[2]; cur_type[2] ++)
                    for (cur_type[3] = si[3]; cur_type[3] <= ei[3]; cur_type[3] ++)
                        for (cur_type[4] = si[4]; cur_type[4] <= ei[4]; cur_type[4] ++)
                        {
                            check(DAY);
                            check(NIGHT);
                        }
        printf("Conversation #%d\n", ca++);
        if (res_num == 0) printf("This is impossible.\n");
        else
        {
            int has = 0;
            for (int i = 0; i < 5; i++)
                if (DIVINE <= res_type[i] && res_type[i] <= EVIL)
                {
                    has = 1;
                    printf("%c is %s.\n", i + 'A', name[res_type[i]]);
                }
            if (res_time == DAY || res_time == NIGHT)
            {
                has = 1;
                printf("It is %s.\n", name[res_time]);
            }
            if (has == 0) printf("No facts are deducible.\n");
        }
        printf("\n");
    }
    return 0;
}
