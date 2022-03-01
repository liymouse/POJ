#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int left, right;
    int num;
    char f;
}Node;
Node *tree;
int ans, n;
int p[10];
char s[1000];
int L;
int ed[300];
char d[5] = "+-*/";
int cal_stack[100];
int st;

void buildTree(int i, int x, int y)
{
    while (x <= y && s[x] == '(' && ed[x] == y) { x++; y--; }
    if (x > y) return;
    //leaf
    if ('0' <= s[x] && s[x] <= '9' && ed[x] == y)
    {
        tree[i].left = tree[i].right = -1;
        tree[i].f = 0;
        tree[i].num = 0;
        for (int j = x; j <= y; j++) tree[i].num = tree[i].num * 10 + s[j] - '0';
        return;
    }
    //find lowest priority, use it as root
    int j = x;
    int k = -1;
    int lv = 10;
    while (j <= y)
    {
        if (s[j] == '+' || s[j] == '-')
        {
            k = j; lv = 0;
        }
        else if (s[j] == '*' || s[j] == '/')
        {
            if (lv >= 1)
            {
                k = j; lv = 1;
            }
        }
        j = ed[j] + 1;
    }
    if (k == -1) return;
    tree[i].num = -1;
    tree[i].f = s[k];
    tree[i].left = n++;
    tree[i].right = n++;
    buildTree(tree[i].left, x, k - 1);
    buildTree(tree[i].right, k + 1, y);
}
void rearVisit(int i)
{
    //leaf
    if (tree[i].left == -1) cal_stack[++st] = tree[i].num;
    else
    {
        rearVisit(tree[i].left);
        rearVisit(tree[i].right);
        int y = cal_stack[st--];
        int x = cal_stack[st--];
        if (tree[i].f == '+') cal_stack[++st] = x + y;
        else if (tree[i].f == '-') cal_stack[++st] = x - y;
        else if (tree[i].f == '*') cal_stack[++st] = x * y;
        else if (y != 0) cal_stack[++st] = x / y;
        else cal_stack[++st] = 1 << 20;
    }
}
int cal()
{
    n = 1;
    memset(tree, 0, n * sizeof(Node));
    buildTree(0, 0, L - 1);
    st = -1;
    rearVisit(0);
    return cal_stack[0];
}
int dfs(int x)
{
    if (x == -1)
    {
        if (cal() == ans) return 1;
        return 0;
    }
    for (int i = 0; i < 4; i++)
    {
        s[p[x]] = d[i];
        if (dfs(x - 1)) return 1;
    }
    return 0;
}

int main()
{
    int t;
    //freopen("1460.in", "r", stdin);
    scanf("%d", &t);
    for (int ca = 0; ca < t; ca++)
    {
        scanf("%s %d", s, &ans);
        n = 0;
        int mark_num = 0;
        int stack[500];
        int top = -1, number = 0;
        L = strlen(s);
        for (int i = 0; i < L; i++)
        {
            if (s[i] == '(') { top++; stack[top] = i; }
            else if (number == 0 && '0' <= s[i] && s[i] <= '9')
            {
                top++; stack[top] = i;
                number = 1;
            }
            else if (s[i] == ')')
            {
                if (number)
                {
                    ed[stack[top]] = i - 1; top--; //pop number
                    number = 0;
                    n++;
                }
                ed[stack[top]] = i; //pop ()
                top--;
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '?')//+-*/?
            {
                ed[i] = i;
                if (s[i] == '?') p[mark_num++] = i;
                if (number)
                {
                    ed[stack[top]] = i - 1; top--;
                    number = 0;
                    n++;
                }
                n++;
            }
        }
        if (top >= 0) { ed[stack[top]] = L - 1; top--; n++; }
        tree = (Node*)malloc(n * sizeof(Node));
        if (dfs(mark_num-1)) printf("yes\n");
        else printf("no\n");
        free(tree);
    }
    return 0;
}
