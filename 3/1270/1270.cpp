#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[26];
int du[26];
vector<int> bian[26];
int n;
char res[26] = { 0 };

void find(int x)
{
    if (x == n)
    {
        printf("%s\n", res);
        return;
    }
    for (int i = 0; i < 26; i ++)
        if (a[i] && du[i] == 0)
        {
            res[x] = 'a' + i;
            a[i] = 0;
            for (int j = 0; j < bian[i].size(); j++)
                du[bian[i][j]] --;
            find(x + 1);
            for (int j = 0; j < bian[i].size(); j++)
                du[bian[i][j]] ++;
            a[i] = 1;
        }
}
int main()
{
    char s0[1024], s1[1024];
    while (gets_s(s0))
    {
        gets_s(s1);
        int L0 = strlen(s0);
        memset(a, 0, sizeof(a));
        memset(du, 0, sizeof(du));
        memset(res, 0, sizeof(res));
        n = 0;
        for (int i = 0; i < 26; i++) bian[i].clear();
        for (int i = 0; i < L0; i++)
            if ('a' <= s0[i] && s0[i] <= 'z') {
                a[s0[i] - 'a'] = 1; n++;
            }
        int L1 = strlen(s1);
        int num = 0;
        int x;
        for (int i = 0; i < L1; i ++)
            if ('a' <= s1[i] && s1[i] <= 'z')
            {
                num++;
                if (num == 1) x = s1[i] - 'a';
                else
                {
                    bian[x].push_back(s1[i] - 'a');
                    du[s1[i] - 'a'] ++;
                    num = 0;
                }
            }
        find(0);
        printf("\n");
    }
    return 0;
}