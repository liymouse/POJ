#include <stdio.h>

int main()
{
    int ca;
    scanf("%d" , &ca);
    while (ca --)
    {
        int y , m , d;
        scanf("%d %d %d" , &y , &m , &d);
        if ((m & 1) == (d & 1)) printf("YES\n");
        else
        {
            if ((m == 9 && d == 30) || (m == 11 && d == 30)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}