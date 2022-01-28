#include <stdio.h>

int a , b;

int gcd(int a , int b)
{
int t;

    if (a == 0) return b;
    if (b == 0) return a;
    if (a < b) {t = a; a = b; b = t;}
    while (1)
    {
        if (a % b == 0) return b;
        t = b; b = a % b; a = t;
    }
}

int lcm(int a , int b)
{
    if (gcd(a , b) == 0) return 0;
    else return a * b / gcd(a , b);
}

int main()
{
    scanf("%d %d" , &a , &b);
    printf("Gcd(%d , %d) = %d\n" , a , b , gcd(a , b));
    printf("Lcm(%d , %d) = %d\n" , a , b , lcm(a , b));
    getchar(); getchar();
    return 0;
}
