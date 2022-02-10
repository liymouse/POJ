#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
typedef unsigned char uint8;

typedef struct
{
    uint8 sx, sy;
    int left, right;
}Node;

char s[255];
uint8 e[255];
Node *tree;
int n;

int getLv(char c) {
    if (c == '+' || c == '-') return 0;
    else if (c == '*' || c == '/') return 1;
    return 2;
}
string midVisit(int i)
{
    string res = "";
    if (tree[i].left == -1)
    {
        for (int j = tree[i].sx; j <= tree[i].sy; j++) res += s[j];
    }
    else
    {
        int cur_lv = getLv(s[tree[i].sx]);
        int left_lv = getLv(s[tree[tree[i].left].sx]);
        int right_lv = getLv(s[tree[tree[i].right].sx]);
        if (left_lv < cur_lv) res += "(" + midVisit(tree[i].left) + ")";
        else res += midVisit(tree[i].left);
        res += s[tree[i].sx];
        if (right_lv < cur_lv || (right_lv == cur_lv && (s[tree[i].sx] == '/' || s[tree[i].sx] == '-')))
            res += "(" + midVisit(tree[i].right) + ")";
        else res += midVisit(tree[i].right);
    }
    return res;
}

void buildTree(int i, int x, int y)
{
    while (x <= y && s[x] == '(' && e[x] == y) { x++; y--; }
    if (x > y) return;
    //leaf
    if ('a' <= s[x] && s[x] <= 'z' && e[x] == y)
    {
        tree[i].left = tree[i].right = -1;
        tree[i].sx = x; tree[i].sy = y;
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
        j = e[j] + 1;
    }
    if (k == -1) return;
    tree[i].sx = tree[i].sy = k;
    tree[i].left = n++;
    tree[i].right = n++;
    buildTree(tree[i].left, x, k - 1);
    buildTree(tree[i].right, k + 1, y);
}

int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--)
    {
        scanf("%s", s);
        int L = strlen(s);
        uint8 stack[255];
        int top = -1, number = 0;
        n = 0;
        for (int i = 0; i < L; i++)
        {
            if (s[i] == '(') { top++; stack[top] = i; }
            else if (number == 0 && 'a' <= s[i] && s[i] <= 'z')
            {
                top++; stack[top] = i;
                number = 1;
            }
            else if (s[i] == ')')
            {
                if (number)
                {
                    e[stack[top]] = i - 1;
                    top--;
                    number = 0;
                    n++;
                }
                e[stack[top]] = i;
                top--;
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                e[i] = i;
                if (number)
                {
                    e[stack[top]] = i - 1;
                    top--;
                    number = 0;
                    n++;
                }
                n++;
            }
        }
        if (top >= 0) { e[stack[top]] = L - 1; top--; n++; }
        tree = (Node*)malloc(n * sizeof(Node));
        memset(tree, 0, n * sizeof(Node));
        n = 1;
        buildTree(0, 0, L - 1);
        string res = midVisit(0);
        printf("%s\n", res.c_str());
        free(tree);
    }

    return 0;
}
