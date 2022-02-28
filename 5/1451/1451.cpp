#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef struct
{
    string s;
    int p;
}Word;

typedef struct Node
{
    struct Node *p[10];
    vector<Word> a;
    char is_sort;
};

char change[27] = "22233344455566677778889999";

int cmp(Word &x, Word &y)
{
    if (x.p == y.p) return x.s < y.s;
    return x.p > y.p;
}

void add(Node *tree, char *s, int x, int p)
{
    if (s[x] == 0) return;
    int id = change[s[x] - 'a'] - '0';
    Word a;
    a.s = string(s, s + x + 1);
    a.p = p;
    if (tree->p[id] == NULL)
    {
        tree->p[id] = new(Node);
        tree->p[id]->is_sort = 0;
        memset(tree->p[id]->p, 0, sizeof(tree->p[id]->p));
        tree->p[id]->a.push_back(a);
    }
    else
    {
        int find = 0;
        for (int i = 0; i < tree->p[id]->a.size(); i++)
        {
            if (tree->p[id]->a[i].s == a.s) {
                tree->p[id]->a[i].p += a.p; find = 1; break;
            }
        }
        if (!find) tree->p[id]->a.push_back(a);
    }
    add(tree->p[id], s, x + 1, p);
}

int main()
{
    //freopen("1451.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int ca = 1; ca <= cas; ca++)
    {
        int w , p;
        char s[105];
        scanf("%d", &w);
        Node tree = { 0 };
        for (int i = 0; i < w; i++)
        {
            scanf("%s %d", s, &p);
            add(&tree, s, 0, p);
        }
        int m;
        scanf("%d", &m);
        printf("Scenario #%d:\n", ca);
        for (int t = 0; t < m; t++)
        {
            char s[103];
            scanf("%s", s);
            Node *p = &tree;
            for (int i = 0; s[i] != '1'; i++)
            {
                int id = s[i] - '0';
                int find = 0;
                if (p != NULL) p = p->p[id];
                if (p == NULL) printf("MANUALLY\n");
                else
                {
                    if (!p->is_sort)
                    {
                        sort(p->a.begin(), p->a.end(), cmp);
                        p->is_sort = 1;
                    }
                    printf("%s\n", p->a[0].s.c_str());
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
