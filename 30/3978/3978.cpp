#include <stdio.h>

int main()
{
    int check[10001] = {1 , 1};
    for (int i = 2; i * i <= 10000; i ++)
        for (int j = i + i; j <= 10000; j += i) check[j] = 1;
    int a , b;
    while (scanf("%d %d" , &a , &b) == 2)
    {
        if (a == -1 && b == -1) break;
        int res = 0;
        for (int i = a; i <= b; i ++) if (i >= 0 && check[i] == 0) res ++;
        printf("%d\n" , res);
    }
    return 0;
}
