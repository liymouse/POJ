#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct _Node Node;
struct _Node
{
    int v;
    Node *left, *right;
    _Node()
    {
        left = right = 0;
        v = 0;
    }
};

char str[10000];
int k, L, getit;

void dfs(Node *cur, int sum)
{
    if (cur == NULL || getit == 1) return;
    sum += cur->v;
    if (cur->left == NULL && cur->right == NULL && sum == k) { getit = 1; return; }
    if (cur->left) dfs(cur->left, sum);
    if (cur->right) dfs(cur->right, sum);

}
void cleanTree(Node **cur)
{
    if ((*cur) == NULL) return;
    if ((*cur)->left) cleanTree(&(*cur)->left);
    if ((*cur)->right) cleanTree(&(*cur)->right);
    delete *cur;
}
void maketree(Node **cur, int a, int b)
{
    //skip ()
    a++; b--;
    //if empty tree return
    if (a > b) return;
    *cur = new Node();
    //get root
    (*cur)->v = 0;
    int f = 1;
    if (str[a] == '-') { f = -1; a++; }
    else if (str[a] == '+') { f = 1; a++; }
    while ('0' <= str[a] && str[a] <= '9') {
        (*cur)->v = (*cur)->v * 10 + str[a] - '0'; a++;
    }
    (*cur)->v *= f;
    int c = a;
    int kuo = 0;
    while (c < b)
    {
        if (str[c] == '(') kuo++;
        else if (str[c] == ')') {
            kuo--; if (kuo == 0) break;
        }
        c++;
    }
    maketree(&(*cur)->left, a, c);
    maketree(&(*cur)->right, c + 1, b);
}

int main()
{
    while (scanf("%d", &k) == 1)
    {
        int kuo = 0;
        char s[1000];
        L = 0;
        int end = 0;
        while (scanf("%s", s) == 1)
        {
            int n = strlen(s);
            for (int i = 0; i < n; i++)
                if (('0' <= s[i] && s[i] <= '9') || s[i] == '-' || s[i] == '+') str[L++] = s[i];
                else if (s[i] == '(') { str[L++] = s[i]; kuo++; }
                else if (s[i] == ')')
                { 
                    str[L++] = s[i]; kuo--; 
                    if (kuo == 0) end = 1;
                }
            if (end) break;
        }
        Node *tree = NULL;
        maketree(&tree, 0, L - 1);
        getit = 0;
        dfs(tree, 0);
        if (getit) printf("yes\n"); else printf("no\n");
        cleanTree(&tree);
    }
    return 0;
}
