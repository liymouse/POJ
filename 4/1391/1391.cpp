#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))

map<string, int> names;
vector<int> paper[32005];
int lv[10005];
char check[32005] = { 0 };

int main()
{
    //freopen("erdos.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int p, n, ca = 1;
    while (scanf("%d %d", &p, &n) == 2)
    {
        if (p == 0 && n == 0) break;
        names.clear();
        memset(lv, 0xff, sizeof(lv));
        memset(check, 0, sizeof(check));
        char s[255];
        gets_s(s);
        int index = 0;
        for (int i = 0; i < p; i++)
        {
            paper[i].clear();
            gets_s(s);
            int num = 0;
            string na = "";
            int L = strlen(s);
            for (int j = 0; j < L; j ++)
                if (s[j] == ',' || s[j] == ':')
                {
                    num++;
                    if (num == 2)
                    {
                        int id;
                        if (names.find(na) != names.end()) id = names[na];
                        else
                        {
                            id = index;
                            names[na] = index;
                            index++;
                            if (na == "Erdos, P.") lv[id] = 0;
                            else lv[id] = 1 << 30;
                        }
                        paper[i].push_back(id);
                        if (s[j] == ':') break; else j++;
                        na = ""; num = 0;
                    }
                    else na += s[j];
                }
                else na += s[j];
        }
        for (int k = 0; k < index; k ++)
        {
            int update = 0;
            for (int i = 0; i < p; i ++)
                if (check[i] == 0)
                {
                    int ok = 0;
                    for (int j = 0; j < paper[i].size(); j++)
                        if (lv[paper[i][j]] == k) {
                            ok = 1; break;
                        }
                    if (ok)
                    {
                        for (int j = 0; j < paper[i].size(); j++)
                            lv[paper[i][j]] = min(lv[paper[i][j]], k + 1);
                        update = 1;
                        check[i] = 1;
                    }
                }
            if (update == 0) break;
        }
        printf("Database #%d\n", ca++);
        for (int i = 0; i < n; i++)
        {
            gets_s(s);
            if (names.find(string(s)) != names.end())
            {
                int id = names[string(s)];
                if (lv[id] != (1 << 30)) printf("%s: %d\n", s, lv[id]);
                else printf("%s: infinity\n", s);
            }
            else printf("%s: infinity\n", s);
        }
        printf("\n");
    }
    return 0;
}
