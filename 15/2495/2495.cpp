#include <stdio.h>

int main()
{
int x1 , y1 , x2 , y2;
int t , h , s;

    scanf("%d" , &t);
    for (h = 0; h < t; h ++)
    {
        scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2);
        printf("Scenario #%d:\n" , h + 1);
        s = x1 + x2 + y1 + y2;
        if (s % 2 == 0) printf("0\n"); else printf("1\n");
        printf("\n");
    }
    return 0;
}
