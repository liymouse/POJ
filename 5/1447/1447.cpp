#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<int> res;
int target;
char b[3][10];
int bL[3];
char s[20];

int getDay(int yy, int mm, int dd)
{
    int res = dd;
    if ((yy % 100 != 0 && yy % 4 == 0) || yy % 400 == 0) days[2] = 29;
    for (int i = 1; i < mm; i++) res += days[i];
    days[2] = 28;
    for (int i = 1700; i < yy; i++)
    {
        if ((i % 100 != 0 && i % 4 == 0) || i % 400 == 0) res += 366;
        else res += 365;
    }
    return res;
}
int valid(int yy, int mm, int dd)
{
    if (yy < 1700 || yy > 2299) return 0;
    if ((yy % 100 != 0 && yy % 4 == 0) || yy % 400 == 0) days[2] = 29;
    int ok = 1;
    if (mm < 1 || mm > 12 || dd < 1 || dd > days[mm]) ok = 0;
    days[2] = 28;
    return ok;
}
void tryIt(char a[][10])
{
    int id[3] = { 0, 1, 2 };
    do
    {
        char *y = a[id[0]], *m = a[id[1]], *d = a[id[2]];
        int Ly = strlen(y);
        int Lm = strlen(m);
        int Ld = strlen(d);
        if ((Ly == 4 || Ly == 2 || Ly == 1) && (Lm == 1 || Lm == 2) && (Ld == 1 || Ld == 2))
        {
            int mm = atoi(m), dd = atoi(d), yy;
            if (1 <= mm && mm <= 12 && 1 <= dd && dd <= 31)
            {
                int L = strlen(y);
                if (L == 4)
                {
                    yy = atoi(y);
                    if (valid(yy, mm, dd))
                    {
                        int k = getDay(yy, mm, dd);
                        res.push_back(k - target);
                    }
                }
                else
                {
                    int base = atoi(y);
                    for (int i = 1700; i <= 2200; i += 100)
                    {
                        yy = i + base;
                        if (valid(yy, mm, dd))
                        {
                            int k = getDay(yy, mm, dd);
                            res.push_back(k - target);
                        }
                    }
                }
            }
        }
    } while (next_permutation(id, id + 3));
}

int main()
{
    int cas;
    target = getDay(2001, 11, 4);
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        scanf("%s", s);
        int i = 0;
        while ('0' <= s[i] && s[i] <= '9') i++;
        res.clear();
        if (s[i] == 0) //no delimiters
        {
            int L = strlen(s);
            for (int x = 1; x < L; x ++)
                if (x == 1 || x == 2 || x == 4)
                for (int y = x + 1; y < L; y++)
                    if ((y-x == 1 || y-x == 2 || y-x == 4) &&
                        (L-y == 1 || L-y == 2 || L-y == 4))
                    {
                        char a[3][10] = { 0 };
                        for (int i = 0; i < x; i++) a[0][i] = s[i];
                        for (int i = x; i < y; i++) a[1][i - x] = s[i];
                        for (int i = y; i < L; i++) a[2][i - y] = s[i];
                        tryIt(a);
                    }
        }
        else
        {
            char a[3][10] = { 0 };
            i = 0;
            int L = 0;
            while ('0' <= s[i] && s[i] <= '9') a[0][L++] = s[i++];
            i++; L = 0;
            while ('0' <= s[i] && s[i] <= '9') a[1][L++] = s[i++];
            i++; L = 0;
            while ('0' <= s[i] && s[i] <= '9') a[2][L++] = s[i++];
            tryIt(a);
        }
        printf("Scenario #%d:\n", ca);
        if (res.size() == 0) printf("Illegal date\n");
        else
        {
            sort(res.begin(), res.end());
            printf("%d\n", res[0]);
            for (int i = 1; i < res.size(); i++)
                if (res[i] != res[i-1]) printf("%d\n", res[i]);
        }
        printf("\n");
    }
    return 0;
}
