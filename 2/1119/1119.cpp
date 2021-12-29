#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef struct
{
    string key;
    int num;
}Elm;
int main()
{
    char s[300];
    vector<Elm> search;
    while (scanf("%s", s))
    {
        if (strcmp(s, "----------") == 0) break;
        string a = "";
        int L = strlen(s);
        for (int i = 0; i < L; i++)
            if ('A' <= s[i] && s[i] <= 'Z') a += s[i] - 'A' + 'a';
            else if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) a += s[i];
        int k = -1;
        for (int i = 0; i < search.size(); i++)
            if (search[i].key == a) {
                k = i;
                search[i].num++; break;
            }
        if (k == -1)
        {
            Elm x;
            x.key = a;
            x.num = 1;
            search.push_back(x);
        }
    }
    int finish = 0;
    while (!finish)
    {
        int num[300] = { 0 };
        finish = 1;
        while (scanf("%s", s))
        {
            if (strcmp(s, "----------") == 0) break;
            finish = 0;
            string a = "";
            int L = strlen(s);
            for (int i = 0; i < L; i++)
                if ('A' <= s[i] && s[i] <= 'Z') a += s[i] - 'A' + 'a';
                else if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) a += s[i];
            int k = -1;
            for (int i = 0; i < search.size(); i++)
                if (search[i].key == a) {
                    k = i;
                    num[i] ++; break;
                }
        }
        if (!finish)
        {
            double res = 0;
            for (int i = 0; i < search.size(); i++)
                res += sqrt((double)num[i] * search[i].num);
            printf("%.2lf\n", res);
        }
    }
    return 0;
}