#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

vector<string> del[2], keep[2];

void getRes(char *res, int x)
{
    int k = 0;
    while (1)
    {
        int same = 1;
        for (int i = 0; i < del[x].size(); i++)
            if (k == del[x][i].length()) { same = -1; break; }
            else if (del[x][i][k] != del[x][0][k]) same = 0;
        if (same == 1) res[k] = del[x][0][k];
        else if (same == 0) res[k] = '?';
        else {
            same = 1;
            for (int i = 1; i < del[x].size(); i ++)
                if (del[x][i].length() != del[x][0].length()) { same = 0; break; }
            if (same == 0) res[k++] = '*';
            break;
        }
        k++;
    }
}
int canMatch(char *res, string s)
{
    int L = strlen(res);
    if (res[L - 1] == '*')
    {
        L--;
        if (L > s.length()) return 0;
    }
    else if (L != s.length()) return 0;
    for (int i = 0; i < L; i++)
        if (res[i] != '?' && res[i] != s[i]) return 0;
    return 1;
}
int main()
{
    char s[15];
    while (scanf("%s", s) == 1)
    {
        string a = "" , b = "";
        int i;
        for (i = 1; s[i] != '.'; i++) a += s[i];
        for (i = i + 1; s[i] != 0; i++) b += s[i];
        if (s[0] == '-')
        {
            del[0].push_back(a); del[1].push_back(b);
        }
        else
        {
            keep[0].push_back(a); keep[1].push_back(b);
        }
    }
    char resa[10] = { 0 }, resb[6] = { 0 };
    getRes(resa, 0);
    getRes(resb, 1);
    int ok = 1;
    for (int i = 0; i < keep[0].size(); i ++)
        if (canMatch(resa, keep[0][i]) && canMatch(resb, keep[1][i]))
        {
            ok = 0;
            break;
        }
    if (ok) printf("DEL %s.%s\n", resa, resb);
    else printf("IMPOSSIBLE\n");
    return 0;
}
