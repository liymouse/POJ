#include <stdio.h>

int main()
{
int n;

    while (scanf("%d" , &n) == 1)
    {
        if (n == 0) return 0;
        if (n < 3) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
