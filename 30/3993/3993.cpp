#include <stdio.h>
#include <math.h>

int main()
{
    int prime[170] , num = 0;
    int check[1001] = {0};
    for (int i = 2; i * i <= 1000; i ++)
        if (check[i] == 0)
            for (int j = i + i; j <= 1000; j += i) check[j] = 1;
    for (int i = 2; i <= 1000; i ++)
        if (check[i] == 0) prime[num ++] = i;
    int a , b , ca = 1;
    while (scanf("%d %d" , &a , &b) == 2)
    {
        if (a == 0 && b == 0) break;
        int expa[170] = {0} , expb[170] = {0};
        for (int i = 0; i < num; i ++)
        {
            while (a % prime[i] == 0) {expa[i] ++; a /= prime[i];}
            while (b % prime[i] == 0) {expb[i] ++; b /= prime[i];}
        }
        expa[num] = a;
        expb[num] = b;
        int mind = 0 , dist = 0;
        for (int i = 0; i < num; i ++)
            if (expa[i] > 0 || expb[i] > 0)
            {
                mind ++;
                dist += abs(expa[i] - expb[i]);
            }
        if (expa[num] != 1 && expb[num] != 1)
        {
            mind ++;
            if (expa[num] != expb[num]) {mind ++; dist += 2;}
        }
        else if (expa[num] != 1 || expb[num] != 1)
        {
            mind ++;
            dist ++;
        }
        printf("%d. %d:%d\n" , ca++ , mind , dist);
    }
    return 0;
}