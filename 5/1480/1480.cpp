#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int input[10];
int res[10];

char str[6][5] = { "", "ADD", "DIV", "DUP", "MUL", "SUB" };
int op[10];
int found = 0, L, n;

int check()
{
    for (int i = 0; i < n; i++)
    {
        int st[20] = { input[i] }, top = 0;
        for (int i = 0; i < L; i ++)
            if (op[i] == 1) // ADD
            {
                st[top - 1] += st[top];
                if (abs(st[top - 1]) > 30000) return 0;
                top--;
            }
            else if (op[i] == 2) //DIV
            {
                if (st[top] == 0) return 0;
                st[top - 1] /= st[top];
                if (abs(st[top - 1]) > 30000) return 0;
                top--;
            }
            else if (op[i] == 3) //DUP
            {
                st[top + 1] = st[top];
                top++;
            }
            else if (op[i] == 4) //MUL
            {
                st[top - 1] *= st[top];
                if (abs(st[top - 1]) > 30000) return 0;
                top--;
            }
            else //SUB
            {
                st[top - 1] -= st[top];
                if (abs(st[top - 1]) > 30000) return 0;
                top--;
            }
        if (st[top] != res[i]) return 0;
    }
    return 1;
}
void find(int x, int dup_num)
{
    if (x == L)
    {
        if (check()) found = 1;
        return;
    }
    if (dup_num < x / 2 + 1) //must DUP
    {
        op[x] = 3;
        find(x + 1, dup_num + 1);
        if (found) return;
    }
    else
    {
        for (int i = 1; i <= 5; i++)
        {
            if (i == 3 && dup_num >= L / 2) continue;
            op[x] = i;
            find(x + 1, dup_num + (i==3));
            if (found) return;
        }
    }
}
int main()
{
    int ca = 1;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        for (int i = 0; i < n; i++) scanf("%d", &input[i]);
        for (int i = 0; i < n; i++) scanf("%d", &res[i]);
        found = 0;
        for (int i = 0; i <= 10; i+=2)
        {
            L = i;
            find(0, 0);
            if (found) break;
        }
        printf("Program %d\n", ca++);
        if (found)
        {
            if (L == 0) printf("Empty sequence\n");
            else
            {
                printf("%s", str[op[0]]);
                for (int i = 1; i < L; i++)
                    printf(" %s", str[op[i]]);
                printf("\n");
            }
        }
        else printf("Impossible\n");
        printf("\n");
    }
    return 0;
}
