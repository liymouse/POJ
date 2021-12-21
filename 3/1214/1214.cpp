#include <stdio.h>
#include <string.h>

typedef struct {
    char card[52][3];
    int num;
}Stack;
Stack a[52];
int n;

int can(int i, int j)
{
    if (a[i].card[a[i].num - 1][0] == a[j].card[a[j].num - 1][0] ||
        a[i].card[a[i].num - 1][1] == a[j].card[a[j].num - 1][1]) return 1;
    return 0;
}
//move i to j
void move(int i, int j)
{
    memcpy(a[j].card[a[j].num], a[i].card[a[i].num - 1], 2);
    a[i].num--;
    a[j].num++;
    if (a[i].num == 0)
    {
        for (int k = i; k < n - 1; k++)
            a[k] = a[k + 1];
        n--;
    }
}
int main()
{
    while (scanf("%s", a[0].card[0]) == 1)
    {
        if (a[0].card[0][0] == '#') break;
        a[0].num = 1;
        n = 52;
        for (int i = 1; i < n; i++)
        {
            scanf("%s", a[i].card[0]);
            a[i].num = 1;
        }
        while (1)
        {
            int finish = 1;
            for (int i = 1; i < n; i++)
            {
                if (i > 2 && can(i, i - 3)) {
                    move(i, i - 3); finish = 0; break;
                }
                if (i > 0 && can(i, i - 1)) {
                    move(i, i - 1); finish = 0; break;
                }
            }
            if (finish == 1 || n == 1) break;
        }
        printf("%d piles remaining:", n);
        for (int i = 0; i < n; i++) printf(" %d", a[i].num);
        printf("\n");
    }
    return 0;
}