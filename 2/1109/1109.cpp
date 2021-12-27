#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef struct
{
    char name[100];
    char low[100];
    vector<int> page;
}Elm;
typedef struct
{
    Elm prime;
    vector<Elm> secondary;
}Index;

int cmpIndex(Index &x, Index &y)
{
    return strcmp(x.prime.low, y.prime.low) < 0;
}
int cmpElm(Elm &x, Elm &y)
{
    return strcmp(x.low, y.low) < 0;
}
void initElm(Elm &x)
{
    memset(x.low, 0, sizeof(x.low));
    memset(x.name, 0, sizeof(x.name));
    x.page.clear();

}
void initIndex(Index &x)
{
    initElm(x.prime);
    x.secondary.clear();
}
void setName(Elm &x, char *p)
{
    strcpy(x.name, p);
    int Lp = strlen(p);
    for (int i = 0; i < Lp; i++)
        if ('A' <= p[i] && p[i] <= 'Z') x.low[i] = p[i] - 'A' + 'a';
        else x.low[i] = p[i];
    x.low[Lp] = 0;
}
int main()
{
    char s[200];
    int ca = 1;
    int page = 1;
    vector<Index> a;
    char prime[200];
    int pi;
    char second[200];
    int si;
    int st = 0;
    while (gets_s(s))
    {
        if (strcmp(s, "**") == 0) break;
        else if (strcmp(s, "*") == 0)
        {
            //output;
            printf("DOCUMENT %d\n", ca++);
            sort(a.begin(), a.end(), cmpIndex);
            for (int i = 0; i < a.size(); i++)
            {
                printf("%s", a[i].prime.name);
                if (a[i].prime.page.size() > 0)
                {
                    sort(a[i].prime.page.begin(), a[i].prime.page.end());
                    printf(", %d", a[i].prime.page[0]);
                    for (int j = 1; j < a[i].prime.page.size(); j++)
                        if (a[i].prime.page[j] > a[i].prime.page[j - 1]) printf(", %d", a[i].prime.page[j]);
                }
                printf("\n");
                sort(a[i].secondary.begin(), a[i].secondary.end(), cmpElm);
                for (int j = 0; j < a[i].secondary.size(); j++)
                {
                    printf("+ %s", a[i].secondary[j].name);
                    if (a[i].secondary[j].page.size() > 0)
                    {
                        sort(a[i].secondary[j].page.begin(), a[i].secondary[j].page.end());
                        printf(", %d", a[i].secondary[j].page[0]);
                        for (int k = 1; k < a[i].secondary[j].page.size(); k++)
                            if (a[i].secondary[j].page[k] > a[i].secondary[j].page[k - 1]) printf(", %d", a[i].secondary[j].page[k]);
                    }
                    printf("\n");
                }
            }
            //clear
            a.clear();
            page = 1; st = 0;
        }
        else
        {
            int L = strlen(s);
            s[L] = ' '; s[L + 1] = 0; L++;
            for (int i = 0; i < L; i++)
                if (s[i] == '&') page++;
                else if (s[i] == '{')
                {
                    memset(prime, 0, sizeof(prime));
                    memset(second, 0, sizeof(second));
                    st = 1; pi = si = 0;
                }
                else if (s[i] == '}')
                {
                    char p[200] = { 0 };
                    int x = 0, y = pi - 1;
                    while (x <= y && prime[x] == ' ') x++;
                    while (x <= y && prime[y] == ' ') y--;
                    prime[y + 1] = 0;
                    strcpy(p, prime + x);

                    char sc[200] = { 0 };
                    if (si > 0)
                    {
                        int x = 0, y = si - 1;
                        while (x <= y && second[x] == ' ') x++;
                        while (x <= y && second[y] == ' ') y--;
                        second[y + 1] = 0;
                        strcpy(sc, second + x);
                    }

                    int k = -1;
                    for (int j = 0; j < a.size(); j ++)
                        if (strcmp(a[j].prime.name, p) == 0)
                        {
                            k = j; break;
                        }
                    if (k == -1)
                    {
                        Index x;
                        setName(x.prime, p);
                        if (sc[0] == 0) x.prime.page.push_back(page);
                        else
                        {
                            Elm y;
                            setName(y, sc);
                            y.page.push_back(page);
                            x.secondary.push_back(y);
                        }
                        a.push_back(x);
                    }
                    else
                    {
                        if (sc[0] == 0) a[k].prime.page.push_back(page);
                        else
                        {
                            int t = -1;
                            for (int j = 0; j < a[k].secondary.size(); j ++)
                                if (strcmp(a[k].secondary[j].name, sc) == 0) { t = j; break; }
                            if (t == -1)
                            {
                                Elm y;
                                setName(y, sc);
                                y.page.push_back(page);
                                a[k].secondary.push_back(y);
                            }
                            else
                            {
                                a[k].secondary[t].page.push_back(page);
                            }
                        }
                    }
                    st = 0;
                }
                else
                {
                    if (st == 1)
                    {
                        if (s[i] == '\%')
                        {
                            memset(prime, 0, sizeof(prime));
                            pi = 0;
                        }
                        else if (s[i] == '$')
                        {
                            st = 2;
                        }
                        else
                        {
                            prime[pi++] = s[i];
                        }
                    }
                    else if (st == 2)
                    {
                        second[si++] = s[i];
                    }
                }
        }
    }
    return 0;
}