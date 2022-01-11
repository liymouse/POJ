#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int tree[10000];
int have[10000];
char str[10000];
int k, L, getit;

void dfs(int cur, int sum)
{
    if (have[cur] == 0 || getit == 1) return;
    sum += tree[cur];
    if (have[cur * 2 + 1] == 0 && have[cur * 2 + 1] == 0)
    {
        if (sum == k) { getit = 1; return; }
    }
    if (have[cur * 2 + 1]) dfs(cur * 2 + 1, sum);
    if (have[cur * 2 + 1]) dfs(cur * 2 + 2, sum);

}
void maketree(int cur, int a, int b)
{
    //skip ()
    a++; b--;
    //if empty tree return
    if (a > b) return;
    //get root
    have[cur] = 1;
    tree[cur] = 0;
    int f = 1;
    if (str[a] == '-') { f = -1; a++; }
    else if (str[a] == '+') { f = 1; a++; }
    while ('0' <= str[a] && str[a] <= '9') {
        tree[cur] = tree[cur] * 10 + str[a] - '0'; a++;
    }
    tree[cur] *= f;
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
    maketree(cur * 2 + 1, a, c);
    maketree(cur * 2 + 2, c + 1, b);
}

int main()
{
    while (scanf("%d", &k) == 1)
    {
        int kuo = 0;
        char s[1000];
        L = 0;
        int end = 0;
        memset(have, 0, sizeof(have));
        memset(tree, 0, sizeof(tree));
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
        maketree(0, 0, L - 1);
        getit = 0;
        dfs(0, 0);
        if (getit) printf("yes\n"); else printf("no\n");
    }
    return 0;
}