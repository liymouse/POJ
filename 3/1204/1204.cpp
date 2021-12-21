#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct Node{
    int id;
    Node *next[26];
};

char a[1005][1005];
int res_row[1005], res_col[1005];
char res_dir[1005];
Node* tree = new Node();
int sx, sy, sd;
int row, col, n;
int num;
int dir[8][2] = { { -1, 0 },{ -1, 1 },{ 0, 1 },{ 1, 1 },{ 1, 0 },{ 1, -1 },{ 0, -1 },{ -1, -1 } };

void insert(char *word, int L, int id)
{
    Node *p = tree;

    for (int i = 0; i < L; i++)
    {
        int k = word[i] - 'A';
        if (p->next[k] == NULL)
        {
            p->next[k] = new Node();
        }
        p = p->next[k];
    }
    p->id = id;
}

void dfs(Node *p, int x, int y)
{
    if (p->id > 0 && res_row[p->id] == -1)
    {
        res_row[p->id] = sx;
        res_col[p->id] = sy;
        res_dir[p->id] = 'A' + sd;
        num++;
        if (num >= n) return;
    }
    if (x < 0 || x >= row || y < 0 || y >= col) return;
    int id = a[x][y] - 'A';
    if (p->next[id])
    {
        dfs(p->next[id], x + dir[sd][0], y + dir[sd][1]);
    }
}

void clean(Node *p)
{
    for (int i = 0; i < 26; i++)
        if (p->next[i]) clean(p->next[i]);
    delete p;
}
int main()
{
    //freopen("1204.in", "r", stdin);
    //freopen("1204.out", "w", stdout);
    scanf("%d %d %d", &row, &col, &n);
    for (int i = 0; i < row; i++)
        scanf("%s", a[i]);
    int minL = 10000;
    for (int i = 1; i <= n; i++)
    {
        char word[1005];
        scanf("%s", word);
        int L = strlen(word);
        minL = min(minL, L);
        res_row[i] = res_col[i] = -1;
        insert(word, L, i);
    }
    num = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int d = 0; d < 8; d++)
            {
                int endi = i + dir[d][0] * (minL - 1);
                int endj = j + dir[d][1] * (minL - 1);
                if (0 <= endi && endi < row && 0 <= endj && endj < col)
                {
                    sx = i; sy = j;
                    sd = d;
                    dfs(tree, sx, sy);
                    if (num == n) break;
                }
            }
            if (num == n) break;
        }
        if (num == n) break;
    }
    for (int i = 1; i <= n; i++)
        printf("%d %d %c\n", res_row[i], res_col[i], res_dir[i]);

    clean(tree);
    return 0;
}
