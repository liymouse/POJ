#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

//0 = not processed, 1 = 1st win, -1 = 2nd win
int win[1 << 19] = { 0 };
vector<int> choose[1 << 19];

int check(int state)
{
    if (win[state] != 0) return win[state];
    if (state == 0) { win[state] = -1; return win[state]; }
    int canwin = 0;
    for (int i = 2; i <= 20; i ++)
        if (state & (1<<(i-2)))
        {
            int b = state;
            b &= ~(1 << (i - 2));
            for (int k = i + i; k <= 20; k += i) b &= ~(1 << (k-2));
            for (int k = 2; k <= 20 - i; k++)
                if ((b & (1<<(k-2))) == 0) b &= ~(1 << (k+i-2));
            if (check(b) == -1){
                canwin = 1; choose[state].push_back(i);
            }
        }
    if (canwin) win[state] = 1;
    else win[state] = -1;
    return win[state];
}
int main()
{
    //for (int i = 0; i < (1 << 19); i++)
    //    if (win[i] == 0) check(i, 1);
    int ca = 1;
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0) break;
        int state = 0;
        int a[21] = { 0 };
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            a[x] = 1;
            state |= 1 << (x - 2);
        }
        int res = check(state);
        printf("Test Case #%d\n", ca++);
        if (res == -1) printf("There's no winning move.\n");
        else
        {
            printf("The winning moves are:");
            for (int i = 0; i < choose[state].size(); i ++)
                printf(" %d", choose[state][i]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}