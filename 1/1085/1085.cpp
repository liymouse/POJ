#include <stdio.h>
#include <string.h>
int memo[1 << 18] = { 0 };
int numA, numB;

int change(int x, int y)
{
    if (x > y) { int tmp = x; x = y; y = tmp; }
    if (x == 1 && y == 2) return 0;
    else if (x == 1 && y == 3) return 1;
    else if (x == 2 && y == 3) return 2;
    else if (x == 2 && y == 4) return 3;
    else if (x == 2 && y == 5) return 4;
    else if (x == 3 && y == 5) return 5;
    else if (x == 3 && y == 6) return 6;
    else if (x == 4 && y == 5) return 7;
    else if (x == 5 && y == 6) return 8;
    else if (x == 4 && y == 7) return 9;
    else if (x == 4 && y == 8) return 10;
    else if (x == 5 && y == 8) return 11;
    else if (x == 5 && y == 9) return 12;
    else if (x == 6 && y == 9) return 13;
    else if (x == 6 && y == 10) return 14;
    else if (x == 7 && y == 8) return 15;
    else if (x == 8 && y == 9) return 16;
    else return 17;
}
//0/1/2, 3/4/7, 2/4/5, 5/6/8, 9/10/15, 7/10/11, 11/12/16, 8/12/13, 13/14/17
int tra[9] = { 7, 152, 52, 352, 34304, 3200, 71680, 12544, 155648 };

int add(int &s, int t)
{
    int old = 0;
    for (int i = 0; i < 9; i++)
        if ((s & tra[i]) == tra[i]) old++;
    s |= (1 << t);
    int cur = 0;
    for (int i = 0; i < 9; i++)
        if ((s & tra[i]) == tra[i]) cur++;
    return cur - old;
}

int find(int s, int get)
{
    if (memo[s] != -1) return memo[s];
    int res = 0;
    if (s == (1 << 18) - 1)
    {
        res = 0;
    }
    else
    {
        int ns = s;
        int have = 1;
        while (have)
        {
            have = 0;
            //get all trangles 1st
            for (int i = 0; i < 9; i++)
            {
                int k = tra[i] - (ns & tra[i]);
                if (k != 0 && (k&(k - 1)) == 0) //add 1 can get a trangle
                {
                    ns |= k;
                    have = 1;
                    break;
                }
            }
        }
        if (ns == (1 << 18) - 1) { res = 9 - get; }
        else
        {
            int cur = 0;
            for (int i = 0; i < 9; i++)
                if ((ns & tra[i]) == tra[i]) cur++;

            int minv = 100;
            for (int i = 0; i < 18; i++)
                if ((ns & (1 << i)) == 0)
                {
                    int k = find(ns | (1 << i), cur);
                    if (k < minv) minv = k;
                }
            res = 9 - get - minv;
        }
    }
    memo[s] = res;
    return res;
}
int main()
{
    int cas;
    memset(memo, 0xff, sizeof(memo));
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        int n;
        int num[2] = { 0 };
        scanf("%d", &n);
        int s = 0;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            int cnt = add(s, change(x, y));
            if (cnt == 0) p = 1 - p;//change player
            else num[p] += cnt;
        }
        int cur = num[0] + num[1];
        num[p] += find(s, cur);
        num[1-p] = 9 - num[p];

        printf("Game %d: %c wins.\n", ca, (num[0] > num[1]) ? 'A' : 'B');
    }
    return 0;
}