#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct { int sx, ex, sy, ey; } Rect;
int main()
{
    int n, ca = 1;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        Rect r[26];
        int a[26][26] = { 0 };
        int degreeL[26] = { 0 };
        int degreeR[26] = { 0 };
        int res[26];
        for (int i = 0; i < n; i++) scanf("%d %d %d %d", &r[i].sx, &r[i].ex, &r[i].sy, &r[i].ey);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            res[i] = -1;
            for (int j = 0; j < n; j++)
                if (r[j].sx < x && x < r[j].ex && r[j].sy < y && y < r[j].ey)
                {
                    a[i][j] = 1;
                    degreeR[j] ++;
                    degreeL[i] ++;
                }
        }
        while (1)
        {
            //find degree 1 in right side (A~Z)
            int t = -1;
            for (int i = 0; i < n; i ++)
                if (degreeR[i] == 1) { t = i; break; }
            if (t != -1)
            {
                for (int i = 0; i < n; i++)
                    if (a[i][t])
                    {
                        res[t] = i;
                        degreeL[i] = 0;
                        for (int j = 0; j < n; j++)
                            if (a[i][j])
                            {
                                a[i][j] = 0;
                                degreeR[j] --;
                            }
                    }
            }
            else
            {
                //find degree 1 in left side (1~26)
                for (int i = 0; i < n; i ++)
                    if (degreeL[i] == 1) { t = i; break; }
                if (t == -1) break;
                for (int i = 0; i < n; i ++)
                    if (a[t][i])
                    {
                        res[i] = t;
                        degreeR[i] = 0;
                        for (int j = 0; j < n; j ++)
                            if (a[j][i])
                            {
                                a[j][i] = 0;
                                degreeL[j] --;
                            }
                    }
            }
        }
        printf("Heap %d\n", ca++);
        int first = 1;
        for (int i = 0; i < n; i ++)
            if (res[i] != -1)
            {
                if (!first) printf(" ");
                else first = 0;
                printf("(%c,%d)", 'A' + i, res[i] + 1);
            }
        if (first) printf("none\n"); 
        else printf("\n");
        printf("\n");
    }
    return 0;
}
