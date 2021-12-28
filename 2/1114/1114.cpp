#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
void addElm(vector<pair<string, int> > &a, string name, int x, int y)
{
    int k = -1;
    for (int j = 0; j < a.size(); j++)
        if (a[j].first == name) { k = j; break; }
    if (k != -1) a[k].second += x * y;
    else
    {
        a.push_back(make_pair(name, x * y));
    }
}
//xOy = x*y O
void add(vector<pair<string, int> > &a, char s[], int L, int x, int y)
{
    if (L == 1 && 'A' <= s[0] && s[0] <= 'Z') {
        addElm(a, string(s, 1), x, y); return;
    }
    if (L == 2 && 'A' <= s[0] && s[0] <= 'Z' && 'a' <= s[1] && s[1] <= 'z')
    {
        addElm(a, string(s, 2), x, y); return;
    }
    if (L == 0) return;
    int i = 0;
    //find x
    int xx = 0;
    while ('0' <= s[i] && s[i] <= '9') {
        xx = xx * 10 + s[i] - '0'; i++;
    }
    if (xx == 0) xx = 1;
    xx *= x;

    while (i < L)
    {
        int begin = i, end = i;
        if (s[i] == '(') //find )
        {
            begin = i + 1;
            int kuohao = 0;
            while (i < L)
            {
                if (s[i] == '(') kuohao++;
                else if (s[i] == ')') {
                    kuohao--;
                    if (kuohao == 0) break;
                }
                i++;
            }
            end = i;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
        {
            if ('a' <= s[i + 1] && s[i + 1] <= 'z') { end = i + 2; i++; }
            else end = i + 1;
        }
        i++;
        int yy = 0;
        while ('0' <= s[i] && s[i] <= '9')
        {
            yy = yy * 10 + s[i] - '0'; i++;
        }
        if (yy == 0) yy = 1;
        add(a, s + begin, end - begin, xx, yy * y);
    }
}

void getNum(vector<pair<string, int> > &a, char s[])
{
    int L = strlen(s);
    int i = 0, j = 0;
    while (j < L)
    {
        while (j < L && s[j] != '+') j++;
        add(a, s + i, j - i, 1, 1);
        j++;
        i = j;
    }
}
int cmp(pair<string, int> &x, pair<string, int> &y)
{
    return x.first < y.first;
}
int main()
{
    char s0[101], s1[101];
    scanf("%s", s0);
    vector<pair<string, int> > left;
    getNum(left, s0);
    sort(left.begin(), left.end());
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s1);
        vector<pair<string, int> > right;
        getNum(right, s1);
        sort(right.begin(), right.end());
        int eq = (left.size() == right.size());
        if (eq)
        {
            for (int j = 0; j < left.size(); j ++)
                if (left[j].first != right[j].first || left[j].second != right[j].second) { eq = 0; break; }
        }
        printf("%s%s%s\n", s0, eq ? "==" : "!=", s1);
    }
    return 0;
}