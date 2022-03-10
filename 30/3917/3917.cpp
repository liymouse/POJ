#include <stdio.h>
#include <string.h>

int main()
{
    char p1[100] , p2[100];
    while (scanf("%s" , p1) == 1)
    {
        int a = 0, b = 0;
        scanf("%s" , p2);
        if (p1[0] == 'E' && p2[0] == 'E') break;
        for (int i = 0; i < strlen(p1); i ++)
        {
            if (p1[i] == p2[i]) continue;
            if ((p1[i] == 'R' && p2[i] == 'S') || (p1[i] == 'S' && p2[i] == 'P') || (p1[i] == 'P' && p2[i] == 'R')) a ++;
            else b ++;
        }
        printf("P1: %d\nP2: %d\n" , a , b);
    }
    return 0;
}
